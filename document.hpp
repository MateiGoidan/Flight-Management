#ifndef DOCUMENT
#define DOCUMENT

class Document
{
protected:
    Document(std::string t, std::string s, long id, int ed);

private:
    std::string type;
    std::string sex;
    long id;
    int expire_date;
    
};

#endif // !DEBUG
