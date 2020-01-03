#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class Diem{
	double x, y;
public :
	void Nhap(){
		cin >> x >> y;
	}
	void Xuat(){
		cout << "(" << x << "," << y << ")" << endl;
	}
	friend istream & operator>>(istream &is, Diem& a){
		cin >> a.x >> a.y;
	}
	friend ostream & operator<<(ostream&os, Diem a){
		cout << "(" << a.x << "," << a.y << ")" << endl;
	}
	double Tinhkhoangcach(Diem a){
		double kc = sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
		return kc;
	}
};
int main(){
	Diem a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << a;
	cout << b;
	cout << c;
	double ab = a.Tinhkhoangcach(b);
	double bc = b.Tinhkhoangcach(c);
	double ac = a.Tinhkhoangcach(c);

	if (abs(ab + bc - ac) < 0.00001 || abs(ab + ac - bc) < 0.00001 || abs(ac + bc - ab) < 0.00001){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}