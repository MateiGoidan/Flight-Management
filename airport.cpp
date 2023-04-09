#include <iostream>
#include <cstring>
#include "Hpp-files/airport.hpp"

//Constructors
Airport::Airport()
{
    airport_name = nullptr;
    x_coordinate = 0;
    y_coordinate = 0;
}

Airport::Airport (const char name[], double x, double y)
{
    airport_name = new char[strlen(name) + 1];
    strcpy(airport_name, name);
    x_coordinate = x;
    y_coordinate = y;
}

//Copy Constructor
Airport::Airport(const Airport& airport)
{
    airport_name = new char[strlen(airport.airport_name)];
    strcpy(airport_name, airport.airport_name);
    x_coordinate = airport.x_coordinate;
    y_coordinate = airport.y_coordinate;
}

//Getters and Setters
void Airport::Set_Data(double x, double y)
{
    x_coordinate = x;
    y_coordinate = y;
}

void Airport::Set_Data(char name[])
{
    delete[] airport_name;
    airport_name = new char[strlen(name) + 1];
    strcpy(airport_name, name);
}

double Airport::Get_x() const
{
    return x_coordinate;
}

double Airport::Get_y() const
{
    return y_coordinate;
}

//Overloading the >>, << and = operators
std::istream& operator>>(std::istream& on, Airport& airport)
{
    char copy[256];
    on >> copy;
    airport.airport_name = new char[strlen(copy) + 1];
    std::strcpy(airport.airport_name, copy);

    on >> airport.x_coordinate >> airport.y_coordinate;
    return on;
}

std::ostream& operator<<(std::ostream& of, const Airport& airport)
{
    of << "Name: " << airport.airport_name << " [" << airport.x_coordinate << ", " << airport.y_coordinate << "]";
    return of;
}

Airport& Airport::operator=(const Airport& airport)
{
   if (this != &airport)
   {
       airport_name = new char(strlen(airport.airport_name) + 1);
       strcpy(airport_name, airport.airport_name);
       x_coordinate = airport.x_coordinate;
       y_coordinate = airport.y_coordinate;
   }
   return *this;
}

//Deconstructor
Airport::~Airport()
{
    delete[] airport_name;

}
