/**
* @file stack.cpp
* @description Stack işleminin yapıldığı yer.
* @course 1.Öğretim A Grubu
* @assignment 2.ödev
* @date 4.Aug.2023
* @author Mustafa Yakın mustafa.yakin@ogr.sakarya.edu.tr
*/


#include "stack.h"


Stack::Stack(){
    elements = new int[MAX_SIZE];
    topIndex = -1;
}

Stack::~Stack() {
    delete[] elements;
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

int Stack::size() const {
    return topIndex + 1;
}

void Stack::push(int value) {

    if(isFull()){
        throw std::runtime_error("Stack tamamen dolu. Daha fazla veri eklenemez.");
    }

    topIndex++;
    elements[topIndex] = value;

}

bool Stack::isFull() const {
    return topIndex + 1 == MAX_SIZE;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack boş. Herhangi bir veri çıkartılamaz.");
    }

    int poppedValue = elements[topIndex];
    topIndex--;
    return poppedValue;
}

int Stack::top() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack boş. Stack'in en üsttünde herhangi bir veri bulunmamaktadır.");
    }

    return elements[topIndex];
}
