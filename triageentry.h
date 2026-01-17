// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#pragma once

#include <string>

class TriageEntry {
private:
  std::string doctorID;
  std::string patientID;
  std::string timeSlot;
  unsigned short priorityLevel;
  unsigned order;

public:
  TriageEntry(const std::string &doctorID, const std::string &patientID,
              const std::string &timeSlot, unsigned short priorityLevel,
              unsigned order)
      : doctorID(doctorID), patientID(patientID), timeSlot(timeSlot),
        priorityLevel(priorityLevel), order(order) {}
  //Overloading < operator for priority queue
  bool operator<(const TriageEntry &other) const { 
    if (priorityLevel != other.priorityLevel)
      return priorityLevel > other.priorityLevel;
    return order > other.order;
  }
  std::string getPatientID() const { return patientID; }
  unsigned short getPatientPriorityLevel() const { return priorityLevel; }
  std::string getDoctorID() const { return doctorID; }
  std::string getTimeSlot() const { return timeSlot; }
};
