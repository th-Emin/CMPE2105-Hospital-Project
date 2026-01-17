// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#pragma once

#include <string>

class Patient {
private:
  std::string ID;
  std::string name;

public:
  Patient(std::string &ID, std::string &name) : ID(ID), name(name) {}
  std::string getName() const { return name; }
};
