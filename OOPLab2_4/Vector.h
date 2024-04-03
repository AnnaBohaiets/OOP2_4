#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Vector
{
private:
	static const int MAX_SIZE = 100;
	int data[MAX_SIZE];
	int size;
public:
	Vector();
	Vector(int arr[], int N);
	Vector(const Vector& other);
	~Vector();


	Vector& operator = (const Vector& other);
	operator string() const;

	friend ostream& operator << (ostream&, const Vector&);
	friend istream& operator >> (istream&, Vector&);


	Vector operator++();
	Vector operator--();
	Vector& operator++(int);
	Vector& operator--(int);

	Vector operator*(int scalar) const;
	bool operator==(const Vector& other) const;
	double operator()() const;


	int& operator [](int index);


};