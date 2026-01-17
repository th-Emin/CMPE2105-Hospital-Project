// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#pragma once

#include "appointment.h"
#include <iostream>
#include <list>
#include <map>
#include <string>

class TimeSlotInfo {
private:
  std::string timeSlot;
  unsigned short capacity;
  std::list<ConfirmedAppointment> appointments;
  std::list<AppointmentRequest> waitList; 
  // I used list instead of queue, so program can search and remove a specific patient easily

public:
  TimeSlotInfo(std::string timeSlot, unsigned short capacity = 3)
      : timeSlot(timeSlot), capacity(capacity) {}
  void print() const;
  void listAppointments() const;
  Appointment *cancelAppointment(std::string &patientID);
  bool scheduleAppointment(std::string &patientID,
                           unsigned short priorityLevel);
  unsigned short getPatientPriorityLevel(std::string &patientID) const;
  void printPatientAppointments(std::string &patientID) const;

  void addToWaitList(std::string &patientID, unsigned short priorityLevel);
  Appointment *popFromWaitingList();

  bool isFull() const { return appointments.size() >= capacity; }
};

class Schedule {
private:
  std::map<std::string, TimeSlotInfo> timeSlots;

public:
  Schedule() {}
  void addTimeSlot(const std::string &timeSlot, unsigned short capacity = 3);
  void print() const;
  void listAppointments(std::string &timeSlot) const;
  Appointment *cancelAppointment(std::string &patientID, std::string &timeSlot);
  bool scheduleAppointment(std::string &patientID, unsigned short priorityLevel,
                           std::string &timeSlot);
  unsigned short getPatientPriorityLevel(std::string &patientID,
                                         std::string &timeSlot) const;
  void printPatientAppointments(std::string &patientID) const;
};
