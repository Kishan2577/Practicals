
// Tree using traversal sequence: Write a C++ program to construct the binary tree with a given preorder and inorder sequence and Test your tree with all traversals

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
#include <cstring> 
using namespace std;

struct node {
    char data;
    node* left;
    node* right;
    node(char data) {
        this->data = data;
        left = right = NULL;
    }
};

int findIndex(char arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1; 
}

node* buildTree(char in[], char pre[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) {
        return nullptr;
    }
    node* p = new node(pre[preIndex++]);
    if (inStart == inEnd) {
        return p;
    }

    int inIndex = findIndex(in, inStart, inEnd, p->data);

    p->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    p->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return p;
}

void preorder(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int n;
    cin >> n;
    char in[n], pre[n];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    int start = 0, end = n - 1, index = 0;
    node* root = buildTree(in, pre, start, end, index);
    cout << "Pre-order traversal of the tree formed by the given preorder and inorder: ";
    preorder(root);
    cout << endl;
    cout << "In-order traversal of the tree formed by the given preorder and inorder: ";
    inorder(root);
    cout << endl;
    cout << "Post-order traversal of the tree formed by the given preorder and inorder: ";
    postorder(root);
    cout << endl;

    return 0;
}

