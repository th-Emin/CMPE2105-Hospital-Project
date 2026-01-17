// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#pragma once
#include "hospitalsystem.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

void addDoctor(HospitalSystem &hospital) {
  std::string doctorID, name, speciality;
  std::cout << "Enter doctor ID: ";
  std::cin >> doctorID;
  if (hospital.hasDoctor(doctorID)) {
    std::cerr << "ERROR: Given ID is allready taken by \""
              << hospital.getDoctorName(doctorID) << "\"." << std::endl;
    return;
  }
  std::cout << "Enter doctor name: ";
  std::getline(std::cin >> std::ws, name);
  std::cout << "Enter speciality: ";
  std::cin >> speciality;
  hospital.addDoctor(doctorID, name, speciality);
  std::cout << "Doctor " << doctorID << " added";
}
void listAllDoctors(HospitalSystem &hospital) { hospital.printDoctors(); }
void viewDoctorSchedule(HospitalSystem &hospital) {
  std::string doctorID;
  std::cout << "Enter doctor ID: ";
  std::cin >> doctorID;
  if (!hospital.hasDoctor(doctorID)) {
    std::cerr << "ERROR: Given ID is not found.";
    return;
  }
  hospital.viewDoctorSchedule(doctorID);
}
void scheduleAppointment(HospitalSystem &hospital) {
  std::string patientID, doctorID, timeSlot;
  unsigned short priorityLevel;
  std::cout << "Enter patient ID: ";
  if (hospital.hasPatient(patientID)) {
    std::cout << "Patient found on database." << std::endl;
    std::cout << "Name:  \"" << hospital.getPatientName(patientID) << std::endl;
  } else {
    std::string patientName;
    std::cout << "Enter patient name: ";
    std::getline(std::cin >> std::ws, patientName);
    hospital.createPatient(patientID, patientName);
  }
  std::cout << "Enter doctor ID: ";
  std::cin >> doctorID;
  if (!hospital.hasDoctor(doctorID)) {
    std::cerr << "ERROR: Given ID is not found." << std::endl;
    return;
  }
  std::cout << "Enter priority level (e.g. 1 (emergency), 5 (casual)): ";
  std::cin >> priorityLevel;
  while (!(std::cin >> priorityLevel)) {
    std::cerr << "ERROR: Invalid input, expected an integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter priority level (e.g. 1 (emergency), 5 (casual)): ";
    std::cin >> priorityLevel;
  }
  std::cout << "Enter time slot (e.g. 09:00): ";
  std::cin >> timeSlot;
  while (!HospitalSystem::checkTimeSlotSyntax(timeSlot)) {
    std::cerr << "ERROR: Invalid input, expected a time format (e.g. 09:30)!"
              << std::endl;
    std::cout << "Enter time slot (e.g. 09:30): ";
    std::cin >> timeSlot;
  }
  bool succes = hospital.scheduleAppointment(patientID, priorityLevel, doctorID,
                                             timeSlot);
  if (succes)
    std::cout << "Appointment scheduled for"
              << hospital.getPatientName(patientID) << " with Dr. "
              << hospital.getDoctorName(doctorID) << " at " << timeSlot << "."
              << std::endl;
  else
    std::cout << "Time slot full. " << hospital.getPatientName(patientID)
              << "added to waiting list for "
              << hospital.getDoctorName(doctorID) << " at " << timeSlot << "."
              << std::endl;
}

void cancelAppointment(HospitalSystem &hospital) {
  std::string patientID, doctorID, timeSlot;
  std::cout << "Enter patient ID: ";
  std::cin >> patientID;
  if (!hospital.hasPatient(patientID)) {
    std::cerr << "ERROR: Given ID is not found." << std::endl;
    return;
  }
  std::cout << "Enter doctor ID: ";
  std::cin >> doctorID;
  if (!hospital.hasDoctor(doctorID)) {
    std::cerr << "ERROR: Given ID is not found." << std::endl;
    return;
  }
  std::cout << "Enter time slot (e.g. 09:30): ";
  std::cin >> timeSlot;
  while (!HospitalSystem::checkTimeSlotSyntax(timeSlot)) {
    std::cerr << "ERROR: Invalid input, expected a time format (e.g. 09:30)!"
              << std::endl;
    std::cout << "Enter time slot (e.g. 09:30): ";
    std::cin >> timeSlot;
  }
  std::string moved = hospital.cancelAppointment(patientID, doctorID, timeSlot);
  std::cout << "Appointment for " << patientID << " at " << timeSlot
            << " with Dr. " << doctorID << " canceled." << std::endl;
  if (!moved.empty())
    std::cout << moved
              << " moved from waiting list to confirmed appointment at "
              << timeSlot << std::endl;
}

void listAppointments(HospitalSystem &hospital) {
  std::string doctorID, timeSlot;
  std::cout << "Enter doctor ID: ";
  std::cin >> doctorID;
  if (!hospital.hasDoctor(doctorID)) {
    std::cerr << "ERROR: Given ID is not found." << std::endl;
    return;
  }
  std::cout << "Enter time slot (e.g. 09:30): ";
  std::cin >> timeSlot;
  while (!HospitalSystem::checkTimeSlotSyntax(timeSlot)) {
    std::cerr << "ERROR: Invalid input, expected a time format (e.g. 09:30)!"
              << std::endl;
    std::cout << "Enter time slot (e.g. 09:30): ";
    std::cin >> timeSlot;
  }
  hospital.listAppointments(doctorID, timeSlot);
}

void callNextPatient(HospitalSystem &hospital) {
  std::cout << "Calling next Patient..." << std::endl;
  hospital.callNextPatient();
}

void printPatientAppointments(HospitalSystem &hospital) {
  std::string patientID;
  std::cout << "Enter patient ID: ";
  std::cin >> patientID;
  if (!hospital.hasPatient(patientID)) {
    std::cerr << "ERROR: Given ID is not found." << std::endl;
    return;
  }
  hospital.printPatientAppointments(patientID);
}
