#include "AVL.h"
using namespace std;

int main() {
    int temp;
    while (cin >> temp && temp != 0) {
        insert(root, temp);
    }
    inOrder(root);
    destroyTree(root);
    inOrder(root);
}