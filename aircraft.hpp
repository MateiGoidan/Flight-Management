#ifndef AIRCRAFT
#define AIRCRAFT

#include "plane.hpp"

class Aircraft : public Plane
{
public:
    Aircraft(std::string al);
    virtual int Speed();
    virtual int Altitude();

private:
    std::string airline_agency;
    int seats = 190;
    int max_speed = 950;                        // km/h
    int max_altitude = 12192;                   // meters
    
};

#endif // !AIRCRAFT
