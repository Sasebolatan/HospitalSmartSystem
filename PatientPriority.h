#pragma once
#include "Patient.h"

// PatientPriority nodes represent nodes inside our Binary Search Tree (TriageTree).
class PatientPriority {
public:
    Patient* patient;         // Pointer to the patient object
    int priorityScore;        // Lower score means higher priority
    PatientPriority* left;    // Left child node (lower priorityScore)
    PatientPriority* right;   // Right child node (higher priorityScore)

    // Constructor initializes node
    PatientPriority(Patient* pat, int score) {
        patient = pat;
        priorityScore = score;
        left = nullptr;
        right = nullptr;
    }
};
