#include "AVL.h"
using namespace std;

node* root = nullptr;

node* createNode(int x, int height) {
    node* temp = new node;
    temp -> data = x;
    temp -> height = height;
    return temp;
}

int getHeight(node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->height;
}

void rotateRight(node* target) {
    node* parentNode = target -> parent;
    node* subTree1 = target -> left;
    node* subTree2 = subTree1 -> right;

    if (parentNode == nullptr) {
        root = subTree1;
    }

    if (parentNode != nullptr) {
        if (target -> data < parentNode -> data) {
            parentNode -> left = subTree1;
        }
        else {
            parentNode -> right = subTree1;
        }
        subTree1 -> parent = parentNode;
    }

    subTree1 -> right = target;
    target -> parent = subTree1;

    target -> left = subTree2;

    subTree1->height = (max(getHeight(subTree1->left), getHeight(subTree1->right)) + 1);

    if (subTree2 != nullptr) {
        subTree2 -> parent = target;
        subTree2 -> height = (max(getHeight(subTree2->left), getHeight(subTree2->right)) + 1);
    }

    return;
}

void rotateLeft(node* target) {
    node* parentNode = target -> parent;
    node* subTree1 = target -> right;
    node* subTree2 = subTree1 -> left;

    if (parentNode == nullptr) {
        root = subTree1;
    }

    if (parentNode != nullptr) {
        if (target -> data < parentNode -> data) {
            parentNode -> left = subTree1;
        }
        else {
            parentNode -> right = subTree1;
        }
        subTree1 -> parent = parentNode;
    }

    subTree1 -> left = target;
    target -> parent = subTree1;

    target -> right = subTree2;

    subTree1->height = (max(getHeight(subTree1->left), getHeight(subTree1->right)) + 1);

    if (subTree2 != nullptr) {
        subTree2 -> parent = target;
        subTree2->height = (max(getHeight(subTree2->left), getHeight(subTree2->right)) + 1);
    }

    return;
}

int calcBalance(node* root) {
    if (root == nullptr) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

void insert(node* &root, int x) {
    if (root == nullptr) {
        node* temp = createNode(x,1);
        root = temp;
        return;
    }
    if (x < root -> data) {
        if (root -> left == nullptr) {
            node* temp = createNode(x,1);
            temp -> parent = root;
            root -> left = temp;
        }
        else {
            insert(root -> left, x);
        }
    }
    else if (x > root -> data) {
            if (root -> right == nullptr) {
                if (root -> right == nullptr) {
                    node* temp = createNode(x,1);
                    temp -> parent = root;
                    root -> right = temp;
                }
            }
            else {
                insert(root -> right, x);
            }
        }
    else {
        return;
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    
    int check = calcBalance(root);
    //Left Left Case
    if (check > 1 && x < root -> left -> data) {
        rotateRight(root);
        return;
    }
    //Right Right Case
    if (check < -1 && x > root -> right -> data) {
        rotateLeft(root);
        return;
    }
    //Left Right Case
    if (check > 1 && x > root -> left -> data) {
        rotateLeft(root->left);
        rotateRight(root);
        return;
    }
    //Right Left Case
    if (check < -1 && x < root -> right -> data) {
        rotateRight(root->right);
        rotateLeft(root);
        return;
    }
    return;
}

void inOrder(node *root)
{
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root -> data << " ";
    inOrder(root->right);
}

void destroyTree(node* &root) {
    if (root == nullptr) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
    root = nullptr;
    return;
}