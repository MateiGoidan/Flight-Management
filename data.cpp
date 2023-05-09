#include <iostream>
#include <cmath>
#include <string>
#include "data.hpp"
#include "exception.hpp"

//Constructor
Data::Data(std::string n, std::string e, std::string p) : name(n), email(e), phone(p) 
{
    std::string ex;                                                  //Exception
    std::string pb = "Problem with personal data!";                 //The exact problem
                                                                    
    //Implementing a lambda function to verify if p contains only digits
    auto verfn = [](const std::string &s) {
        for(char c : s)
            if(std::isdigit(c) == 0)
                return 1;
        return 0;
    };

    //Implementing a lambda function to verify if n contains only letters
    auto verfa = [](const std::string &s) {
        for(char c : s)
            if(std::isalpha(c) == 0)
                return 1;
        return 0;
    };

    //Veryfing if both the email address and the phone number are corect
    //Veryfing if the name is corect
    try {
        if(verfa(name)) {
            ex = "Not a real name!\n";
            throw std::runtime_error(pb);
        }
    }
    catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        try {
            throw Exception(ex); 
        } 

        catch(Exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    //Veryfing email address
    try {
        if(email.find("@") == std::string::npos) {
            ex = "Missing '@'.\n";
            throw std::runtime_error(pb);
        }

        if(email.find("com") == std::string::npos || email.find("ro") == std::string::npos) {
            ex = "Mising top-level domain (ex: .com).\n";
            throw std::runtime_error(pb);
        }
    } 

    catch(const std::runtime_error &e) 
    {
        std::cout << e.what() << std::endl;
        try {
            throw Exception(ex); 
        } 

        catch(Exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    //We make multiple try...catch blocks in order to not jump over any error that might occure
    //Veryfing the phone number
    try {
        if (phone.length() != 11) {
            ex = "Phone number too short.\n";
            throw std::runtime_error(pb);
        }

        if(verfn(phone)) {
            ex = "Not a valid phone number.\n";
            throw std::runtime_error(pb);
        }
    }

    catch(const std::runtime_error &e) 
    {
        std::cout << e.what() << std::endl;
        try {
            throw Exception(ex); 
        } 

        catch(Exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
