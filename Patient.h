#pragma once
#include <string>
#include <stack>
#include "TreatmentRecord.h"
#include "EditRecord.h"

// This class represents each patient in the hospital system.
// It stores personal data, treatment history, and edit history for undo support.
class Patient {
public:
    int ID;                        // Unique patient identifier
    std::string Name;              // Patient's name
    std::string ContactInfo;       // Contact details
    TreatmentRecord* treatmentHead; // Head of linked list for treatments
    std::stack<EditRecord> editHistory; // Stack to store previous versions for undo

    // Constructor initializes patient info and sets treatment head to null.
    Patient(int id, std::string name, std::string contact);

    // Methods to manage treatment records and patient info
    void addTreatment(std::string treatment);
    void displayTreatments();
    void editInfo(std::string newName, std::string newContact);
    void undoEdit();
    void display();
};
