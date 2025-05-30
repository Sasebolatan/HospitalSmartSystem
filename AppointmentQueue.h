#pragma once
#include <queue>

// AppointmentQueue manages patient appointments using FIFO queue.
// Patients wait in order of arrival.
class AppointmentQueue {
public:
    std::queue<int> appointments;  // Queue holds patient IDs (not full Patient objects)

    // Add a new appointment by adding patient ID to the queue
    void addAppointment(int patientID);

    // Process (remove) the next patient in queue for their appointment
    void processAppointment();

    // Display current state of the appointment queue
    void displayQueue();
};
