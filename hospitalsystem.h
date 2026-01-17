// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#pragma once

#include "appointment.h"
#include "doctor.h"
#include "patient.h"
#include "triageentry.h"
#include <iostream>
#include <map>
#include <queue>
#include <string>

class HospitalSystem {
private:
  std::map<std::string, Doctor> doctors;
  std::map<std::string, Patient> patients;
  std::priority_queue<TriageEntry> triageEntries;
  unsigned triageOrderCounter;

public:
  HospitalSystem() : triageOrderCounter(0) {}
  void addDoctor(std::string &doctorID, std::string &name,
                 std::string &speciality);
  void printDoctors() const;
  void viewDoctorSchedule(const std::string &doctorID) const;
  bool scheduleAppointment(std::string &patientID, unsigned short priorityLevel,
                           std::string &doctorID, std::string &timeSlot);
  std::string cancelAppointment(std::string &patientID, std::string &doctorID,
                                std::string &timeSlot);
  void createPatient(std::string &patientID, std::string &patientName);
  void listAppointments(std::string &doctorID, std::string &timeSlot);
  void callNextPatient();
  void printPatientAppointments(std::string &patientID) const;

  bool hasDoctor(const std::string &doctorID) const;
  std::string getDoctorName(const std::string &doctorID) const;
  bool hasPatient(const std::string &patientID) const;
  std::string getPatientName(const std::string &patientID) const;

  static bool checkTimeSlotSyntax(const std::string &timeSlot);
};
