#include<iostream>
using namespace std;
int UCLN(int a, int b);
class Phanso{
	int tu, mau;
public:
	void Nhap(){
		cin >> tu >> mau;
		
	}
	Phanso(){
		tu = 0; 
		mau = 1;
	}
	void Xuat(){
		if (mau < 0){
			tu *= -1;
			mau *= -1;
		}
		int uc = UCLN(tu, mau);
		tu /= uc;
		mau / uc;
		cout << tu << "/" << mau << endl;
	}
	Phanso operator+(Phanso a){
		Phanso tong;
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = mau*a.mau;
		return tong;
	}
};

int UCLN(int a, int b){
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
	Phanso tong;
	int tong_int = 0;
	int check1 = 0;
	int check2 = 0;
	while (cin >> k){
		if (k == 'a'){
			int a;
			cin >> a;
			tong_int += a;
			check1 = 1;
		}
		if (k == 'b'){
			Phanso a;
			a.Nhap();
			tong = tong + a;
			check2 = 1;
		}
	}
	if (check1 == 1){
		cout << tong_int << endl;
	}
	else{
		cout << "khong co" << endl;
	}
	if (check2 == 1){
		tong.Xuat();
	}
	else{
		cout << "khong co" << endl;
	}
	//system("pause");
	return 0;
}