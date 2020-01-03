#include "Phanso.h"
int Ucln(int a, int b){
	if (a<0){
		a *= -1;
	}
	if (b<0){
		b *= -1;
	}
	while (a != b){
		if (a > b){
			a -= b;
		}
		else{
			b -= a;
		}
	}
	return a; //hoac b
}
void Phanso::Nhap(){
	cout << "Nhap tu so : ";
	cin >> tu;
	do{
		cout << "Nhap mau : ";
		cin >> mau;
		if (mau == 0){
			cout << "Mau khong hop le. Nhap lai : " << endl;
		}
	} while (mau == 0);
}
void Phanso::Xuat(){
	cout << tu << "/" << mau << endl;
}
void Phanso::Rutgon(){
	int ucln = Ucln(tu, mau);
	tu /= ucln;
	mau /= ucln;
}
Phanso Phanso::Tinhtong(Phanso a){
	Phanso tong;
	tong.tu = tu*a.mau + mau*a.tu;
	tong.mau = mau*a.mau;
	return tong;
}
Phanso Phanso::Tinhhieu(Phanso a){
	Phanso hieu;
	hieu.tu = tu*a.mau - mau*a.tu;
	hieu.mau = mau*a.mau;
	return hieu;
}
Phanso Phanso::Tinhtich(Phanso a){
	Phanso tich;
	tich.tu = tu*a.tu;
	tich.mau = mau*a.mau;
	return tich;
}
Phanso Phanso::Tinhthuong(Phanso a){
	Phanso thuong;
	thuong.tu = tu*a.mau;
	thuong.mau = mau*a.tu;
	return thuong;
}
