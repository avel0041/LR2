#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Vector
{
	double* a;
	int n;
public:
	Vector(double* arr, int b);
	Vector(Vector&& Vec);
	friend ostream& operator<<(ostream& out, Vector& vec);
	double& operator[](int in);
	Vector();
	Vector& operator =(Vector& vec);
	~Vector();
	friend Vector& operator +(Vector& v, Vector& vec);
};


