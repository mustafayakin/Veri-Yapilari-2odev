/**
* @file bst.cpp
* @description Binary Search İşleminin yapıldığı yer.
* @course 1.Öğretim A Grubu
* @assignment 2.ödev
* @date 5.Aug.2023
* @author Mustafa Yakın mustafa.yakin@ogr.sakarya.edu.tr
*/


#include "bst.h"

BinarySearchTree::BinarySearchTree() : root(NULL) {}


BSTNode* BinarySearchTree::insertRecursive(BSTNode* currentNode, int value)  {
    if (currentNode == NULL) {
        totalOfElements += value;
        return new BSTNode(value);
    }

    if (value < currentNode->data) {
        currentNode->left = insertRecursive(currentNode->left, value);
    } else if (value > currentNode->data) {
        currentNode->right = insertRecursive(currentNode->right, value);
    }

    return currentNode;
}

bool BinarySearchTree::searchRecursive(BSTNode* currentNode, int value) const {

    if (currentNode == NULL) {
        return false;
    }

    if (currentNode->data == value) {
        return true;
    } else if (value < currentNode->data) {
        return searchRecursive(currentNode->left, value);
    } else {
        return searchRecursive(currentNode->right, value);
    }
}

void BinarySearchTree::insert(int value) {
    root = insertRecursive(root, value);
}

bool BinarySearchTree::search(int value) const {
    return searchRecursive(root, value);
}

int BinarySearchTree::calculateHeightRecursive(BSTNode *currentNode) const {
    if (currentNode == NULL) {
        return -1;
    }

    int leftHeight = calculateHeightRecursive(currentNode->left);
    int rightHeight = calculateHeightRecursive(currentNode->right);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int BinarySearchTree::calculateHeight() const {
    return calculateHeightRecursive(root);
}

void BinarySearchTree::postorderYazdirmaRecursive(BSTNode *currentNode) const {

    if (currentNode == NULL) {
        return;
    }

    postorderYazdirmaRecursive(currentNode->left);

    postorderYazdirmaRecursive(currentNode->right);

    char ascii = currentNode->data;
    std::cout << ascii << " ";
}

void BinarySearchTree::postorderYazdirma() const  {
    postorderYazdirmaRecursive(root);
}




