#pragma once

#include <iostream>

template <typename T>

struct Vector {

    int capacity;
    int size;
    T *data;

    Vector(int capacity = 0, int size = 0) : capacity{capacity}, size{size} {
        if (capacity == 0) this->data = nullptr;
        else this->data = new T[capacity];
    }

    Vector(Vector &other) {
        *this = other;
    }

    ~Vector() {
        delete [] this->data;
    }

    void reserve(int new_capacity) {
        T * new_data = new T[new_capacity];

        int qtdd = std::min(this->size, new_capacity);

        for (int index = 0; index < qtdd; index++) {
            new_data[index] = this->data[index];
        }

        this->size = qtdd;
        this->capacity = new_capacity;

        delete [] this->data;
        
        this->data = new_data;
    }
    
    void push_back(T valor) {
        if (this->size == this->capacity) {
            this->reserve(this->capacity == 0 ? 1 : 2 * this->capacity);
        }

        this->data[size] = valor;
        this->size += 1;
    }

    void pop_back() {
        if (this->size != 0) 
            this->size -= 1; 
    }

    void insert(T *it, T valor) {
        if ( this->size == this->capacity) {
            reserve(2 * this->capacity);
        }

        int pos = it - this->data;

        for (int index = this->size; index > pos; index--) {
            this->data[index] = this->data[index - 1];
        }

        this->size += 1;
        this->data[pos] = valor;
    }

    void erase(T *it) {
        int pos = it - this->data;

        for (int index = this->size(); index < this->size; index++) {
            this->data[index] = this->data[index + 1];
        }

        this->size -= 1;
    }

    T& at(int index) const {
        if (index < 0 || index >= this->size) {
            throw std::string("Invalid index");
        }
        
        return this->data[index];
    }

    int get_capacity() const {
        return this->capacity;
    }

    int get_size() const {
        return this->size;
    }

    T& front() const {
        return this->data;
    }

    T& back() const {
        return this->data[this->size - 1];
    }

    T* begin() const {
        return this->data;
    }
    
    T* end() const {
        return this->data[this->size];
    }

    T& operator[](int index) const {
        return data[index];
    }

    void operator=(const Vector<T> &other) {
        this->capacity = other.get_capacity();
        this->size = other.get_size();
        
        if (this->data != nullptr) delete [] data;
        
        this->data = new T[capacity];
        
        for (int index = 0; index < this->size; index++) {
            this->data[index] = other.data[index];
        }
    }

    friend std::ostream& operator<<(std::ostream &os, Vector<T> &vector) {
        os << "[ ";

        for(int i = 0; i < vector.get_size(); i++) {
            os << vector.data[i] << " ";
        }

        os << "]";

        return os;
    }
};