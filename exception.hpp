#ifndef EXCEPTION
#define EXCEPTION

class Exception : public std::exception 
{
public:
    Exception(const std::string &e);
    const char *what();

private:
    std::string error = "Exception ";
    static int numb;
};

#endif // !EXCEPTION
