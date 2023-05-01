#include <iostream>
#include <cmath>
#include "flight.hpp"
#include "airport.hpp"

double Flight::time = 0;

//Constructor
Flight::Flight(const Airport& dep, const Airport& ariv) : departure(dep), arrival(ariv) {
    Data_Calculator(departure, arrival);
    Data_Calculator(distance);
}

//Getters and Setters
double Flight::Get_Distance()
{
    return distance;
}

//Functions
void Flight::Data_Calculator(const Airport& dep, const Airport& arv)
{
    //To calculate the distance between two points on a globe, we can use the Haversine formula. 
    //The formula uses the latitude and longitude of the two points to calculate the great-circle distance between them.
    const double earth_radius = 6371;
    double d_lat = (arv.Get_x() - dep.Get_x()) * M_PI / 180.0;
    double d_lon = (arv.Get_y() - dep.Get_y()) * M_PI / 180.0;    
    double a = pow(sin(d_lat / 2), 2) + cos(dep.Get_x() * M_PI / 180.0) * cos(arv.Get_x() * M_PI / 180.0) * pow(sin(d_lon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = earth_radius * c;
}

void Flight::Data_Calculator(double dist)
{
    //To calculate the time of flight we divide the distance with
    //the gound speed of a plane (we put a generic speed of 600 kmph)
    time = dist / 600;
}

//Deconstructor
Flight::~Flight()
{
    time = 0;
}
