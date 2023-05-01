#include <iostream>
#include <string>
#include "plane.hpp"
#include "regional_jet.hpp"

//Constructor
Regional_Jet::Regional_Jet(std::string al) : airline_agency(al) {}

//Functions
int Regional_Jet::Speed() { return max_speed; }

int Regional_Jet::Altitude() {return max_altitude; }
