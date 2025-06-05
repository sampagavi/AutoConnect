/*#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    int id;
    std::string name;
    std::string contact;

    User(int _id, std::string _name, std::string _contact);
};

#endif*/
#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    int id;
    std::string name;
    std::string contact;

    User(int _id, const std::string& _name, const std::string& _contact);
};

#endif 
