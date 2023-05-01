#include <iostream>
#include <string>
#include "exception.hpp"

int Exception::numb = 0;

Exception::Exception(const std::string &e)
{
    this->error += std::to_string(++numb) + ": " + e;
}

const char *Exception::what()
{
   return (this->error).c_str();
}
