#include "Bolt.h"
#include "Circle.h"
#include "Robot.h"

#include <vector>

const double robot_speed = 10; // pixels / sec
const double robot_radius = 20; //pixels
const int    robot_energy = 1000;    // initial energy
const double bolt_speed = 20;
const double FPS = 20;		   // frames per second
const double arenaXSize = 500; // pixels
const double arenaYSize = 500; // pixels


std::vector<Circle*> objectStorage;