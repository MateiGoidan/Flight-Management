#include <iostream>
#include <string>
#include <cmath>
#include "document.hpp"
#include "exception.hpp"

//Constructor
Document::Document(std::string t, std::string s, long id, int ed) : type(t), sex(s), id(id), expire_date(ed) 
{
    //Veryfing if the input data is corect
    try {
        if(type != "passport" && type != "identity card")
            throw Exception("Invalid document type!");
    } catch(Exception &er1) {
        std::cout << er1.what() << std::endl;
    }

    try {
        if(sex != "M" && sex != "F")
            throw Exception("Invalid input for sex!");
    } catch(Exception &er1) {
        std::cout << er1.what() << std::endl;
    }

    try {
        if(id >= pow(10, 13))
            throw Exception("Invalid personal code!");
    } catch(Exception &er1) {
        std::cout << er1.what() << std::endl;
    }

    try {
        if(expire_date < 2023)
            throw Exception("Document has expired!");
    } catch(Exception &er1) {
        std::cout << er1.what() << std::endl;
    }
}
