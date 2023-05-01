#include <iostream>
#include <cstring>
#include <memory>
#include "airport.hpp"

//Constructors
Airport::Airport()
{
    airport_name = nullptr;
    x_coordinate = nullptr;
    y_coordinate = nullptr;
}

Airport::Airport (std::string name, double x, double y)
{
    airport_name = std::make_unique<std::string>(name);
    x_coordinate = std::make_unique<double>(x);
    y_coordinate = std::make_unique<double>(y);
}

//Copy Constructor
Airport::Airport(const Airport& airport)
{
    airport_name = std::make_unique<std::string>(*airport.airport_name);
    x_coordinate = std::make_unique<double>(*airport.x_coordinate);
    y_coordinate = std::make_unique<double>(*airport.y_coordinate);
}

//Getters and Setters
void Airport::Set_Data(double x, double y)
{
    x_coordinate = std::make_unique<double>(x);
    y_coordinate = std::make_unique<double>(y);
}

void Airport::Set_Data(std::string name)
{
    airport_name = std::make_unique<std::string>(name);
}

double Airport::Get_x() const
{
    return *x_coordinate;
}

double Airport::Get_y() const
{
    return *y_coordinate;
}

//Overloading the >>, << and = operators
std::istream& operator>>(std::istream& on, Airport& airport)
{
    std::string copy;
    double x, y;

    on >> copy >> x >> y;
    airport.airport_name = std::make_unique<std::string>(copy);
    airport.x_coordinate = std::make_unique<double>(x);
    airport.y_coordinate = std::make_unique<double>(y);

    return on;
}

std::ostream& operator<<(std::ostream& of, const Airport& airport)
{
    of << "Name: " << *airport.airport_name << " [" << *airport.x_coordinate << ", " << *airport.y_coordinate << "]";
    return of;
}

Airport& Airport::operator=(const Airport& airport)
{
    if (this != &airport)
    {
        airport_name = std::make_unique<std::string>(*airport.airport_name);
        x_coordinate = std::make_unique<double>(*airport.x_coordinate);
        y_coordinate = std::make_unique<double>(*airport.y_coordinate);
    }
    return *this;
}
