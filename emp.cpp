
#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
};

Node* createNode(int id) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int id) {
    if (root == nullptr)
        return createNode(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->id << " ";
        inorder(root->right);
    }
}

bool search(Node* root, int id) {
    if (root == nullptr)
        return false;

    if (root->id == id)
        return true;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

int main() {
    Node* root = nullptr;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    int id;

    for (int i = 0; i < n; i++)
        root = insert(root, ids[i]);

    cout << "Employee IDs in ascending order: ";
    inorder(root);

    cout << "\nEnter employee ID to search: ";
    cin >> id;

    if (search(root, id))
        cout << "Employee ID found.\n";
    else
        cout << "Employee ID not found.\n";

    return 0;
}
