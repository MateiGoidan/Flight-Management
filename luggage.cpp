#include <iostream>
#include "luggage.hpp"

//Constructor
Luggage::Luggage(float we, float he, float le, float wi) : weight(&we), height(&he), length(&le), width(&wi) {}

//Functions
void Luggage::Verify_Weight()
{
    try {
        if (*weight <= 0) {
            throw std::invalid_argument("Invalid weight");
        }
        std::cout << "Weight is valid" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

//Getters
float Luggage::Get_Volume() {return *height * *width * *length;}

//Destructors
Luggage::~Luggage()
{
    delete weight;
    delete height;
    delete width;
    delete length;
}
