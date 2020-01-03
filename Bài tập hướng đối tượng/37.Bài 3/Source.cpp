#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
class Phanso{
protected: int tu, mau;
public:
	friend istream & operator>>(istream & is, Phanso & p){
		cin >> p.tu >> p.mau;
		return cin;
	}
	friend ostream & operator<<(ostream& os, Phanso p){
		if (p.mau < 0){
			p.tu *= -1;
			p.mau *= -1;
		}
		cout << p.tu << "/" << p.mau <<endl;
		return cout;
	}
	int Get_tu(){
		return tu;
	}
	int Get_mau(){
		return mau;
	}
};
class Sophuc: public Phanso{
	int a, b;
public:
	friend istream & operator>>(istream & is, Sophuc & p){
		cin >> p.a >> p.b;
		return cin;
	}
	friend ostream & operator<<(ostream& os, Sophuc p){
		cout << p.a << "+" << p.b << "i" << endl;
		return cout;
	}
	void Xuat(){
		if (a*b != 0){
			if (b < 0){
				cout << a  << b << "i" << endl;
			}
			else{
				cout << a << "+" << b << "i" << endl;
			}
		}
		else{
			if (b == 0){
				cout << a << endl;
			}
			else{
				cout << b << "i" << endl;
			}
		}
	}
	Sophuc operator+(Sophuc p){
		Sophuc tong;
		tong.a = a + p.a;
		tong.b = b + p.b;
		return tong;
	}
	Sophuc operator*(Sophuc p){
		Sophuc nhan;
		nhan.a = a*p.a - b*p.b;
		nhan.b = a*p.b + b*p.a;
		return nhan;
	}
	Sophuc operator-(Sophuc p){
		Sophuc hieu;
		hieu.a = a - p.a;
		hieu.b = b - p.b;
		return hieu;
	}
	Sophuc operator+(int k){
		Sophuc tong;
		tong.a = a + k;
		tong.b = b;
		return tong;
	}
	Sophuc operator+(Phanso p){
		Sophuc tong;
		tong.a = a + p.Get_tu();
		tong.b = b + p.Get_mau();
		return tong;
	}
	Sophuc operator^(int k){

		Sophuc p = *this;
		for (int i = 1; i < k; i++){
			*this = *this*p;
		}
		return *this;
	}
	Sophuc Mu(int k){

		Sophuc p = *this;
		for (int i = 1; i < k; i++){
			*this = *this*p;
		}
		return *this;
	}
};
int main(){
	Sophuc a, b;
	cin >> a;
	char t;
	cin >> t;
	if (t == 'i'){
		int k;
		cin >> k;
		cout << a;
		cout << k << endl;
		Sophuc tong = a + k;
		tong.Xuat();
	}
	else if (t == 'z'){
		cin >> b;
		cout << a;
		b.Xuat();
		Sophuc tong = a + b;
		tong.Xuat();
	}
	else{
		Phanso p;
		cin >> p;
		cout << a;
		cout << p;
		Sophuc tong = a + p;
		tong.Xuat();
	}
	return 0;
}