#include "primitives.h"

point_3d get_normal_vector(point_3d vert_1, point_3d vert_2, point_3d vert_3) {
    point_3d result;
    result.x = (vert_2.y - vert_1.y)*(vert_3.z - vert_1.z) -
                (vert_2.z - vert_1.z)*(vert_3.y - vert_1.y);
    result.y = (vert_2.z - vert_1.z)*(vert_3.x - vert_1.x) -
                (vert_2.x - vert_1.x)*(vert_3.z - vert_1.z);
    result.z = (vert_2.x - vert_1.x)*(vert_3.y - vert_1.y) -
                (vert_2.y - vert_1.y)*(vert_3.x - vert_1.x);

    return result / result.length();;
}
