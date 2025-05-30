#pragma once
#include <unordered_map>
#include "Patient.h"
#include "AppointmentQueue.h"
#include "TriageTree.h"

// The Hospital class coordinates all subsystems:
// patient storage (hash table), appointment management (queue), and emergency triage (BST).
class Hospital {
public:
    std::unordered_map<int, Patient*> patientTable;  // Hash Table for fast patient ID lookup
    AppointmentQueue appointmentQueue;               // Queue for managing appointments
    TriageTree triageTree;                           // Binary Search Tree for patient triage priorities

    // Methods for core hospital functionality:
    void addPatient(int id, std::string name, std::string contact);
    void displayPatient(int id);
    void addTreatment(int id, std::string treatment);
    void editPatient(int id, std::string name, std::string contact);
    void undoEdit(int id);
    void addToTriage(int id, int priorityScore);
    void getHighestPriorityPatient();
};
