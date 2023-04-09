#ifndef AIRPORT
#define AIRPORT

class Airport
{
    char* airport_name;                         //Airport's name
    double x_coordinate, y_coordinate;          //Airport's coordinates

public:
    Airport();                                                                  //Default constructor
    Airport(const char name[], double x, double y);                             //Constructor with parameters
    Airport(const Airport& airport);                                            //Copy-constructor
    void Set_Data(double x, double y);                                          //Set coordinates
    void Set_Data(char name[]);                                                 //Set the name of the airport
    double Get_x() const;                                                       //Getter of the x coordinate
    double Get_y() const;                                                       //Getter of the x coordinate 
    Airport& operator=(const Airport& airport);                                 //Overloading the operator '='
    friend std::ostream& operator<<(std::ostream& of, const Airport& airport);  //Overloading the operator '<<'
    friend std::istream& operator>>(std::istream& on, Airport& airport);        //Overloading the operator '>>'
    ~Airport();                                                                 //Deconstructor
};

#endif // !AIRPOR
