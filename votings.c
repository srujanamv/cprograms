#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define CANDIDATES 3

// Hash table to store voter IDs (cache)
int hashTable[TABLE_SIZE];

// Vote count for candidates
int votes[CANDIDATES] = {0};

// Initialize hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;   // -1 means empty
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Search voter ID in cache
int searchVoter(int voterID) {
    int index = hashFunction(voterID);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int newIndex = (index + i) % TABLE_SIZE;

        if (hashTable[newIndex] == voterID) {
            return 1; // Voter already voted
        }
        if (hashTable[newIndex] == -1) {
            return 0; // Voter not found
        }
    }
    return 0;
}

// Insert voter ID into cache
void insertVoter(int voterID) {
    int index = hashFunction(voterID);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int newIndex = (index + i) % TABLE_SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = voterID;
            return;
        }
    }
}

// Cast vote
void castVote() {
    int voterID, choice;

    printf("\nEnter Voter ID: ");
    scanf("%d", &voterID);

    // Check cache
    if (searchVoter(voterID)) {
        printf("You have already voted!\n");
        return;
    }

    printf("\nCandidates:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > CANDIDATES) {
        printf(" Invalid choice!\n");
        return;
    }

    votes[choice - 1]++;
    insertVoter(voterID);

    printf(" Vote cast successfully!\n");
}

// Display results
void displayResults() {
    printf("\n Voting Results:\n");
    printf("Candidate A: %d votes\n", votes[0]);
    printf("Candidate B: %d votes\n", votes[1]);
    printf("Candidate C: %d votes\n", votes[2]);
}

// Main function
int main() {
    int option;
    initHashTable();

    do {
        printf("\n--- Online Voting System ---\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                castVote();
                break;
            case 2:
                displayResults();
                break;
            case 3:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 3);

    return 0;
}