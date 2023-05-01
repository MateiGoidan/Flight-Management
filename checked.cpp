#include <iostream>
#include "luggage.hpp"
#include "checked.hpp"

//Constructor
Checked::Checked(float we, float he, float le, float wi) : Luggage(we, he, le, wi){}

//Function
void Checked::Verify_Weight()
{
    try {
        if (*weight < 0 || *weight >= 30) {
            throw std::invalid_argument("Invalid weight");
        }
        std::cout << "Weight is valid" << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

//Getters
float Checked::Get_Volume() {return (*height + 1.5) * (*width + 1.5) * (*length + 1.5);}
