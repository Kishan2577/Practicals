// A Dictionary using AVL: A Dictionary stores key and value pairs 
// Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be 
// comparable, Keys must be unique. 
// Standard Operations: Insert(key, value), Find(key), Delete(key)
// Write a menu driven C++ program to provide above standard operations 
// on dictionaries and provide a facility to display whole data sorted in 
// ascending/ Descending order. Also find how many maximum 
// comparisons may require for finding any keyword.
// Use Height balanced tree(AVL) and find the complexity for finding a 
// keyword

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
using namespace std;

class AVLNode {
public:
    int key;
    string value;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k, string v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    void updateHeight(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* balance(AVLNode* node);
    AVLNode* insertHelper(AVLNode* node, int key, string value);
    AVLNode* findMin(AVLNode* node);
    AVLNode* deleteNode(AVLNode* node, int key);
    void inOrderTraversal(AVLNode* node, bool ascending);

public:
    AVLTree() : root(nullptr) {}

    void insert(int key, string value);
    string find(int key);
    void remove(int key);
    void displayAscending();
    void displayDescending();
    int getMaxComparisons(int key);
};


int AVLTree::height(AVLNode* node) {
    return (node == nullptr) ? 0 : node->height;
}

int AVLTree::balanceFactor(AVLNode* node) {
    return height(node->left) - height(node->right);
}

void AVLTree::updateHeight(AVLNode* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

AVLNode* AVLTree::rotateRight(AVLNode* node) {
    AVLNode* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
}

AVLNode* AVLTree::rotateLeft(AVLNode* node) {
    AVLNode* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
}

AVLNode* AVLTree::balance(AVLNode* node) {
    updateHeight(node);

    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}

AVLNode* AVLTree::insertHelper(AVLNode* node, int key, string value) {
    if (node == nullptr) {
        return new AVLNode(key, value);
    }

    if (key < node->key) {
        node->left = insertHelper(node->left, key, value);
    } else if (key > node->key) {
        node->right = insertHelper(node->right, key, value);
    } else {
        node->value = value;
        return node;
    }

    return balance(node);
}

AVLNode* AVLTree::findMin(AVLNode* node) {
    if (node->left == nullptr) {
        return node;
    }
    return findMin(node->left);
}

AVLNode* AVLTree::deleteNode(AVLNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            AVLNode* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (node == nullptr) {
        return nullptr;
    }
    return balance(node);
}

void AVLTree::inOrderTraversal(AVLNode* node, bool ascending) {
    if (node == nullptr) {
        return;
    }
    if (ascending) {
        inOrderTraversal(node->left, ascending);
        cout << node->key << ": " << node->value << endl;
        inOrderTraversal(node->right, ascending);
    } else {
        inOrderTraversal(node->right, ascending);
        cout << node->key << ": " << node->value << endl;
        inOrderTraversal(node->left, ascending);
    }
}

void AVLTree::insert(int key, string value) {
    root = insertHelper(root, key, value);
}

string AVLTree::find(int key) {
    AVLNode* current = root;
    int comparisons = 0;
    while (current != nullptr) {
        comparisons++;
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return current->value;
        }
    }
    return "Key not found!";
}

void AVLTree::remove(int key) {
    root = deleteNode(root, key);
}

void AVLTree::displayAscending() {
    inOrderTraversal(root, true);
}

void AVLTree::displayDescending() {
    inOrderTraversal(root, false);
}

int AVLTree::getMaxComparisons(int key) {
    AVLNode* current = root;
    int comparisons = 0;
    while (current != nullptr) {
        comparisons++;
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return comparisons;
        }
    } 
    return -1;
}

int main() {
    AVLTree dictionary;
    int choice, key;
    string value;

    while (true) {
        cout << "\nAVL Dictionary Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display Ascending" << endl;
        cout << "5. Display Descending" << endl;
        cout << "6. Get Max Comparisons" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                dictionary.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                cout << "Value: " << dictionary.find(key) << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.remove(key);
                cout << "Key deleted." << endl;
                break;
            case 4:
                cout << "Dictionary in Ascending order:" << endl;
                dictionary.displayAscending();
                break;
            case 5:
                cout << "Dictionary in Descending order:" << endl;
                dictionary.displayDescending();
                break;
            case 6:
                cout << "Enter key to find max comparisons: ";
                cin >> key;
                cout << "Max comparisons required: " << dictionary.getMaxComparisons(key) << endl;
                break;
            case 7:
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
