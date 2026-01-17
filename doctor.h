// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#pragma once

#include "appointment.h"
#include "schedule.h"
#include <iostream>
#include <string>

class Doctor {
private:
  std::string ID;
  std::string name;
  std::string speciality;
  Schedule schedule;

public:
  Doctor(std::string ID, std::string name, std::string speciality)
      : ID(ID), name(name), speciality(speciality) {}
  void printSchedule() const;
  std::string getName() const;
  std::string getID() const;
  std::string getSpeciality() const;
  Appointment *cancelAppointment(std::string &patientID, std::string &timeSlot);
  void listAppointments(std::string &timeSlot);
  bool scheduleAppointment(std::string &patientID, unsigned short priorityLevel,
                           std::string &timeSlot);
  unsigned short getPatientPriorityLevel(std::string &patientID,
                                         std::string &timeSlot);
  void printPatientAppointments(std::string &patientID) const;
};
