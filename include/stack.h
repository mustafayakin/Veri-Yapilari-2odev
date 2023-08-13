/**
* @file stack.h
* @description Stack işleminin headeri.
* @course 1.Öğretim A Grubu
* @assignment 2.ödev
* @date 4.Aug.2023
* @author Mustafa Yakın mustafa.yakin@ogr.sakarya.edu.tr
*/
#ifndef STACKPROJECT_STACK_H
#define STACKPROJECT_STACK_H

#include "bstnode.h"

class Stack {
private:

    const int MAX_SIZE = 100000;

    int* elements;
    int topIndex = -1;

public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void push(int value);
    int pop();
    int top() const;
};





#endif //STACKPROJECT_STACK_H
