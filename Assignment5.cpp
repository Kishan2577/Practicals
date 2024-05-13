// Expression tree: Write a menu driven C++ program to construct an 
// expression tree from the given prefix expression eg. +--a*bc/def and 
// perform following operations:
// 1. Traverse it using post order traversal (non recursive) 
// 2. Delete the entire tree 
// 3. Change a tree so that the roles of the left and right pointers are 
// swapped at every node

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* constructTree(string prefix) {
    stack<Node*> s;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            s.push(new Node(prefix[i]));
        } else {
            Node* right = s.top();
            s.pop();
            Node* left = s.top();
            s.pop(); 
            s.push(new Node(prefix[i]));
            s.top()->left = left;
            s.top()->right = right;
        }
    }
    return s.top();
}

void postOrder(Node* root) {
    if (!root)
        return;

    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void deleteTree(Node* root) {
    if (!root)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();

        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);

        delete temp;
    }
}

void swapPointers(Node* root) {
    if (!root)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapPointers(root->left);
    swapPointers(root->right);
}

int main() {
    string prefix;
    Node* root;

    while (true) {
        cout << "\n1. Construct Expression Tree\n";
        cout << "2. Post Order Traversal\n";
        cout << "3. Delete the Tree\n";
        cout << "4. Swap Pointers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the prefix expression: ";
                cin >> prefix;
                root = constructTree(prefix);
                break;
            case 2:
                cout << "Post Order Traversal: ";
                postOrder(root);
                break;
            case 3:
                deleteTree(root);
                cout << "The tree has been deleted.\n";
                root = nullptr;
                break;
            case 4:
                swapPointers(root);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
