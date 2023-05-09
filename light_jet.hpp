#ifndef LIGHT_JET
#define LIGHT_JET

#include "plane.hpp"

class Light_Jet : public Plane
{
public:
    Light_Jet(std::string al) : airline(al) {}

    virtual int Speed() {
        return max_speed;
    }

    virtual int Altitude() 
    {
        return max_altitude;
    }

private:
    std::string airline;
    int seats = 7;
    int max_speed = 70;
    int max_altitude = 1400;
    
};

#endif // !LIGHT_JET
