#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <cmath>
#include <vector>

const double EPS = 0.00001;
const double PI = 3.1416;

class point_3d {
public:
    double x;
    double y;
    double z;
    point_3d() {
        x = 0;
        y = 0;
        z = 0;
    }
    point_3d(double xi, double yi, double zi) {
        x = xi;
        y = yi;
        z = zi;
    }
    double length() {
        return sqrt(x * x + y * y + z *z);
    }
    double dot_product (point_3d a) {
        return x * a.x + y * a.y + z * a.z;
    }
    point_3d cross_product (point_3d a) {
        point_3d res;
        res.x = y * a.z - z * a.y;
        res.y = x * a.z - z * a.x;
        res.z = x * a.y - y * a.x;
        return res;
    }
    point_3d operator+(const point_3d a) {
        return point_3d(x + a.x, y + a.y, z + a.z);
    }
    point_3d operator-(const point_3d a) {
        return point_3d(x - a.x, y - a.y, z - a.z);
    }
    point_3d operator*(double value) {
        return point_3d(x * value, y * value, z * value);
    }
    point_3d operator/(double value) {
        return point_3d(x / value, y / value, z / value);
    }
};

class point_2d {
public:
    double x;
    double y;
};

class color {
public:
    int r;
    int g;
    int b;
    color() {
        r = 0;
        g = 0;
        b = 0;
    }
    color(double ri, double gi, double bi) {
        r = round(ri);
        g = round(gi);
        b = round(bi);
    }
    color operator*(double value) {
        return color(r * value, g * value, b * value);
    }
    color operator+(const color a) {
        return color(r + a.r, g + a.g, b + a.b);
    }
};

class Figure {
public:
    virtual ~Figure() = 0;
    int specular;
    double reflective;
    double refractive;
    double refractive_index;
    bool transparent;
    color color;
    virtual std::vector<double> get_intersect_points(point_3d orig, point_3d dest) = 0;
    virtual point_3d get_normal(point_3d P) = 0;

};

inline Figure::~Figure() { }

class triangle : public Figure {
public:
    point_3d vertex[3];
    bool left_oriented; //Иногда лучше рендерится с точками, образующими нормаль внутрь фигуры (непонятно почему)
    double A;
    double B;
    double C;
    double D;
    std::vector<double> get_intersect_points(point_3d orig, point_3d dest) override {
        std::vector<double> result;
        point_3d vec;
        double znam = (A*dest.x + B*dest.y +C*dest.z);
        if (fabs(znam) < EPS)
            return result;
        double x = -(A*orig.x + B*orig.y + C*orig.z + D)/znam;
        point_3d P = orig + dest * x;
        point_3d AB = vertex[1] - vertex[0];
        point_3d AF = P - vertex[0];
        point_3d BC = vertex[2] - vertex[1];
        point_3d BF = P - vertex[1];
        point_3d CA = vertex[0] - vertex[2];
        point_3d CF = P - vertex[2];

        point_3d na = AB.cross_product(AF);
        point_3d nb = BC.cross_product(BF);
        point_3d nc = CA.cross_product(CF);
        bool sign_x = ((na.x >= EPS && nb.x >= EPS && nc.x >= EPS) || (na.x <= EPS && nb.x <= EPS && nc.x <= EPS));
        bool sign_y = ((na.y >= EPS && nb.y >= EPS && nc.y >= EPS) || (na.y <= EPS && nb.y <= EPS && nc.y <= EPS));
        bool sign_z = ((na.z >= EPS && nb.z >= EPS && nc.z >= EPS) || (na.z <= EPS && nb.z <= EPS && nc.z <= EPS));
        if (sign_x && sign_y && sign_z)
            result.push_back(x);
        return result;
    }
    point_3d get_normal(point_3d P) override {
        return {A, B, C};
    }
};



class Pixel {
public:
    point_3d pos;
    color color;
};

class light_src {
public:
    double intensity;
    point_3d pos;
};

class sphere : public Figure {
public:
    point_3d center;
    double radius;

    std::vector<double> get_intersect_points(point_3d viewer, point_3d viewport) override {
        //std::vector <double> result;
        point_3d OC = {viewer.x - center.x, viewer.y - center.y, viewer.z - center.z};

        double a = viewport.dot_product(viewport);
        double b = 2*OC.dot_product(viewport);
        double c = OC.dot_product(OC) - radius * radius;

        return solve_quadratic_equation(a, b, c);
    }
    point_3d get_normal(point_3d P) override {
        return P - center;
    }
private:
    std::vector<double> solve_quadratic_equation(double a, double b, double c) {
        std::vector<double> result;
        double D = b*b - 4*a*c;
        if (D >= EPS) {
            double x1 = (-b + sqrt(D))/(2*a);
            result.push_back(x1);
            double x2 = (-b - sqrt(D))/(2*a);
            result.push_back(x2);
        }
        return result;
    }
};

point_3d get_normal_vector(point_3d vert_1, point_3d vert_2, point_3d vert_3, bool left_oriented);

#endif // PRIMITIVES_H
