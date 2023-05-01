#include <iostream>
#include <string>
#include "plane.hpp"
#include "light_jet.hpp"

//Constructor
Light_Jet::Light_Jet(std::string al) : airline_agency(al) {}

//Functions
int Light_Jet::Speed() { return max_speed; }

int Light_Jet::Altitude() {return max_altitude; }
