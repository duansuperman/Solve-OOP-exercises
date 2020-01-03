#include"Phanso.h"
int main(){
	Phanso ps1, ps2;
	ps1.Nhap();
	ps2.Nhap();
	ps1.Rutgon();
	ps2.Rutgon();
	ps1.Xuat();
	ps2.Xuat();
	ps1.Tinhtong(ps2).Xuat();
	system("pause");
	return 0;
}