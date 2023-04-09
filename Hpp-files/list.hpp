#ifndef LIST
#define LIST

#include "airport.hpp"

class List
{
public:
    List(int size);                                 //Cosntructor
    void Add_Airport(const Airport& new_airport);   //Function that adds an airport to the array 
    bool Remove_Airport(int index);                 //Function that removes an airport from the array
    unsigned int Get_Num();                         //Getter for the number of airports in the array
    Airport& Get_Airport(int integer);              //Getter for an airport from the array
    ~List();                                        //Deconstructor

private:
    Airport* airport_list;                          //An array of multiple airports
    unsigned int num_airports = 0;                  //The number of airports in that list
};

#endif // !LIST
