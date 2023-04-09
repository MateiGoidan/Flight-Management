#ifndef PASSENGER
#define PASSENGER

class Passenger
{
    char* passenger_name;               //The name of the passenger
    static long id;                     //The unique id of each passenger 
                                        //We can also use this to get the total number of passengers after all destructors are called
public:
    Passenger(const char name[]);       //Constructor the passenger
    long Get_ID();                      //Getter for id
    ~Passenger();                       //Deconstructor
};

#endif // !PASSENGER
