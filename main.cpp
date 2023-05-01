#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "exception.hpp"
#include "luggage.hpp"
#include "carry_on.hpp"
#include "checked.hpp"
#include "data.hpp"
#include "document.hpp"
#include "passenger.hpp"
#include "plane.hpp"
#include "light_jet.hpp"
#include "regional_jet.hpp"
#include "aircraft.hpp"
#include "airport.hpp"
#include "list.hpp"
#include "flight.hpp"

std::string name_input, e_adress, phone, document_type, sex;
long id;
int ex_year;

void Adding_Airports(List &airport_list)
{
    //Adding some airports for our airports-array
    Airport gr("Berlin", 52.36, 13.51);
    Airport fr("Paris", 49.02, 2.54);
    Airport uk("London", 1.36, 90.51);

    airport_list.Add_Airport(gr);
    airport_list.Add_Airport(fr);
    airport_list.Add_Airport(uk);
}

void Making_Flight(List &airport_list)
{
    int code;
    //Choosing the airport from which we depart
    std::cout << "Where would you like to depart from?" << std::endl;
    for(int i = 0; i < airport_list.Get_Num(); i++)
        std::cout << i << ") " << airport_list.Get_Airport(i) << std::endl;

    std::cout << "Please input the number of the airport from the list: ";
    std::cin >> code;
    Airport dep(airport_list.Get_Airport(code));

    airport_list.Remove_Airport(code);

    //Choosing the the airport in which we arrive
    std::cout << std::endl;
    std::cout << "And where would you like to arrive?" << std::endl;
    for(int i = 0; i < airport_list.Get_Num(); i++)
        std::cout << i << ") " << airport_list.Get_Airport(i) << std::endl;

    std::cout << "Please input the number of the airport from the list: ";
    std::cin >> code;
    Airport ariv(airport_list.Get_Airport(code));

    //Generating the details of the flight
    Flight f1(dep, ariv);
}

void Making_Passenger()
{
    std::cout << "Welcome to Bluebird Airways!" << std::endl;
    std::cout << "Please tell us your name: ";
    //Name of the passanger
    std::cin >> name_input;

    std::cout << "Email address: ";
    std::cin >> e_adress;

    std::cout << "Phone number: ";
    std::cin >> phone;

    std::cout << "Travel document type: ";
    std::cin >> document_type;

    std::cout << "Sex: ";
    std::cin >> sex;
    
    std::cout << "Personal Identification Code: ";
    std::cin >> id;

    std::cout << "Experation year: ";
    std::cin >> ex_year;

    Passenger(name_input, e_adress, phone, document_type, sex, id, ex_year);
}

/*
void Make_Planes()
{
    std::vector<Plane*> planes;
    planes.push_back(new Light_Jet("Bluebird Airways"));
}
*/

void Verify_Luggage(Luggage l)
{
    Luggage* lug1 = &l;

    Checked* checked = dynamic_cast<Checked*>(lug1);
    
    if(checked) {
        std::cout << "This is a check-luggage" << std::endl;
    }
    else {
        Carry_On* cary = dynamic_cast<Carry_On*>(lug1);
        
        if(cary) {
            std::cout << "This is a carry-on" << std::endl;
        }
        else { std::cout << "This is not a luggage" << std::endl;}
    }
}

int main()
{
    Luggage l(20, 12, 8, 17);
    Verify_Luggage(l);
    List airport_list(4); 
    Adding_Airports(airport_list);

    Making_Passenger();

    Making_Flight(airport_list);

    return 0;
}
