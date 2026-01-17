// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#include "schedule.h"
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>

void Schedule::addTimeSlot(const std::string &timeSlot,
                           unsigned short capacity) {
  TimeSlotInfo timeSlotInfo(timeSlot, capacity);
  timeSlots.insert({timeSlot, timeSlotInfo});
}
void Schedule::print() const {
  for (auto const &[key, timeSlot] : timeSlots) {
    timeSlot.print();
  }
}
void Schedule::listAppointments(std::string &timeSlot) const {
  if (timeSlots.find(timeSlot) != timeSlots.end()) {
    timeSlots.at(timeSlot).listAppointments();
  }
}
Appointment *Schedule::cancelAppointment(std::string &patientID,
                                         std::string &timeSlot) {
  if (timeSlots.find(timeSlot) == timeSlots.end()) {
    return nullptr;
  }
  return timeSlots.at(timeSlot).cancelAppointment(patientID);
}

bool Schedule::scheduleAppointment(std::string &patientID,
                                   unsigned short priorityLevel,
                                   std::string &timeSlot) {
  if (timeSlots.find(timeSlot) == timeSlots.end()) {
    addTimeSlot(timeSlot);
  }
  return timeSlots.at(timeSlot).scheduleAppointment(patientID, priorityLevel);
}
unsigned short Schedule::getPatientPriorityLevel(std::string &patientID,
                                                 std::string &timeSlot) const {
  if (timeSlots.find(timeSlot) == timeSlots.end()) {
    return 0;
  }
  return timeSlots.at(timeSlot).getPatientPriorityLevel(patientID);
}
void Schedule::printPatientAppointments(std::string &patientID) const {
  for (auto const &[key, timeSlot] : timeSlots) {
    timeSlot.printPatientAppointments(patientID);
  }
}
