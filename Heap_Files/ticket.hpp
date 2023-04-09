#ifndef TICKET
#define TICKET

#include "passenger.hpp"
#include "airport.hpp"
#include "flight.hpp"

class Ticket
{
public:
    Ticket(const Passenger& pas, const Flight& f);  //Constructor
    double Get_Cost();                              //Getter for cost_ticket
    void Price(Flight f);                           //Calculating the price of a ticket

private:
    Passenger passenger;                            //The passanger of the ticket
    Flight flight;                                  //The flight bought with the ticket
    double cost_ticket;                             //The cost of the flight
    float cost_km = 0.20;                           //Generic price per kilometer
    float cost_hour = 90;                           //Generic price per hour
};

#endif // !TICKET
