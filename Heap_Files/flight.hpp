#ifndef FLIGHT
#define FLIGHT

#include "airport.hpp"

class Flight
{
    double distance, time;                                          //The distance and time od said flight
    Airport departure;                                              //The airport from which we depart
    Airport arrival;                                                //The airport where we arrive

public:
    Flight(const Airport& dep, const Airport& ariv);                //Constructor
    double Data_Calculator(const Airport& dep, const Airport& arv); //Calculating the distanced based on coordinates of the 2 airports
    double Data_Calculator(double dist);                            //Calculating the time of the journey based on the distanced
    double Get_Distance();                                          //Getter for distanced
    double Get_Time();                                              //Getter for time
};

#endif // !FLIGHT
