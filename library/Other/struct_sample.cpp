#include <iostream>

using namespace std;

struct treeNode {
    int data;

    treeNode *left;
    treeNode *right;

    treeNode(int _data){
        data = _data;
        left = right = NULL;
    }
};

void deleteTree(treeNode *node){

    if(node->left != NULL){
        deleteTree(node->left);
    }

    if(node->right != NULL){
        deleteTree(node->right);
    }

    delete node;
}

int main() {

    treeNode *n0 = new treeNode(5);
    treeNode *n1 = new treeNode(10);
    treeNode *n2 = new treeNode(20);

    n0->left = n1;
    n0->right = n2;

    deleteTree(n0); //メモリを解放

    return 0;
}
