#include "scene.h"

point_3d O = {0, 0, 0};
light_src lamp = {0.6, {2, 1, 1}};
point_3d angle = {0, 0, 0};

double degrees_to_radians(double angle) {
    return angle * PI / 180;
}

void setup_glassplain_from_triangle(triangle *tr) {
        tr->color = {0, 186, 228};
        tr->reflective = 0.01;
        tr->refractive = 0.4;
        tr->refractive_index = 1.3;
        tr->specular = 20;
        tr->transparent = true;
        point_3d n = get_normal_vector(tr->vertex[0], tr->vertex[1], tr->vertex[2], tr->left_oriented);
                tr->A = int(round(n.x));
                tr->B = int(round(n.y));
                tr->C = int(round(n.z));
                tr->D = int(round(-n.x*tr->vertex[0].x-n.y*tr->vertex[0].y-n.z*tr->vertex[0].z));
}

scene *init_scene() {
    scene_objects *sc_o = new scene_objects;
    sc_o->lamp = lamp;
//    sphere *t1 = new sphere;
//    t1->color = {255, 0, 0}; //red
//    t1->center = {0, 0, 3};
//    t1->radius = 1;
//    t1->specular = 500;
//    t1->reflective = 0; //0.02
//    t1->refractive = 0.5;
//    t1->refractive_index = 1.5;
//    t1->transparent = false;
//    sc_o->items.push_back(t1);

//    sphere *t2 = new sphere;
//    t2->color = {0, 0, 255}; //blue
//    t2->center = {-2, 1, 3};
//    t2->radius = 1;
//    t2->specular = 500;
//    t2->reflective = 0.03; //0.03
//    t2->refractive = 0.3;
//    t2->refractive_index = 1;
//    t2->transparent = false;
//    items->t_vec.push_back(t2);


//    sphere *t3 = new sphere;
//    t3->color = {0, 149, 182}; //water
//    t3->center = {0, 1, 12};
//    t3->radius = 2;
//    t3->specular = 200;
//    t3->reflective = 0; //0.03
//    t3->refractive = 0.7;
//    t3->refractive_index = 1.5;
//    t3->transparent = false;
//    items->t_vec.push_back(t3); //!

    sphere *t4 = new sphere;
    t4->color = {255, 0, 0}; //water -> red
    t4->center = {0, 3, 10};
    t4->radius = 2;
    t4->specular = 200;
    t4->reflective = 0.03; //0.03
    t4->refractive = 0;
    t4->refractive_index = 1;
    t4->transparent = false;
    sc_o->items.push_back(t4); //!

    sphere *t5 = new sphere;
    t5->color = {255, 255, 0}; //yellow
    t5->center = {0, -5005, 0};
    t5->radius = 5000;
    t5->specular = 1000;
    t5->reflective = 0.4; //0.05
    t5->refractive = 0;
    t5->refractive_index = 1;
    t5->transparent = false;
    sc_o->items.push_back(t5); //!

//    sphere *t6 = new sphere;
//    t6->color = {255, 0, 0}; //red 2
//    t6->center = {2, 0, 15};
//    t6->radius = 1;
//    t6->specular = 1000;
//    t6->reflective = 0; //0.05
//    t6->refractive = 0;
//    t6->refractive_index = 1;
//    t6->transparent = false;
//    items->t_vec.push_back(t6); //!

//    sphere *t7 = new sphere;
//    t7->color = {255, 255, 0}; //yellow 3
//    t7->center = {0, 0, 1000};
//    t7->radius = 2000;
//    t7->specular = 1000;
//    t7->reflective = 0.05; //0.05
//    t7->refractive = 0;
//    t7->refractive_index = 1;
//    t7->transparent = false;
//    items->t_vec.push_back(t7);

//    sphere *t8 = new sphere;
//    t8->color = {0, 255, 0}; //green
//    t8->center = {2, 1, 3};
//    t8->radius = 1;
//    t8->specular = 10;
//    t8->reflective = 0.04; //0.04
//    t8->refractive = 0.4;
//    t8->refractive_index = 1;
//    t8->transparent = false;
//    items->t_vec.push_back(t8);

    //СТАКАН
    //Перед
    const int width = 2; //ширина /2
    const int height = 3; //высота /2
    triangle *tr = new triangle;
    tr->vertex[0] = {-width, -height, 8}; //Левая нижняя
    tr->vertex[2] = {width, -height, 8}; //Правая нижняя
    tr->vertex[1] = {width, height, 8}; //Правая верхняя
//    tr.A = 0;
//    tr.B = 0;
//    tr.C = 1;
//    tr.D = -8;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    tr = new triangle;
    tr->vertex[0] = {width, height, 8}; //Правая верхняя
    tr->vertex[1] = {-width, -height, 8}; //Левая нижняя
    tr->vertex[2] = {-width, height, 8}; //Левая верхняя
//    tr.A = 0;
//    tr.B = 0;
//    tr.C = 1;
//    tr.D = -8;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    //Левый бок
    tr = new triangle;
    tr->vertex[0] = {-width, -height, 8}; //Левая нижняя
    tr->vertex[1] = {-width, height, 8+width*2}; //Левая верхняя дальняя
    tr->vertex[2] = {-width, height, 8}; //Левая верхняя
//    tr.A = 1;
//    tr.B = 0;
//    tr.C = 0;
//    tr.D = 2;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    tr = new triangle;
    tr->vertex[0] = {-width, -height, 8}; //Левая нижняя
    tr->vertex[1] = {-width, -height, 8+width*2}; //Левая нижняя дальняя
    tr->vertex[2] = {-width, height, 8+width*2}; //Левая верхняя дальняя
//    tr.A = 1;
//    tr.B = 0;
//    tr.C = 0;
//    tr.D = 2;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    //Правый бок
    tr = new triangle;
    tr->vertex[0] = {width, height, 8}; //Правая верхняя
    tr->vertex[1] = {width, -height, 8}; //Правая нижняя
    tr->vertex[2] = {width, -height, 8+width*2}; //Правая нижняя дальняя
//    tr.A = -1;
//    tr.B = 0;
//    tr.C = 0;
//    tr.D = 2;
    tr->left_oriented = false;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    tr = new triangle;
    tr->vertex[0] = {width, -height, 8 + width*2}; //Правая нижняя дальняя
    tr->vertex[1] = {width, height, 8+width*2}; //Правая верхняя дальняя
    tr->vertex[2] = {width, height, 8}; //Правая верхняя
//    tr.A = -1;
//    tr.B = 0;
//    tr.C = 0;
//    tr.D = 2;
    tr->left_oriented = false;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    //Зад
    tr = new triangle;
    tr->vertex[0] = {-width, -height, 8+width*2}; //Левая нижняя
    tr->vertex[1] = {width, height, 8+width*2}; //Правая верхняя
    tr->vertex[2] = {width, -height, 8+width*2}; //Правая нижняя
//    tr.A = 0;
//    tr.B = 0;
//    tr.C = -1;
//    tr.D = 8 + width * 2;
    tr->left_oriented = false;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    tr = new triangle;
    tr->vertex[0] = {-width, -height, 8+width*2}; //Левая нижняя
    tr->vertex[1] = {-width, height, 8+width*2}; //Левая верхняя
    tr->vertex[2] = {width, height, 8+width*2}; //Правая верхняя
//    tr.A = 0;
//    tr.B = 0;
//    tr.C = - 1;
//    tr.D = 8 + width * 2;
    tr->left_oriented = false;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    //Низ
    tr = new triangle;
    tr->vertex[0] = {width, -height, 8}; //Правая нижняя
    tr->vertex[1] = {-width, -height, 8}; //Левая нижняя
    tr->vertex[2] = {-width, -height, 8+width*2}; //Левая нижняя дальняя
//    tr.A = 0;
//    tr.B = -1;
//    tr.C = 0;
//    tr.D = -height;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    tr = new triangle;
    tr->vertex[0] = {width, -height, 8}; //Правая нижняя
    tr->vertex[1] = {-width, -height, 8 + width*2}; //Левая нижняя дальняя
    tr->vertex[2] = {width, -height, 8 + width*2}; //Правая нижняя дальняя
//    tr.A = 0;
//    tr.B = -1;
//    tr.C = 0;
//    tr.D = -height;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    //Верх
    tr = new triangle;
    tr->vertex[0] = {-width, height, 8}; //Левая верхняя
    tr->vertex[1] = {width, height, 8}; //Правая вехрняя
    tr->vertex[2] = {-width, height, 8+width*2}; //Левая верхняя дальняя
//    tr.A = 0;
//    tr.B = 1;
//    tr.C = 0;
//    tr.D = -height;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);

    tr = new triangle;
    tr->vertex[0] = {width, height, 8}; //Правая вехрняя
    tr->vertex[1] = {width, height, 8+width*2}; //Правая верхняя дальняя
    tr->vertex[2] = {-width, height, 8+width*2}; //Левая верхняя дальняя
//    tr.A = 0;
//    tr.B = 1;
//    tr.C = 0;
//    tr.D = -height;
    tr->left_oriented = true;
    setup_glassplain_from_triangle(tr);
    sc_o->items.push_back(tr);


    scene *sc = new scene;
    sc->O = O;
    sc->objects = sc_o;
    sc->angle = {degrees_to_radians(angle.x), degrees_to_radians(angle.y), degrees_to_radians(angle.z)};
    return sc;
}
