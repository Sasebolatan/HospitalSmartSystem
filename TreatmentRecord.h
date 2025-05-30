#pragma once
#include <string>

// This class represents a node in a linked list of treatments for each patient.
// Each treatment record stores the treatment details and a pointer to the next record.
class TreatmentRecord {
public:
    std::string treatmentDetails;  // The actual treatment description (e.g. "MRI Scan")
    TreatmentRecord* next;         // Pointer to the next treatment (linked list)

    // Constructor initializes treatment details and sets next to nullptr.
    TreatmentRecord(std::string details) {
        treatmentDetails = details;
        next = nullptr;
    }
};
