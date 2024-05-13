// A Dictionary using BST: A Dictionary stores key and value pairs 
// Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be 
// comparable, Keys must be unique. 
// Standard Operations: Insert(key, value), Find(key), Delete(key)
// Write a menu driven C++ program to provide above standard operations 
// on dictionaries and provide a facility to display whole data sorted in 
// ascending/ Descending order. Also find how many maximum 
// comparisons may require for finding any keyword. 
// Use Binary Search Tree for implementation

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int key;
    string value;
    Node *left;
    Node *right;
};

Node *createNode(int key, string value)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int key, string value)
{
    if (root == nullptr)
    {
        return createNode(key, value);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key, value);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key, value);
    }
    return root;
}

Node *find(Node *root, int key)
{
    if (root == nullptr || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return find(root->left, key);
    }
    return find(root->right, key);
}

int maxComparisons(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + max(maxComparisons(root->left), maxComparisons(root->right));
}

void displayAscending(Node *root)
{
    if (root != nullptr)
    {
        displayAscending(root->left);
        cout << "Key: " << root->key << ", Value: " << root->value << endl;
        displayAscending(root->right);
    }
}

void displayDescending(Node *root)
{
    if (root != nullptr)
    {
        displayDescending(root->right);
        cout << "Key: " << root->key << ", Value: " << root->value << endl;
        displayDescending(root->left);
    }
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = root->right;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        root->key = temp->key;
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    int choice, key;
    string value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Delete\n";
        cout << "4. Display Ascending and Descending\n";
        cout << "5. Maximum Comparisons\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key and value to insert: ";
            cin >> key >> value;
            root = insert(root, key, value);
            break;
        case 2:
            cout << "Enter key to find: ";
            cin >> key;
            if (find(root, key) != nullptr)
            {
                cout << "Key found in the dictionary.\n";
            }
            else
            {
                cout << "Key not found in the dictionary.\n";
            }
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            break;
        case 4:
            cout << "Dictionary in ascending order:\n";
            displayAscending(root);
            cout << "Dictionary in Descending order:\n"<<endl;
            displayDescending(root);
            break;
        case 5:
            cout << "Maximum comparisons required for finding any keyword: " << maxComparisons(root) << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice);
}