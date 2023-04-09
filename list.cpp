#include <iostream>
#include "Hpp-files/list.hpp"

//Constructor
List::List(int size)
{
    if(size == 0)
        airport_list = nullptr;
    else 
        airport_list = new Airport[size];
}

//Functions
void List::Add_Airport(const Airport& new_airport)
{
    num_airports++;
    Airport* copy_list = new Airport[num_airports];

    for(int i = 0; i < num_airports - 1; i++)
        copy_list[i] = airport_list[i];

    copy_list[num_airports - 1] = new_airport;
    delete[] airport_list;
    airport_list = copy_list;
}

bool List::Remove_Airport(int index)
{
    if(index >= num_airports || index < 0)
        return false;

    if(num_airports == 1)
    {
        delete[] airport_list;
        airport_list = nullptr;
        num_airports = 0;
        return true;
    }

    if(num_airports == 2)
    {
        Airport* copy_list = new Airport[num_airports];

        if(index == 0)
        {
            copy_list[0] = airport_list[1];
            delete[] airport_list;
            airport_list = copy_list;
        }
        else
        {
            copy_list[0] = airport_list[0];
            delete[] airport_list;
            airport_list = copy_list;
        }
        num_airports--;
        return true;
    }

    Airport* copy_list = new Airport[num_airports];

    for(int i = 0; i < index; i++)
        copy_list[i] = airport_list[i];

    for(int i = index; i < num_airports - 1; i++)
        copy_list[i] = airport_list[i + 1]; 

    num_airports = num_airports - 1;
    delete[] airport_list;
    airport_list = copy_list;
    return true;
}

unsigned int List::Get_Num()
{
    return num_airports;
}

Airport& List::Get_Airport(int integer) 
{
    return airport_list[integer];
}

//Deconstructor
List::~List()
{
    delete[] airport_list;
}
