#include "Vector.h"
Vector::Vector(double* arr, int b)
{
	n = b;
	a = new double[b];
	for (int i = 0; i < b; i++) a[i] = arr[i];
}
Vector::Vector(Vector&& Vec)
{
	a = Vec.a;
	n = Vec.n;
	Vec.a = nullptr;
	Vec.n = 0;
}

double& Vector::operator[](int in)
{
	return a[in];
}
Vector::Vector() { a = nullptr; n = 0; }
Vector& Vector::operator =(Vector& vec)
{
	n = vec.n;
	if (a != nullptr) delete[] a;
	a = new double[n];
	for (int i = 0; i < n; i++) a[i] = vec.a[i];
	return *this;
}
Vector::~Vector()
{
	if (a != nullptr) delete[] a;
}
Vector& operator +(Vector& v, Vector& vec)
{
	double* m = new double[v.n + vec.n];
	for (int i = 0; i < v.n; i++) m[i] = v.a[i];
	for (int i = 0; i < vec.n; i++) m[i + v.n] = vec.a[i];
	Vector* V1 = new Vector(m, v.n + vec.n);
	delete[] m;
	return *V1;
}
ostream& operator<<(ostream& out, Vector& vec) {
	for (int i = 0; i < vec.n; i++)
		out << vec.a[i] << " ";
	out << endl;
	return out;
}
