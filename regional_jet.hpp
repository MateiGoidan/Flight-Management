#ifndef REGIONAL_JET
#define REGIONAL_JET

#include "plane.hpp"

class Regional_Jet : public Plane
{
public:
    Regional_Jet(std::string al);
    virtual int Speed();
    virtual int Altitude();

private:
    std::string airline_agency;
    int seats = 7;
    int max_speed = 800;                        // km/h
    int max_altitude = 12192;                   // meters
    
};

#endif // !REGIONAL_JET
