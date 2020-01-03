#include<iostream>
using namespace std;
class Phanso{
protected:
	int tu, mau;
	void Nhap(){
		cin >> tu;
		cin >> mau;
	}
	void Xuat(){
		if (mau < 0){
			tu *= -1;
			mau *= -1;
		}
		cout << tu << "/" << mau <<endl;
	}
	Phanso cong(Phanso a){
		Phanso tong;
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = mau*a.mau;
		return tong;
	}
	Phanso(){
		tu = 0;
		mau = 1;
	}
	Phanso(int a, int b){
		tu = a;
		mau = b;
	}
};
int ucln(int a, int b){
	if (a < 0){
		a *= -1;
	}
	if (b < 0){
		b *= -1;
	}
	while (a != b){
		if (a>b){
			a -= b;

		}
		else{
			b -= a;
		}
	}
	return a;
}

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
			a.tu*-1;
		}
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = mau*a.mau;
		return tong;
	}
};
int main(){
	Honso a, b;
	a.Nhap();
	b.Nhap();
	Honso c = a.cong(b);
	c.Xuat();
	//system("pause");
	return 0;
}