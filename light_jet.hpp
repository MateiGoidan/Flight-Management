#ifndef LIGHT_JET
#define LIGHT_JET

#include <string>
#include "plane.hpp"

class Light_Jet : public Plane
{
public:
    Light_Jet(std::string al);
    virtual int Speed();
    virtual int Altitude();

private:
    std::string airline_agency;
    int seats = 7;
    int max_speed = 700;                        // km/h
    int max_altitude = 13716;                   // meters

};

#endif // !LIGHT_JET
