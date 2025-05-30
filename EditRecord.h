#pragma once
#include <string>

// This class is used for undo functionality.
// It stores the previous state of patient information for rollback purposes.
class EditRecord {
public:
    std::string previousName;      // The patient's previous name
    std::string previousContact;   // The patient's previous contact information

    // Constructor saves the previous state when an edit happens.
    EditRecord(std::string name, std::string contact) {
        previousName = name;
        previousContact = contact;
    }
};