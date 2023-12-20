/*Binary Search Tree - Linked List Implementation
Input
50 25 6 75 30 60 70 52 85 -1
30
25
50

Output
Tree values are:
6 25 30 50 52 60 70 75 85 
Inorder traversal after deletion of 30: 6 25 50 52 60 70 75 85 
Inorder traversal after deletion of 25: 6 50 52 60 70 75 85 
Inorder traversal after deletion of 50: 6 52 60 70 75 85 
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val) {
    if (root == NULL){
        Node* newnode = new Node();
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* findMinimum(Node* current) {
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) 
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int val;
    cin >> val;
    while ( val > 0 ) {
        root = insert( root, val);
        cin>>val;
    }
    cout << "Tree values are:" << endl;
    inorder( root );
    cout << endl;
    
    int key;
    cin>>key;
    root = deleteNode(root, key);
    cout << "Inorder traversal after deletion of " << key << ": ";
    inorder(root);
    cout << endl;
    
    cin>>key;
    root = deleteNode(root, key);
    cout << "Inorder traversal after deletion of " << key << ": ";
    inorder(root);
    cout << endl;
    
    cin>>key;
    root = deleteNode(root, key);
    cout << "Inorder traversal after deletion of " << key << ": ";
    inorder(root);
    cout << endl;
    
    return 0;
}
