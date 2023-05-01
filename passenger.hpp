#ifndef PASSENGER
#define PASSENGER

#include "data.hpp"
#include "document.hpp"

class Passenger : protected Data, protected Document
{
    public:
        Passenger(std::string n, std::string e, std::string p, std::string t, std::string s, long id, int ed);          //Constructor the passenger
                                                                                                                        
    private:
        static long id;                                                                                                  //The passenger ID
};

#endif // !PASSENGER
