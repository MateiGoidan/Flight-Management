#ifndef AIRPORT
#define AIRPORT

#include <memory>

class Airport
{
    std::unique_ptr<std::string> airport_name;                                  //Airport's name
    std::unique_ptr<double> x_coordinate;
    std::unique_ptr<double> y_coordinate;                                       //Airport's coordinates

public:
    Airport();                                                                  //Default constructor
    Airport(std::string name, double x, double y);                              //Constructor with parameters
    Airport(const Airport& airport);                                            //Copy-constructor
    void Set_Data(double x, double y);                                          //Set coordinates
    void Set_Data(std::string name);                                            //Set the name of the airport
    double Get_x() const;                                                       //Getter of the x coordinate
    double Get_y() const;                                                       //Getter of the x coordinate 
    Airport& operator=(const Airport& airport);                                 //Overloading the operator '='
    friend std::ostream& operator<<(std::ostream& of, const Airport& airport);  //Overloading the operator '<<'
    friend std::istream& operator>>(std::istream& on, Airport& airport);        //Overloading the operator '>>'
};

#endif // !AIRPOR
