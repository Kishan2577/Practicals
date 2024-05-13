// Telephone book management: Consider the telephone book database of 
// N clients. Write a menu driven C++ program to make use of a hash table 
// implementation to quickly look up a client's telephone number. Use of 
// two collision handling techniques and compare them using number of 
// comparisons required to find a set of telephone number

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
using namespace std;

// Function to print the hash table
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout <<i<< "-\t"<< arr[i] << " \t";
    }
    cout << endl;
}

// Function to implement linear probing
void linearProbing(int table[], int tsize, int key, int& collisions) {
    int hv = key % tsize;
    if (table[hv] == -1)
        table[hv] = key;
    else {
        int j = (hv + 1) % tsize;
        while (table[j] != -1) {
            j = (j + 1) % tsize;
            collisions++; // Increment collision count
        }
        table[j] = key;
    }
}

// Function to implement quadratic probing
void quadraticProbing(int table[], int tsize, int key, int& collisions) {
    int hv = key % tsize;
    if (table[hv] == -1) {
        table[hv] = key; // If the slot is empty, insert the key directly
    } else {
        // Quadratic probing
        int j = 1;
        int original_hv = hv; // Save the original hash value for cycling
        while (true) {
            hv = (original_hv + j * j) % tsize; // Calculate the new slot
            if (table[hv] == -1) {
                table[hv] = key; // If the slot is empty, insert the key
                break;
            }
            collisions++;
            j++; // Increment j by increasing squares of integers
        }
    }
}

int main() {
    int hash_table[100]; // Hash table to store telephone numbers
    int choice;
    long int key;
    int tsize;
    int collisions = 0; // Variable to store collision count

    cout << "Enter the size of the data base: ";
    cin >> tsize;
    
    // Initializing the hash table
    for (int i = 0; i < tsize; i++) {
        hash_table[i] = -1;
    }

    cout << "Choose probing method:" << endl;
    cout << "1. Linear Probing" << endl;
    cout << "2. Quadratic Probing" << endl;
    cout << "3. Exit!"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter telephone numbers to insert (enter -1 to stop):" << endl;
            while (true) {
                cin >> key;
                if (key == -1)
                    break;
                linearProbing(hash_table, tsize, key, collisions);
            }
            cout << "Table after insertion:" << endl;
            printArray(hash_table, tsize);
            cout << "Number of collisions: " << collisions << endl;
            break;
        case 2:
            cout << "Enter keys to insert (enter -1 to stop):" << endl;
            while (true) {
                cin >> key;
                if (key == -1)
                    break;
                quadraticProbing(hash_table, tsize, key, collisions);
            }
            cout << "data base after insertion:" << endl;
            printArray(hash_table, tsize);
            cout << "Number of collisions: " << collisions << endl;
            break;
        case 3:
        	exit(0);
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

