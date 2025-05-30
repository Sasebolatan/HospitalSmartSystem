#pragma once
#include "PatientPriority.h"

// TriageTree implements Binary Search Tree (BST) to manage patient priorities for emergencies.
class TriageTree {
private:
    PatientPriority* root;  // Root node of BST

    // Recursive insertion helper
    PatientPriority* insertRecursive(PatientPriority* node, Patient* patient, int score) {
        if (node == nullptr)
            return new PatientPriority(patient, score);
        if (score < node->priorityScore)
            node->left = insertRecursive(node->left, patient, score);
        else
            node->right = insertRecursive(node->right, patient, score);
        return node;
    }

    // Recursive helper to locate highest priority patient (lowest score = leftmost node)
    PatientPriority* getHighestPriorityRecursive(PatientPriority* node) {
        if (node == nullptr) return nullptr;
        if (node->left == nullptr) return node;
        return getHighestPriorityRecursive(node->left);
    }

public:
    // Constructor initializes empty tree
    TriageTree() { root = nullptr; }

    // Public insert interface
    void insert(Patient* patient, int score) {
        root = insertRecursive(root, patient, score);
    }

    // Retrieve patient with highest priority
    Patient* getHighestPriority() {
        PatientPriority* result = getHighestPriorityRecursive(root);
        return (result != nullptr) ? result->patient : nullptr;
    }
};
