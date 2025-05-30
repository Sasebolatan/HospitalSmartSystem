#include "Patient.h"
#include <iostream>

// Constructor assigns initial patient details
Patient::Patient(int id, std::string name, std::string contact) {
    ID = id;
    Name = name;
    ContactInfo = contact;
    treatmentHead = nullptr;
}

// Add a new treatment to the patient's history (linked list insertion at head O(1))
void Patient::addTreatment(std::string treatment) {
    TreatmentRecord* newRecord = new TreatmentRecord(treatment);
    newRecord->next = treatmentHead;
    treatmentHead = newRecord;
}

// Display all treatments in the linked list
void Patient::displayTreatments() {
    std::cout << "  Treatments:\n";
    TreatmentRecord* current = treatmentHead;
    while (current != nullptr) {
        std::cout << "   - " << current->treatmentDetails << std::endl;
        current = current->next;
    }
}

// Edit patient details while saving previous state onto stack for undo
void Patient::editInfo(std::string newName, std::string newContact) {
    editHistory.push(EditRecord(Name, ContactInfo));
    Name = newName;
    ContactInfo = newContact;
}

// Undo last edit by popping from the editHistory stack
void Patient::undoEdit() {
    if (!editHistory.empty()) {
        EditRecord lastEdit = editHistory.top();
        editHistory.pop();
        Name = lastEdit.previousName;
        ContactInfo = lastEdit.previousContact;
    }
}

// Display full patient record including treatment history
void Patient::display() {
    std::cout << "ID: " << ID << " Name: " << Name << " Contact: " << ContactInfo << std::endl;
    displayTreatments();
}
