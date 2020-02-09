#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>
#include <cmath>
#include "scene.h"

const double ambient_light = 0.4;
const double viewport_width = 1;
const double viewport_height = 1;
const double viewport_d = 1;



std::vector <std::vector<color>> myrender(int canvas_width, int canvas_height);

#endif // RAYTRACER_H
