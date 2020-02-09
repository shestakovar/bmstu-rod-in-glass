#ifndef SCENE_H
#define SCENE_H

#include "primitives.h"

extern point_3d O;
extern light_src lamp;
extern point_3d angle;

class scene_objects {
public:
    light_src lamp;
    std::vector<Figure*> items;
};

class scene {
public:
    point_3d O; //viewer
    point_3d angle;
    scene_objects *objects;
};

scene *init_scene();

#endif // SCENE_H
