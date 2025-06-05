#include "User.h"

User::User(const std::string& name, int id) : name(name), id(id) {}

std::string User::getName() const {
    return name;
}

int User::getId() const {
    return id;
}
