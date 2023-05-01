#ifndef LUGGAGE
#define LUGGAGE

class Luggage
{
public:
    Luggage(float we, float he, float le, float wi); 
    virtual void Verify_Weight();
    virtual float Get_Volume();

protected:
    float* weight;
    float* height;
    float* length;
    float* width;
};

#endif // !DEBUG
