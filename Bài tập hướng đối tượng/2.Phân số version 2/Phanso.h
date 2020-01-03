#pragma once
#include<iostream>
using namespace std;

class Phanso
{
	int tu, mau;
public:
	void Nhap();
	void Xuat();
	void Rutgon();
	Phanso Tinhtong(Phanso);
	Phanso Tinhtich(Phanso);
	Phanso Tinhhieu(Phanso);
	Phanso Tinhthuong(Phanso);
};


