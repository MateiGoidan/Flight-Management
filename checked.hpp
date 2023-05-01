#ifndef CHECKED
#define CHECKED

#include "luggage.hpp"

class Checked : protected Luggage
{
public:
    Checked(float we, float he, float le, float wi); 
    virtual void Verify_Weight() override;
    virtual float Get_Volume() override;

};

#endif // !CHECKED
