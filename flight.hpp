#ifndef FLIGHT
#define FLIGHT

#include "airport.hpp"

class Flight
{
    double distance;                                                //The distance and time od said flight
    static double time; 
    Airport departure;                                              //The airport from which we depart
    Airport arrival;                                                //The airport where we arrive

    public:
    Flight(const Airport& dep, const Airport& ariv);                //Constructor
    void Data_Calculator(const Airport& dep, const Airport& arv); //Calculating the distanced based on coordinates of the 2 airports
    static void Data_Calculator(double dist);                            //Calculating the time of the journey based on the distanced
    double Get_Distance();                                          //Getter for distanced
    ~Flight();
};

#endif // !FLIGHT
