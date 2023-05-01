#include <iostream>
#include "luggage.hpp"
#include "carry_on.hpp"

//Constructor
Carry_On::Carry_On(float we, float he, float le, float wi) : Luggage(we, he, le, wi) {}

//Function
void Carry_On::Verify_Weight()
{
    try {
        if (*weight < 0 || *weight >= 10) {
            throw std::invalid_argument("Invalid weight");
        }
        std::cout << "Weight is valid" << std::endl;
    }
    catch (const std::invalid_argument e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

//Getters
float Carry_On::Get_Volume() {return (*height - 0.50) * (*width - 0.50) * (*length - 0.50);}
