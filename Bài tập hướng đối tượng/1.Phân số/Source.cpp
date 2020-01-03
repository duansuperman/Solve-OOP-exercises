#include<iostream>
using namespace std;

int Ucln(int, int);

class Phanso{
private:
	int tu, mau;
public:
	void Nhap(){
		cout << "Nhap tu so : ";
		cin >> tu;
		do{
			cout << "Nhap mau so : ";
			cin >> mau;
			if (mau == 0){
				cout << "Mau khong hop le. Nhap lai :" << endl;
			}
		} while (mau == 0);
	}
	void Xuat(){
		if (mau < 0){
			tu *= -1;
			mau *= -1;
		}
		cout << tu << "/" << mau << endl;
	}
	void Rutgonphanso(){
		int ucln = Ucln(tu, mau);
		tu /= ucln;
		mau /= ucln;
	}
	Phanso Tinhtong2phanso(Phanso a){
		a.tu = 1;
		a.mau = 2;
		Phanso tong;
		tong.tu = tu*a.mau + a.tu*mau;
		tong.mau = mau*a.mau;
		return tong;
	}
	Phanso Tinhhieu2phanso(Phanso a){
		Phanso hieu;
		hieu.tu = tu*a.mau - a.tu*mau;
		hieu.mau = mau*a.mau;
		return hieu;
	}
	Phanso Tinhtich2phanso(Phanso a){
		Phanso tich;
		tich.tu = tu*a.tu;
		tich.mau = mau*a.mau;
		return tich;
	}
	Phanso Tinhthuong2phanso(Phanso a){
		Phanso thuong;
		thuong.tu = a.mau;
		thuong.mau = a.tu;
		return thuong.Tinhtich2phanso(*this);
	}
};

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
	return a;//hoặc b
}

int main(){
	Phanso ps1,ps2;
	ps1.Nhap();
	ps2.Nhap();
	ps2.Xuat();
	ps1.Rutgonphanso();
	ps2.Rutgonphanso();
	Phanso tong = ps1.Tinhtong2phanso(ps2);
	Phanso hieu = ps1.Tinhhieu2phanso(ps2);
	Phanso tich = ps1.Tinhtich2phanso(ps2);
	Phanso thuong = ps1.Tinhthuong2phanso(ps2);
	tong.Rutgonphanso();
	cout << "Tong 2 phan so : ";
	tong.Xuat();
	hieu.Rutgonphanso();
	cout << "Hieu 2 phan so : ";
	hieu.Xuat();
	tich.Rutgonphanso();
	cout << "Tich 2 phan so : ";
	tich.Xuat();
	thuong.Rutgonphanso();
	cout << "Thuong 2 phan so : ";
	thuong.Xuat();
	system("pause");
	return 0;
}