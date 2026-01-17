// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#include "doctor.h"
#include "appointment.h"
#include "patient.h"
#include "schedule.h"
#include <iostream>
#include <string>

void Doctor::printSchedule() const {
  std::cout << "Dr. " << name << " (" << speciality << ")" << std::endl;
  schedule.print();
}
std::string Doctor::getName() const { return name; }
std::string Doctor::getID() const { return ID; }
std::string Doctor::getSpeciality() const { return speciality; }
Appointment *Doctor::cancelAppointment(std::string &patientID,
                                       std::string &timeSlot) {
  return schedule.cancelAppointment(patientID, timeSlot);
}
void Doctor::listAppointments(std::string &timeSlot) {
  schedule.listAppointments(timeSlot);
}
bool Doctor::scheduleAppointment(std::string &patientID,
                                 unsigned short priorityLevel,
                                 std::string &timeSlot) {
  return schedule.scheduleAppointment(patientID, priorityLevel, timeSlot);
}
unsigned short Doctor::getPatientPriorityLevel(std::string &patientID,
                                               std::string &timeSlot) {
  return schedule.getPatientPriorityLevel(patientID, timeSlot);
}
void Doctor::printPatientAppointments(std::string &patientID) const {
  std::cout << "Dr. " << name << " (" << speciality << ")" << std::endl;
  schedule.printPatientAppointments(patientID);
}
