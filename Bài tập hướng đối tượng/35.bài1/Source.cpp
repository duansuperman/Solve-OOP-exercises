#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
class Sophuc{
	int a, b;
public:
	friend istream & operator>>(istream & is, Sophuc & p){
		cin >> p.a >> p.b;
		return cin;
	}
	friend ostream & operator<<(ostream& os, Sophuc p){
		cout << p.a << "+" << b << "i" << endl;
		return cout;
	}
	Sophuc operator+(Sophuc p){
		Sophuc tong;
		tong.a = a + p.a;
		tong.b = b + p.b;
		return tong;
	}
	Sophuc operator-(Sophuc p){
		Sophuc hieu;
		hieu.a = a - p.a;
		hieu.b = b - p.b;
		return hieu;
	}
};
int main(){
	Sophuc a, b;
	cin >> a;
	cin >> b;
	cout << a;
	cout << b;
	cout << a + b;
	cout << a - b;
	return 0;
}