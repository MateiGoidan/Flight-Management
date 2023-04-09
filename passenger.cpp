#include <iostream>
#include <cstring>
#include "Hpp-files/passenger.hpp"

//Constructors
Passenger::Passenger(const char name[])
{ 
    //Dynamic allocation for the name of the passenger using a pointer
    passenger_name = new char[strlen(name) + 1];
    strcpy(passenger_name, name);
    id++;
    std::cout << '\n' << "Welcome " << name << "! ";
}

//Getters and Setters
long Passenger::Get_ID()
{
    return id;
}

//Destructor
Passenger::~Passenger()
{
    //Dealocating the pointer
    delete[] passenger_name;
}
