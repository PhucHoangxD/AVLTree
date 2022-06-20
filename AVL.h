#include <iostream>
#include <algorithm>

struct node {
    int data;
    node* left = nullptr;
    node* right = nullptr;
    int height = 1;
    node* parent = nullptr;
};

extern node* root;

node* createNode(int x, int height);
int getHeight(node* root);
void rotateRight(node* target);
void rotateLeft(node* target);
int calcBalance(node* root);
void insert(node* &root, int x);
void inOrder(node *root);
void destroyTree(node* &root);