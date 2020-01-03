#include<iostream>
#include<vector>
using namespace std;
int ucln(int a, int b);
class Phanso{
	int tu, mau;
public:
	void Nhap(){
		cin >> tu >> mau;
	}
	void Xuat(){
		if (mau < 0){
			tu *= -1;
			mau *= -1;
		}
		int uc = ucln(tu, mau);
		tu /= uc;
		mau /= uc;
		cout << tu << "/" << mau << endl;
	}
	Phanso(){
		
		tu = 0;
		mau = 1;
	}
	friend istream & operator>>(istream &is, Phanso &a){
		cin >> a.tu >> a.mau;
	}
	Phanso operator+(Phanso a){
		Phanso tong;
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = mau*a.mau;
		return tong;
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
int main(){
	char k;
	cin >> k;
	
	if (k == 'a'){
		int tong = 0;
		int a;
		while (cin >> a){
			tong += a;
		}
		cout << tong << endl;
	}
	else{
		Phanso tong;
		Phanso a;
		while (cin >> a){
			tong = tong + a;
		}
		tong.Xuat();
	}
	//system("pause");
	return 0;
}