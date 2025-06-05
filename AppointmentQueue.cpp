#include "AppointmentQueue.h"
#include <iostream>

// Enqueue a patient for an appointment
void AppointmentQueue::addAppointment(int patientID) {
    appointments.push(patientID);
}

// Dequeue and process the next patient in line
void AppointmentQueue::processAppointment() {
    if (!appointments.empty()) {
        std::cout << "Processing appointment for Patient ID: " << appointments.front() << std::endl;
        appointments.pop();
    }
    else {
        std::cout << "No appointments in queue.\n";
    }
}

// Display all patients currently waiting for appointments
void AppointmentQueue::displayQueue() {
    std::queue<int> temp = appointments;  // Create a copy to safely iterate through queue
    std::cout << "Current Appointments Queue: ";
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}
