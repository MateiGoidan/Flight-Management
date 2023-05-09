#ifndef PASSENGER
#define PASSENGER

#include "data.hpp"
#include "document.hpp"

class Passenger : protected Data, protected Document
{
    public:
        Passenger(std::string n, std::string e, std::string p, std::string t, std::string s, long id, int ed);          //Constructor the passenger
        void Set_Status(std::string s);
        static long Get_ID();
        std::string Get_Name();
                                                                                                                        
    private:
        static long id;                                                                                                  //The passenger ID
        std::string status;
};

#endif // !PASSENGER
