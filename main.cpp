#include <iostream>
#include <cstring>
#include "Hpp-files/passenger.hpp"
#include "Hpp-files/airport.hpp"
#include "Hpp-files/list.hpp"
#include "Hpp-files/flight.hpp"
#include "Hpp-files/ticket.hpp"

long Passenger::id = 1000;

char name_input[256];
int code;
int main()
{    
    //Adding some airports for our airports-array
    List airport_list(2); 
    Airport gr("Berlin", 52.36, 13.51);
    Airport fr("Paris", 49.02, 2.54);
    Airport uk("London", 52.36, 13.51);

    airport_list.Add_Airport(gr);
    airport_list.Add_Airport(fr);
    airport_list.Add_Airport(uk);

    //Menu
    std::cout << "Welcome to Bluebird Airways!" << std::endl;
    std::cout << "Please tell us your name: ";
    //Name of the passanger
    std::cin >> name_input;

    //Admin lets you make changes to the airports-array
    if(strcmp(name_input, "Admin") == 0)
    {
        code = 4;
        std::cout << "Welcome to edit menu! Here you can add and change the data of the airports we are associated" << std::endl;
        std::cout << "(0)Quit (1)List all the airports (2)Add Airport (3)Remove Airport" << std::endl;
        std::cout << std::endl;
        while(code != 0)
        {
            std::cout << "Input: ";
            std::cin >> code;

            //Showing all the airports of the array
            if(code == 1)
            {
                std::cout << "List: " << airport_list.Get_Num() << std::endl;
                for(int i = 0; i < airport_list.Get_Num(); i++)
                    std::cout << i << ") " << airport_list.Get_Airport(i) << std::endl;
            }

            //Adding an airport to the array
            if(code == 2)
            {
                Airport new_airport;
                std::cout << "Please input the name of the airport and its coordinates:" << std::endl;
                std::cin >> new_airport;
                airport_list.Add_Airport(new_airport);
                std::cout << "Airport - " << airport_list.Get_Airport(airport_list.Get_Num() - 1) << " added" << std::endl;
            }

            //Removing an airport to the array
            if(code == 3)
            {
                unsigned int num;
                std::cout << "Please input the number of the airport from the list: ";
                std::cin >> num;
                if(airport_list.Remove_Airport(num) == true)
                    std::cout << "Airport removed succesfuly" << std::endl;
                else
                    std::cout << "ERROR" << std::endl;
            }

            std::cout << std::endl;
        }
    }
    else {
        Passenger per1(name_input);

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

        Ticket board_pass(per1, f1);

        //Final price
        std::cout << std::endl;
        std::cout << "Your ticket price is: " << board_pass.Get_Cost() << " euros" << std::endl;
    } 

    return 0;
}