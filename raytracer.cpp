#include "raytracer.h"
#include <algorithm>

point_3d canvas_to_viewport(point_2d p, int canvas_width, int canvas_height) {

    double coeff_x = viewport_width / canvas_width ;
    double coeff_y = viewport_height / canvas_height ;

    return point_3d {p.x * coeff_x, p.y * coeff_y, viewport_d};
}


// 0 - Nothing
// 1 - Sphere
// 2 - Triangle
Figure *get_closest_intersection(point_3d viewer, point_3d viewport, physical_items *item,
                              double &x_min, int &result, double t_min = 1, double t_max = INT_MAX,
                             bool find_tranparent = true) {
    Figure *closest = NULL;
    x_min = INT_MAX;
    result = 0;
    for (auto i = 0; i < item->t_vec.size(); i++) {
        bool transparent = find_tranparent || !item->t_vec[i]->transparent;
        std::vector<double> points = item->t_vec[i]->get_intersect_points(viewer, viewport);
        if (points.size() == 1) {
            if (points[0] < x_min && points[0] > t_min && points[0] < t_max && transparent) {
                x_min = points[0];
                closest = item->t_vec[i];
                result = 1;
            }
        }
        else if (points.size() == 2) {
            bool transparent = find_tranparent || !item->t_vec[i]->transparent;
                if (points[0] < x_min && points[0] > t_min && points[0] < t_max && transparent) {
                    x_min = points[0];
                    closest = item->t_vec[i];
                    result = 1;
                }
                if (points[1] < x_min && points[1] > t_min && points[1] < t_max && transparent) {
                    x_min = points[1];
                    closest = item->t_vec[i];
                    result = 1;
                }
        }
    }

    for (auto i = 0; i < item->tr_vec.size(); i++) {
        auto t = item->tr_vec[i];
        bool transparent = find_tranparent || !t->transparent;
        std::vector<double> points = t->get_intersect_points(viewer, viewport);
        if (points.size() == 1) {
            if (points[0] < x_min && points[0] > t_min && points[0] < t_max && transparent) {
                x_min = points[0];
                closest = item->tr_vec[i];
                result = 2;
            }
        }
    }
    return closest;
}

point_3d reflect_ray(point_3d R, point_3d N) {
    return N*2*N.dot_product(R) - R;
}

point_3d refract_ray(point_3d I, point_3d N, double eta_t, double eta_i = 1) {
    double cosi = - std::max(-1.0, std::min(1.0, I.dot_product(N)));
    if (cosi < 0) {
        return refract_ray(I, N * -1, eta_i, eta_t);
    }
    double eta = eta_i/eta_t;
    double k = 1 - eta*eta*(1-cosi * cosi);
    return k < 0 ? point_3d(1, 0, 0) : I*eta + N*(eta * cosi - sqrt(k));
}

//point_3d refract_ray(point_3d I, point_3d N, double ior)
//{
//    double cosi = I.dot_product(N);
//    if (cosi > 1)
//        cosi = 1;
//    else if (cosi < -1)
//        cosi = -1;
//    //float cosi = std::clamp(-1, 1, I.dot_product(N));
//    double etai = 1, etat = ior;
//    point_3d n = N;
//    if (cosi < 0) { cosi = -cosi; } else { std::swap(etai, etat); n= N * -1; }
//    double eta = etai / etat;
//    double k = 1 - eta * eta * (1 - cosi * cosi);
//    return k < 0 ? point_3d(1, 0, 0) : I * eta + n * (eta * cosi - sqrtf(k));
//}

double get_lighting(point_3d P, point_3d N, scene_objects *objects, int specular, point_3d viewport) {
    double intensity = ambient_light;
    light_src light = objects->lamp;

    point_3d L = light.pos - P;

    double x_min = INT_MAX;
    int r;
    Figure *closest = get_closest_intersection(P, L, objects->item, x_min, r, EPS, 1, false);;
    //если в тени или стеклянный
    if (r != 0)
        return intensity;

    // Диффузное отражение
    double N_prod_L = N.dot_product(L);
    if (N_prod_L > EPS)
        intensity += light.intensity*N_prod_L/(N.length()*L.length());

    //Зеркальное отражение
    if (specular != -1) {
        point_3d R = reflect_ray(L, N);
        point_3d V = viewport;
        double R_prod_V = R.dot_product(V);
        if (R_prod_V > EPS)
            intensity += light.intensity*pow(R_prod_V/(R.length() * V.length()), specular);
    }

    return intensity;
}

color trace(point_3d orig, point_3d dest, scene_objects *objects, int depth, double t_min, double t_max) {
    color background_color = {255, 255, 255};
    double x_min;
    int r;
    Figure *closest = get_closest_intersection(orig, dest, objects->item, x_min, r, t_min, t_max);;

    if (r == 0)
        return background_color;

    color result;
    point_3d P = orig + dest * x_min;
    point_3d N;
    N = closest->get_normal(P);
    N = N / N.length();

    double intensity = get_lighting(P, N, objects, closest->specular, dest * -1);
    result = closest->color * intensity;
    if (depth <= 0 || (closest->reflective <= EPS && closest->refractive <= EPS) )
        return result;
    if (closest->refractive <= EPS)  { //ONLY REFLECTIVE
        point_3d R = reflect_ray(dest * -1, N);
        color reflected_color = trace(P, R, objects, depth-1, EPS, INT_MAX);
        result = result * (1 - closest->reflective) + reflected_color * closest->reflective;
    }
    else if (closest->reflective <= EPS) { //ONLY REFRACTIVE
        point_3d Ref;
        if (r == 1)
            Ref = refract_ray(dest / dest.length(), N / N.length(), closest->refractive_index);
        else
            Ref = refract_ray(dest / dest.length(), N / N.length() * -1, closest->refractive_index);
        color refracted_color = trace(P, Ref, objects, depth-1, EPS, INT_MAX);
        result =  result * (1 - closest->refractive) + refracted_color * closest->refractive;
    }
    else { //REFLECTIVE AND REFRACTIVE
        point_3d R = reflect_ray(dest * -1, N);
        point_3d Ref;
        color reflected_color = trace(P, R, objects, depth-1, EPS, INT_MAX);
        if (r == 1)
            Ref = refract_ray(dest / dest.length(), N / N.length(), closest->refractive_index);
        else
            Ref = refract_ray(dest / dest.length(), N / N.length() * -1, closest->refractive_index);
        color refracted_color = trace(P, Ref, objects, depth-1, EPS, INT_MAX);
        result = result * (1 - closest->reflective - closest->refractive) +
                reflected_color * closest->reflective + refracted_color * closest->refractive;
        }

    return result;
}

point_3d multiple_matrix_vector (std::vector<point_3d> matrix, point_3d vector) {
    point_3d result;
    result.x = matrix[0].x * vector.x + matrix[0].y * vector.y+ matrix[0].z * vector.z;
    result.y = matrix[1].x * vector.x + matrix[1].y * vector.y+ matrix[1].z * vector.z;
    result.z = matrix[2].x * vector.x + matrix[2].y * vector.y+ matrix[2].z * vector.z;
    return result;
}

point_3d turn (point_3d vector, point_3d angle) {
    std::vector<point_3d> matrix (3);
    //X
    matrix[0] = {1, 0, 0};
    matrix[1].x = 0;
    matrix[1].y = cos(angle.x);
    matrix[1].z = -sin(angle.x);
    matrix[2].x = 0;
    matrix[2].y = sin(angle.x);
    matrix[2].z = cos(angle.x);
    vector = multiple_matrix_vector(matrix, vector);

    //Y
    matrix[0].x = cos(angle.y);
    matrix[0].y = 0;
    matrix[0].z = sin(angle.y);
    matrix[1] = {0, 1, 0};
    matrix[2].x = -sin(angle.y);
    matrix[2].y = 0;
    matrix[2].z = cos(angle.y);
    vector = multiple_matrix_vector(matrix, vector);

    //Z
    matrix[0].x = cos(angle.z);
    matrix[0].y = -sin(angle.z);
    matrix[0].z = 0;
    matrix[1].x = sin(angle.z);
    matrix[1].y = cos(angle.z);
    matrix[1].z = 0;
    matrix[2] = {0, 0, 1};

    vector = multiple_matrix_vector(matrix, vector);
    return vector;
}



void normalize_colors(std::vector <std::vector<color>> &scene) {
    for (double x = 0; x < scene.size(); x++)
        for (double y = 0; y < scene[0].size(); y++) {
            if (scene[x][y].r > 255) scene[x][y].r = 255;
            if (scene[x][y].g > 255) scene[x][y].g = 255;
            if (scene[x][y].b > 255) scene[x][y].b = 255;
        }
}

std::vector <std::vector<color>> myrender(int canvas_width, int canvas_height) {

    std::vector <std::vector<color>> buffer (canvas_width, std::vector<color>(canvas_height));
    auto scene = init_scene();
    int depth = 5;

    for (double x = 0; x < canvas_width; x++) {
        for (double y = 0; y < canvas_height; y++) {
            point_3d viewport_point = canvas_to_viewport(point_2d{x -canvas_width/2, y -canvas_height/2},
                                                         canvas_width, canvas_height);
            viewport_point = turn(viewport_point, scene->angle);
//            if (y == 342) {
//                int b = 0;
//                b++;
//            }
            color a = trace(scene->O, viewport_point, scene->objects, depth, 1, INT_MAX);
            buffer[x][y] = a;
        }
    }

    normalize_colors(buffer);
    return buffer;
}
