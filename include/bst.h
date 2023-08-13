/**
* @file bst.h
* @description Binary Search İşleminin node kısmının yapıldığı yer.
* @course 1.Öğretim A Grubu
* @assignment 2.ödev
* @date 5.Aug.2023
* @author Mustafa Yakın mustafa.yakin@ogr.sakarya.edu.tr
*/
#ifndef STACKPROJECT_BST_H
#define STACKPROJECT_BST_H


#include "bstnode.h"

class BinarySearchTree {

    BSTNode* root;
    BSTNode* insertRecursive(BSTNode* currentNode, int value);
    bool searchRecursive(BSTNode* currentNode, int value) const;
    int calculateHeightRecursive(BSTNode* currentNode) const;
    void postorderYazdirmaRecursive(BSTNode* currentNode) const;

public:

    BinarySearchTree();
    int totalOfElements = 0;

    void insert(int value);
    bool search(int value) const;
    int calculateHeight() const;
    void postorderYazdirma() const;
};


#endif //STACKPROJECT_BST_H
