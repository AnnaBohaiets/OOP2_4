#include "Vector.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;


Vector::Vector() : size(0) {};

Vector::Vector(int arr[], int N)
{
    size = (N > MAX_SIZE) ? MAX_SIZE : N;
    for (int i = 0; i < size; ++i) {
        data[i] = arr[i];
    }
}

Vector::Vector(const Vector& other) : size(other.size)
{
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Vector::~Vector() {};


Vector& Vector::operator = (const Vector& other)
{
    if (this != &other) {
        size = other.size;
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    return *this;
}

ostream& operator << (ostream& os, const Vector& vec)
{
    os << "Element in vector: ";
    for (int i = 0; i < vec.size; i++) {
        os << " " << vec.data[i];
    }
    return os;
}

istream& operator>>(istream& is, Vector& vec) {
    cout << "Enter the size of the vector: ";
    is >> vec.size;

    vec.size = min(vec.size, Vector::MAX_SIZE);

    cout << "Enter " << vec.size << " elements:" << endl;
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.data[i];
    }
    return is;
}

Vector::operator string() const
{
    string result = "Vector elements: ";
    for (int i = 0; i < size; i++) {
        result += " " + to_string(data[i]);
    }
    return result;
}

Vector Vector::operator ++()
{
    for (int i = 0; i < size; i++) {
        ++data[i];
    }
    return *this;
}

Vector Vector::operator --()
{
    for (int i = 0; i < size; i++) {
        --data[i];
    }
    return *this;
}

Vector& Vector::operator ++(int)
{
    Vector tmp(*this);
    ++(*this);
    return tmp;
}

Vector& Vector::operator --(int)
{
    Vector tmp(*this);
    --(*this);
    return tmp;
}


Vector Vector::operator *(int scalar) const {
    Vector result(*this);
    for (int i = 0; i < size; ++i) {
        result.data[i] *= scalar;
    }
    return result;
}



bool Vector::operator==(const Vector& other) const
{
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}



double Vector::operator()() const {
    double sum_of_squares = 0.0;
    for (int i = 0; i < size; ++i) {
        sum_of_squares += data[i] * data[i];
    }
    return std::sqrt(sum_of_squares);
}


int& Vector::operator[](int index)
{
    if (index >= 0 && index < size) {
        return data[index];
    }
    else {
        throw out_of_range("Index out of range!");
    }
}