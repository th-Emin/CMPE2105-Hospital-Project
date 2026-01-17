// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#include "schedule.h"
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stdexcept>
#include <string>

void TimeSlotInfo::print() const {
  std::cout << "Time: " << timeSlot << std::endl;
  std::cout << "Confirmed Appointments: " << std::endl;
  for (const ConfirmedAppointment &appointment : appointments) {
    appointment.print();
  }
  std::cout << "Waiting List: " << std::endl;
  for (const AppointmentRequest &waiting : waitList) {
    waiting.print();
  }
}

void TimeSlotInfo::listAppointments() const {
  std::cout << "Time: " << timeSlot << std::endl;
  std::cout << "Confirmed Appointments: " << std::endl;
  for (const ConfirmedAppointment &appointment : appointments) {
    appointment.print();
  }
}

Appointment *TimeSlotInfo::cancelAppointment(std::string &patientID) {
  bool isCanceled{};
  std::list<ConfirmedAppointment> a;
  for (ConfirmedAppointment &appointment : appointments) {
    if (appointment.getPatientID() == patientID) {
      isCanceled = true;
      continue;
    }
    a.push_back(appointment);
  }
  if (!isCanceled)
    throw std::runtime_error(
        "Patient ID not found, appointment cannot canceled");
  appointments = a;
  return popFromWaitingList();
}

bool TimeSlotInfo::scheduleAppointment(std::string &patientID,
                                       unsigned short priorityLevel) {
  if (isFull()) {
    addToWaitList(patientID, priorityLevel);
    return false;
  }
  ConfirmedAppointment appointment(patientID, priorityLevel);
  appointments.push_back(appointment);
  return true;
}
unsigned short
TimeSlotInfo::getPatientPriorityLevel(std::string &patientID) const {
  for (const ConfirmedAppointment &appointment : appointments) {
    if (appointment.getPatientID() == patientID) {
      return appointment.getPriorityLevel();
    }
  }
  for (const AppointmentRequest &appointment : waitList) {
    if (appointment.getPatientID() == patientID) {
      return appointment.getPriorityLevel();
    }
  }
  throw std::runtime_error("Patient ID not found on appointment list! Cannot "
                           "return priority level!");
}

void TimeSlotInfo::printPatientAppointments(std::string &patientID) const {
  std::cout << "Confirmed Appointments: " << std::endl;
  for (const ConfirmedAppointment &appointment : appointments) {
    if (appointment.getPatientID() == patientID) {
      appointment.print();
    }
  }
  std::cout << "Waiting List: " << std::endl;
  for (const AppointmentRequest &appointment : waitList) {
    if (appointment.getPatientID() == patientID) {
      appointment.print();
    }
  }
}

void TimeSlotInfo::addToWaitList(std::string &patientID,
                                 unsigned short priorityLevel) {
  AppointmentRequest appointment(patientID, priorityLevel);
  waitList.push_back(appointment);
}
Appointment *TimeSlotInfo::popFromWaitingList() {
  if (isFull())
    throw std::runtime_error(
        "Appointment List is full! Cannot pop from Waiting List!");
  if (waitList.empty())
    return nullptr;
  AppointmentRequest &next = waitList.front();
  ConfirmedAppointment added(next.getPatientID(), next.getPriorityLevel());
  appointments.push_back(added);
  waitList.pop_front();
  return &appointments.back();
}
