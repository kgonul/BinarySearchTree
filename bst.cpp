#include <iostream>
struct node {
    int data;
    node* left;
    node* right;
};

node *root = nullptr;

node * createNode(int data) {
    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

node * addNode(node *node, int data) {
    if(node == nullptr) {
        return createNode(data);
    }
    if(data<node->data) {
        node->left = addNode(node->left, data);
    }
    else {
        node->right = addNode(node->right, data);
    }
    return node;
}

void traverse(node *n) {
    if (n != nullptr) {
        printf("%d ", n->data);
        traverse(n->left);
        traverse(n->right);
    }
}

node *searchNode(node* n, int data) {
    if(n == nullptr || n->data == data) {
        return n;
    }
    if (n->data>data) {
        return searchNode(n->left, data);
    }
    return searchNode(n->right, data);
}

node* deleteNode(node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
    
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
    
    // We reach here when root is the node
    // to be deleted.
    
    // If one of the children is empty
    if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    }
    
    // If both children exist
    else {
        node *succ = root->right;
        while (succ->left != NULL) {
            succ = succ->left;
        }
        root->data = succ->data;
        root->right = deleteNode(root->right, root->data);
        return root;
    }
}
//http://www.algolist.net/Data_structures/Binary_search_tree/Removal
//https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
int main() {
    root = addNode(root, 8);
    root = addNode(root, 5);
    root = addNode(root, 6);
    root = addNode(root, 9);
    root = addNode(root, 10);
    root = addNode(root, 1);
    traverse(root);
    node *p = searchNode(root, 9);
    /*if (p==nullptr) {
        printf("null");
    } else {
        printf("data: %d", p->data);
    }*/
    
    root = deleteNode(root, 8);
    traverse(root);
    return 0;
}
