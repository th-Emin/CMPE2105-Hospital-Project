// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#pragma once

#include <iostream>
#include <string>

class Appointment {
private:
  std::string patientID;
  unsigned short priorityLevel;

public:
  Appointment(const std::string &patientID, unsigned short priorityLevel)
      : patientID(patientID), priorityLevel(priorityLevel) {}
  void print() const {
    std::cout << patientID << " (" << priorityLevel << ")" << std::endl;
  }
  virtual bool isConfirmed() const = 0;
  unsigned short getPriorityLevel() const { return priorityLevel; }
  std::string getPatientID() const { return patientID; }
};

class ConfirmedAppointment : public Appointment {
public:
  ConfirmedAppointment(const std::string &patientID,
                       unsigned short priorityLevel)
      : Appointment(patientID, priorityLevel) {}
  bool isConfirmed() const override final { return true; }
};

class AppointmentRequest : public Appointment {
public:
  AppointmentRequest(const std::string &patientID, unsigned short priorityLevel)
      : Appointment(patientID, priorityLevel) {}
  bool isConfirmed() const override final { return false; }
};
