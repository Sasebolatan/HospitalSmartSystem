#include <iostream>
#include "Hospital.h"

// Main function to test all features of Smart Hospital System
int main() {
    Hospital hospital;

    // Adding patients into the system
    hospital.addPatient(101, "John Doe", "123-456-789");
    hospital.addPatient(102, "Jane Smith", "987-654-321");
    hospital.addPatient(103, "Alice Brown", "111-222-333");

    // Adding treatment records (Linked List usage)
    hospital.addTreatment(101, "Flu Vaccination");
    hospital.addTreatment(101, "Blood Test");
    hospital.addTreatment(102, "MRI Scan");
    hospital.addTreatment(103, "Physical Therapy");

    // Displaying full patient records
    std::cout << "\n--- Initial Patient Records ---\n";
    hospital.displayPatient(101);
    hospital.displayPatient(102);
    hospital.displayPatient(103);

    // Testing Edit (Stack usage for undo)
    hospital.editPatient(101, "John D.", "999-999-999");
    std::cout << "\n--- After Edit ---\n";
    hospital.displayPatient(101);

    // Testing Undo edit operation
    hospital.undoEdit(101);
    std::cout << "\n--- After Undo ---\n";
    hospital.displayPatient(101);

    // Testing Appointment Queue (Queue usage)
    hospital.appointmentQueue.addAppointment(101);
    hospital.appointmentQueue.addAppointment(102);
    hospital.appointmentQueue.addAppointment(103);

    std::cout << "\n--- Appointment Queue ---\n";
    hospital.appointmentQueue.displayQueue();

    hospital.appointmentQueue.processAppointment();
    hospital.appointmentQueue.processAppointment();

    std::cout << "\n--- Queue After Processing ---\n";
    hospital.appointmentQueue.displayQueue();

    // Testing TriageTree (BST usage for critical patients)
    hospital.addToTriage(101, 5);  // Lower score = higher priority
    hospital.addToTriage(102, 15);
    hospital.addToTriage(103, 10);

    std::cout << "\n--- Highest Priority Patient ---\n";
    hospital.getHighestPriorityPatient();

    return 0;
}
