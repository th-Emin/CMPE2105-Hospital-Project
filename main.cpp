// This program is written for Istanbul University CMPE2105 DATA STRUCTURES AND ALGORITHMS project.

#include "hospitalsystem.h"
#include "menu.h"
#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
  HospitalSystem esnafHospital;
  bool exit{};
  while (!exit) {
    unsigned short selection{};
    std::cout << std::endl;
    std::cout << std::endl << "===== Main Menu =====" << std::endl;
    std::cout << "1. Add doctor" << std::endl;
    std::cout << "2. List all doctors" << std::endl;
    std::cout << "3. View doctor schedule" << std::endl;
    std::cout << "4. Schedule appointment" << std::endl;
    std::cout << "5. Cancel appointment" << std::endl;
    std::cout << "6. List appointments for a doctor and time slot" << std::endl;
    std::cout << "7. Call next patient (triage)" << std::endl;
    std::cout << "8. Find patient appointments" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl << "Enter your selection (0-8): ";

    try {
      if (!(std::cin >> selection)) {
        std::cerr << "ERROR: Invalid input, expected an integer" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      switch (selection) {
      case 0: 
        exit = true;
        break;
      case 1:
        addDoctor(esnafHospital);
        break;
      case 2:
        listAllDoctors(esnafHospital);
        break;
      case 3:
        viewDoctorSchedule(esnafHospital);
        break;
      case 4:
        scheduleAppointment(esnafHospital);
        break;
      case 5:
        cancelAppointment(esnafHospital);
        break;
      case 6:
        listAppointments(esnafHospital);
        break;
      case 7:
        callNextPatient(esnafHospital);
        break;
      case 8:
        printPatientAppointments(esnafHospital);
        break;
      default:
        std::cerr << "ERROR: Selection out of range (0-8)." << std::endl;
        break;
      }
    } catch (std::exception &e) {
      std::cerr << "ERROR: " << e.what() << std::endl;
    }
  }
  return 0;
}
