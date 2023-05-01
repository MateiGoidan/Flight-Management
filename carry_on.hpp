#ifndef CARRY_ON
#define CARRY_ON

#include "luggage.hpp"

class Carry_On : public Luggage
{
public:
    Carry_On(float we, float he, float le, float wi); 
    virtual void Verify_Weight() override;
    virtual float Get_Volume() override;

};

#endif // !CARRY_ON
