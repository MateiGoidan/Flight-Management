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

    Passenger per1(name_input, e_adress, phone, document_type, sex, id, ex_year);

    std::cout << "Hello " << per1.Get_Name() << ", your code is " << per1.Get_ID() << std::endl << std::endl;
    per1.Set_Status("normal");
}

void Plane_Details(Plane &p)
{
    std::cout << "Planes max-speed: " << p.Speed() << std::endl;
    std::cout << "Planes max-altitude: " << p.Altitude() << std::endl;
}

void Make_Planes()
{
    Light_Jet p1("Bluebird Airline");
    Aircraft p2("Bluebird Airline");
    Regional_Jet p3("Bluebird Airline");

    Plane_Details(p2);
}

void Verify_Luggage(Luggage* l)
{

    Carry_On* cary = dynamic_cast<Carry_On*>(l);
    
    if(cary) {
        std::cout << "This is a carry-on" << std::endl;
    }
    else {
        Checked* checked = dynamic_cast<Checked*>(l);
        
        if(checked) {
            std::cout << "This is a checked" << std::endl;
        }
        else { std::cout << "None of the above" << std::endl;}
    }
}

int main()
{
    std::vector<Luggage*> vl;
    Carry_On* bag1 = new Carry_On(20, 12, 8, 17);
    Checked* bag2 = new Checked(20, 12, 8, 17);
    vl.push_back(bag1);
    vl.push_back(bag2);

    for(int i = 0; i < vl.size(); i++)
    {
        Verify_Luggage(vl[i]);
    }

    List airport_list(4); 
    Adding_Airports(airport_list);

    Making_Passenger();

    Make_Planes();

    Making_Flight(airport_list);

    return 0;
}
