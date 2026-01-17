# Hospital Management & Triage System

A C++ based Hospital Management System developed for the **Istanbul University CMPE2105 Data Structures and Algorithms** project. This software demonstrates the practical application of STL containers to manage doctors, patient triage, and conflict-free scheduling.

## 📋 Features

* **Doctor & Patient Management:** Registration and lookup using unique string IDs.
* **Smart Scheduling:**
    * Schedule appointments for specific time slots.
    * **Conflict Detection:** Prevents double-booking doctors for the same slot.
* **Priority Triage System:**
    * Patients are assigned urgency levels (e.g., 1=Emergency, 5=Casual).
    * Uses a **Priority Queue** to determine the order of care when calling the next patient.
* **Waitlist Handling:**
    * If a slot is full, patients are added to a waiting list.
    * **Auto-Fill:** When an appointment is canceled, the system automatically promotes the next patient from the waitlist to the confirmed slot.
* **Interactive CLI:** A robust menu system (`menu.h`) handling user inputs and exception safety.

## 🛠 Data Structures

* **`std::map`**: Stores `Doctor` and `Patient` objects for $O(\log n)$ retrieval by ID.
* **`std::priority_queue`**: Manages the `TriageEntry` objects to ensure the highest priority patients are processed first.
* **`std::list`**: Used within `TimeSlotInfo` to manage appointments. Lists were chosen to allow efficient removal of appointments from the middle of the schedule during cancellations.

## 📂 Project Structure

* **`main.cpp`**: Entry point; initializes the system and launches the menu loop.
* **`hospitalsystem.cpp/h`**: The central controller managing the doctor/patient maps and the main triage queue.
* **`doctor.cpp/h`**: Represents medical staff and holds their individual schedules.
* **`schedule.cpp/h`**: Manages the timeline of slots for doctors.
* **`timeslotinfo.cpp`**: handles the specific logic for a single time block (managing confirmed vs. waitlisted patients).
* **`appointment.h`**: Polymorphic base class for `ConfirmedAppointment` and `AppointmentRequest`.
* **`menu.h`**: Handles input validation and console output.

## 🚀 How to Build and Run

### Prerequisites
* A C++ Compiler (GCC, Clang, or MSVC) supporting C++11 or later.

### Compilation
Navigate to the project directory and compile all source files together:

**Using g++ (Linux/Mac/MinGW):**
```bash
g++ main.cpp hospitalsystem.cpp doctor.cpp schedule.cpp timeslotinfo.cpp -o hospital_system
