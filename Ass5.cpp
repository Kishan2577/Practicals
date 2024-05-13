#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Definition of the expression tree node
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct an expression tree from prefix expression
TreeNode* constructExpressionTree(const string& prefixExpression) {
    stack<TreeNode*> st;
    int length = prefixExpression.length();
   
    for (int i = length - 1; i >= 0; i--) {
        char c = prefixExpression[i];
        if (isOperator(c)) {
            TreeNode* node = new TreeNode(c);
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
            st.push(node);
        } else {
            TreeNode* node = new TreeNode(c);
            st.push(node);
        }
    }
    return st.top();
}

// Function to perform post order traversal (non-recursive)
void postOrderTraversal(TreeNode* root) {
    if (!root)
        return;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left)
            st1.push(current->left);
        if (current->right)
            st1.push(current->right);
    }

    while (!st2.empty()) {
        TreeNode* current = st2.top();
        st2.pop();
        cout << current->data << " ";
    }
}

// Function to delete the entire tree
void deleteTree(TreeNode* root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Function to swap the left and right pointers of each node
void swapTree(TreeNode* root) {
    if (!root)
        return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapTree(root->left);
    swapTree(root->right);
}

int main() {
    string prefixExpression;
    cout << "Enter the prefix expression: ";
    cin >> prefixExpression;

    TreeNode* root = constructExpressionTree(prefixExpression);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Traverse tree using post order traversal\n";
        cout << "2. Delete the entire tree\n";
        cout << "3. Swap the left and right pointers of each node\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Post order traversal: ";
                postOrderTraversal(root);
                cout << endl;
                break;
            case 2:
                deleteTree(root);
                cout << "Tree deleted successfully.\n";
                root = nullptr;
                break;
            case 3:
                swapTree(root);
                cout << "Tree nodes swapped successfully.\n";
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
