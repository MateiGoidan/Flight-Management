#include <iostream>
#include <string>
#include "document.hpp"
#include "data.hpp"
#include "passenger.hpp"

long Passenger::id = 1000;

//Constructors
Passenger::Passenger(std::string n, std::string e, std::string p, std::string t, std::string s, long id, int ed) : Data(n, e, p), Document(t,s,id,ed) {}

//Getters and Setters
long Passenger::Get_ID()
{
    return id;
}

std::string Passenger::Get_Name()
{
    return name;
}

void Passenger::Set_Status(std::string s)
{
    status = s;
}
