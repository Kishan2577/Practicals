// A Dictionary using Hash table: A Dictionary stores key and value pairs 
// Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be 
// comparable, Keys must be unique. 
// Standard Operations: Insert(key, value), Find(key), Delete(key)
// Write a menu driven C++ program to provide above standard operations 
// on dictionaries
// Write a menu driven C++ program to provide all the functions of a 
// dictionary (ADT) using hashing and handle collisions using chaining.

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
#include <list>
#include <string>

using namespace std;

const int TABLE_SIZE = 10; // Adjust table size as needed

// Node structure for storing key-value pairs in the hash table
struct Node {
    string key;
    string value;

    Node(string k, string v) : key(k), value(v) {}
};

// Dictionary class with separate chaining for collision resolution
class Dictionary {
public:
    Dictionary() {
        table = new list<Node>[TABLE_SIZE];
    }

    ~Dictionary() {
        delete[] table;
    }

    // Hash function (simple modulo for demonstration)
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

    // Insert a key-value pair
    void insert(string key, string value) {
        int index = hashFunction(key);
        // Check if key already exists
        for (auto &node : table[index]) {
            if (node.key == key) {
                cout << "Key already exists. Cannot insert." << endl;
                return;
            }
        }
        // Key does not exist, insert
        table[index].push_back(Node(key, value));
        cout << "Key-value pair inserted successfully." << endl;
    }

    // Find a value for a given key
    string find(string key) {
        int index = hashFunction(key);
        for (const auto &node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return "Key not found"; // Key not found
    }

    // Delete a key-value pair
    void deleteKey(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                cout << "Key-value pair deleted successfully." << endl;
                return;
            }
        }
        cout << "Key not found for deletion." << endl;
    }

private:
    list<Node>* table; // Hash table with linked lists for collision resolution
};

// Menu-driven program
int main() {
    Dictionary dictionary;
    int choice;
    string key, value;

    while (true) {
        cout << "\nDictionary Operations" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Insert (key, value)" << endl;
        cout << "2. Find (value for a key)" << endl;
        cout << "3. Delete (key)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dictionary.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find value: ";
                cin >> key;
                value = dictionary.find(key);
                cout << "Value for " << key << " is: " << value << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.deleteKey(key);
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}
/*
Dictionary Operations
-----------------------
1. Insert (key, value)
2. Find (value for a key)
3. Delete (key)
4. Exit
Enter your choice: 1
Enter key: mango
Enter value: fruit
Key-value pair inserted successfully.

Dictionary Operations
-----------------------
1. Insert (key, value)
2. Find (value for a key)
3. Delete (key)
4. Exit
Enter your choice: 1
Enter key: mango
Enter value: fruit
Key already exists. Cannot insert.

Dictionary Operations
-----------------------
1. Insert (key, value)
2. Find (value for a key)
3. Delete (key)
4. Exit
Enter your choice: 1
Enter key: chikoo
Enter value: fruit
Key-value pair inserted successfully.

Dictionary Operations
-----------------------
1. Insert (key, value)
2. Find (value for a key)
3. Delete (key)
4. Exit
Enter your choice: 2
Enter key to find value: chikoo
Value for chikoo is: fruit

Dictionary Operations
-----------------------
1. Insert (key, value)
2. Find (value for a key)
3. Delete (key)
4. Exit
Enter your choice: 3
Enter key to delete: mango
Key-value pair deleted successfully.
*/