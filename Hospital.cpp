#include "Hospital.h"
#include <iostream>

// Adds a new patient into the system.
// Uses Hash Table for O(1) lookup and insert.
void Hospital::addPatient(int id, std::string name, std::string contact) {
    if (patientTable.find(id) == patientTable.end()) {
        patientTable[id] = new Patient(id, name, contact);
        std::cout << "Patient added successfully.\n";
    }
    else {
        std::cout << "Patient ID already exists.\n";
    }
}

// Displays full information for one patient
void Hospital::displayPatient(int id) {
    if (patientTable.find(id) != patientTable.end()) {
        patientTable[id]->display();
    }
    else {
        std::cout << "Patient not found.\n";
    }
}

// Adds a treatment record to a patient
void Hospital::addTreatment(int id, std::string treatment) {
    if (patientTable.find(id) != patientTable.end()) {
        patientTable[id]->addTreatment(treatment);
    }
}

// Allows staff to update patient details while saving history for undo
void Hospital::editPatient(int id, std::string name, std::string contact) {
    if (patientTable.find(id) != patientTable.end()) {
        patientTable[id]->editInfo(name, contact);
    }
}

// Undo last patient edit by popping the top EditRecord off the stack
void Hospital::undoEdit(int id) {
    if (patientTable.find(id) != patientTable.end()) {
        patientTable[id]->undoEdit();
    }
}

// Inserts patient into triage system (BST) with a given priority score
void Hospital::addToTriage(int id, int priorityScore) {
    if (patientTable.find(id) != patientTable.end()) {
        triageTree.insert(patientTable[id], priorityScore);
        std::cout << "Patient added to triage.\n";
    }
}

// Finds and displays patient with highest priority from triage (lowest score)
void Hospital::getHighestPriorityPatient() {
    Patient* patient = triageTree.getHighestPriority();
    if (patient != nullptr) {
        std::cout << "Highest priority patient: \n";
        patient->display();
    }
    else {
        std::cout << "No patients in triage.\n";
    }
}
