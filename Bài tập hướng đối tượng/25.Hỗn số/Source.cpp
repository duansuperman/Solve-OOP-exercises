#include<iostream>
using namespace std;
int ucln(int a, int b);
class Phanso{
protected:
	int tu, mau;
public:
	void Nhap(){
		cin >> tu;
		cin >> mau;

	}
	void Xuat(){
		int uc = ucln(tu, mau);
		tu /= uc;
		mau /= uc;
		cout << tu << "/" << mau << endl;
	}
	Phanso(){
		tu = 0;
		mau = 1;
	}
	Phanso(int a, int b){
		tu = a;
		mau = b;
	}
	Phanso cong(Phanso a){
		Phanso tong;
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = mau*a.mau;
		return tong;
	}
};
class Honso:public Phanso{
	int phannguyen;
public:
	void Nhap(){
		cin >> phannguyen;
		Phanso::Nhap();
	}
	void Xuat(){
		cout << phannguyen << " ";
		Phanso::Xuat();
	}
	Honso cong(Honso a){
		Honso tong;
		tong.phannguyen = phannguyen + a.phannguyen;
		if (phannguyen < 0){
			tu *= -1;
			
		}
		if (a.phannguyen < 0){
			a.tu *= -1;
			
		}
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = a.mau*mau;
		return tong;
	}

};
int ucln(int a,int b){
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
	return a;
}
int main(){
	Honso a;
	a.Nhap();
	Honso b;
	b.Nhap();
	Honso c = a.cong(b);
	c.Xuat();
	//system("pause");
	return 0;
}