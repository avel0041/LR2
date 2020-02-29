// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;


int main()
{
	int t,t1;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fin >> t;
	double *m = new double [t];
	for (int i = 0; i < t; i++) fin >> m[i];
	fin >> t1;
	double *m1 = new double [t1];
	for (int i = 0; i < t1; i++) fin >> m1[i];
	fin.close();
	fout.open("output.txt");
	Vector V1(m, t);
	fout << V1;
	Vector V2(m1, t1);
	fout << V2;
	Vector V3;
	V3 = (V1+V2);
	fout << V3 << endl;
	fout.close();
	system("pause");
	return 0;
}