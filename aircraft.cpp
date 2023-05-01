#include <iostream>
#include <string>
#include "plane.hpp"
#include "aircraft.hpp"

//Constructor
Aircraft::Aircraft(std::string al) : airline_agency(al) {} 

//Functions
int Aircraft::Speed() { return max_speed; }

int Aircraft::Altitude() {return max_altitude; }
