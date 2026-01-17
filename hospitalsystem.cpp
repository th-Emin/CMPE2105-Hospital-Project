// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#include "hospitalsystem.h"
#include "appointment.h"
#include "doctor.h"
#include "patient.h"
#include "triageentry.h"
#include <iostream>
#include <map>
#include <queue>
#include <string>

void HospitalSystem::addDoctor(std::string &doctorID, std::string &name,
                               std::string &speciality) {
  Doctor newDoctor(doctorID, name, speciality);
  doctors.insert({doctorID, newDoctor});
}

void HospitalSystem::printDoctors() const {
  for (auto i : doctors) {
    const Doctor &doctor = i.second;
    std::cout << doctor.getID() << " - " << doctor.getName() << " ("
              << doctor.getSpeciality() << ")" << std::endl;
  }
}

void HospitalSystem::viewDoctorSchedule(const std::string &doctorID) const {
  return doctors.at(doctorID).printSchedule();
}

bool HospitalSystem::scheduleAppointment(std::string &patientID,
                                         unsigned short priorityLevel,
                                         std::string &doctorID,
                                         std::string &timeSlot) {
  bool appointment = doctors.at(doctorID).scheduleAppointment(
      patientID, priorityLevel, timeSlot);
  if (appointment) {
    TriageEntry entry(doctorID, patientID, timeSlot, priorityLevel,
                      triageOrderCounter++);
    triageEntries.push(entry);
  }
  return appointment;
}

std::string HospitalSystem::cancelAppointment(std::string &patientID,
                                              std::string &doctorID,
                                              std::string &timeSlot) {
  std::priority_queue<TriageEntry> triageTemp = triageEntries;
  while(triageEntries.empty()){
      const TriageEntry& top = triageEntries.top();
      if(top.getPatientID() == patientID && top.getDoctorID() == doctorID &&
         top.getTimeSlot() == timeSlot) {
          triageEntries.pop();
          continue;
      }
      triageTemp.push(top);
      triageEntries.pop();
  }
  Appointment *waited =
      doctors.at(doctorID).cancelAppointment(patientID, timeSlot);
  if (waited) {
    unsigned short priorityLevel = waited->getPriorityLevel();
    TriageEntry entry(doctorID, waited->getPatientID(), timeSlot, priorityLevel,
                      triageOrderCounter++);
    triageEntries.push(entry);
    return waited->getPatientID();
  }
  return "";
}

void HospitalSystem::createPatient(std::string &patientID,
                                   std::string &patientName) {
  Patient newPatient(patientID, patientName);
  patients.insert({patientID, newPatient});
}

void HospitalSystem::listAppointments(std::string &doctorID,
                                      std::string &timeSlot) {
  doctors.at(doctorID).listAppointments(timeSlot);
}

bool HospitalSystem::hasDoctor(const std::string &doctorID) const {
  return doctors.count(doctorID);
}

std::string HospitalSystem::getDoctorName(const std::string &doctorID) const {
  return doctors.at(doctorID).getName();
}

bool HospitalSystem::hasPatient(const std::string &patientID) const {
  return patients.count(patientID);
}

std::string HospitalSystem::getPatientName(const std::string &patientID) const {
  return patients.at(patientID).getName();
}

void HospitalSystem::callNextPatient() {
  if (triageEntries.empty()) {
    std::cerr << "ERROR: There is no next patient!" << std::endl;
    return;
  }
  std::cout << "Next patient: " << std::endl;
  TriageEntry top = triageEntries.top();
  std::cout << "Patient ID: " << top.getPatientID() << std::endl;
  std::cout << "Name: " << patients.at(top.getPatientID()).getName()
            << std::endl;
  std::cout << "Priority: " << top.getPatientPriorityLevel() << std::endl;
  std::cout << "Doctor: " << top.getDoctorID() << std::endl;
  std::cout << "Time slot: " << top.getTimeSlot() << std::endl;
  triageEntries.pop();
}

void HospitalSystem::printPatientAppointments(std::string &patientID) const {
  for (const auto &[id, doctor] : doctors) {
    std::cout << "Doctor name: " << doctor.getName() << std::endl;
    doctor.printPatientAppointments(patientID);
  }
}

bool HospitalSystem::checkTimeSlotSyntax(const std::string &timeSlot) {
  if (timeSlot.size() != 5)
    return false;
  if (timeSlot[0] < '0' || timeSlot[0] > '2')
    return false;
  if (timeSlot[1] < '0' || timeSlot[1] > '9')
    return false;
  if (timeSlot[0] == '2' && timeSlot[1] > '3')
    return false;
  if (timeSlot[2] != ':')
    return false;
  if (timeSlot[3] < '0' || timeSlot[3] > '5')
    return false;
  if (timeSlot[4] < '0' || timeSlot[4] > '9')
    return false;
  return true;
}
