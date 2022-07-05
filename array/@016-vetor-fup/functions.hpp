#pragma once

#include <iostream>
#include <sstream>

struct Vector {
    int capacity;
    int size;
    int* data;
};

Vector* vector_create(int capacity) {
    Vector* vetor = new Vector();
    
    vetor->capacity = capacity;
    
    vetor->data = new int[capacity];
    
    vetor->size = 0;

    return vetor;
}

void vector_destroy(Vector* vetor) {
    delete [] vetor->data;
   
    delete vetor;
}

void vector_add(Vector* vetor, int value) {
    if (vetor->size < vetor->capacity) {
        vetor->data[vetor->size] = value;
        vetor->size++;
    }
}

std::string vector_show(Vector* vetor) {
    std::stringstream show;

    show << "[ ";

    for (int index = 0; index < vetor->size; index++) {
        show << vetor->data[index] << " ";
    }

    show << "]";

    return show.str();
}