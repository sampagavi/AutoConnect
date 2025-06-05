/*#include "User.h"

User::User(const std::string& name, int id) : name(name), id(id) {}

std::string User::getName() const {
    return name;
}

int User::getId() const {
    return id;
}*/

#include "User.h"

User::User(int _id, const std::string& _name, const std::string& _contact)
    : id(_id), name(_name), contact(_contact) {}
