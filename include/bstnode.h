/**
* @file bstnode.h
* @description Binary Search İşleminin düğüm kısmının yapıldığı yer.
* @course 1.Öğretim A Grubu
* @assignment 2.ödev
* @date 5.Aug.2023
* @author Mustafa Yakın mustafa.yakin@ogr.sakarya.edu.tr
*/
#ifndef STACKPROJECT_BSTNODE_H
#define STACKPROJECT_BSTNODE_H

#include <iostream>

using namespace std;

class BSTNode {

public:
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int data);
};



#endif //STACKPROJECT_BSTNODE_H
