#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class Diem{
	double x, y;
public:
	void Nhap(){
		cin >> x >> y;
	}
	void Xuat(){
		cout << "(" << x << "," << y << ")" << endl;
	}
	friend istream & operator>>(istream &is, Diem& a){
		cin >> a.x >> a.y;
		return is;
	}
	friend ostream & operator<<(ostream&os, Diem a){
		cout << "(" << a.x << "," << a.y << ")" << endl;
	}
	double Tinhkhoangcach(Diem a){
		double kc = sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
		return kc;
	}
	int Xettamgiac(Diem a, Diem b){
		double ab = a.Tinhkhoangcach(b);
		double bc = b.Tinhkhoangcach(*this);
		double ac = a.Tinhkhoangcach(*this);

	}
};
class Tamgiac{
	Diem a, b, c;
public :
	friend istream & operator>>(istream &is, Tamgiac & t){
		cin >> t.a;
		cin >> t.b;
		cin >> t.c;
		return is;
	}
	double Dientich(){
		double ab = a.Tinhkhoangcach(b);
		double bc = b.Tinhkhoangcach(c);
		double ac = a.Tinhkhoangcach(c);
		double p = (ab + bc + ac) / 2;
		double s = sqrt(p*(p - ab)*(p - bc)*(p - ac));
		return s;
	}
	int Xacdinhdiem(Diem d){
		double ab = a.Tinhkhoangcach(b);
		double bd = b.Tinhkhoangcach(d);
		double ad = a.Tinhkhoangcach(d);
		double p = (ab + bd + ad) / 2;
		double s = sqrt(p*(p - ab)*(p - bd)*(p - ad));

		double ac1 = a.Tinhkhoangcach(c);
		double ad1 = a.Tinhkhoangcach(d);
		double cd1 = c.Tinhkhoangcach(d);
		double p1 = (ac1 + ad1 + cd1) / 2;
		double s1 = sqrt(p1*(p1 - ac1)*(p1 - ad1)*(p1 - cd1));

		double bc2 = b.Tinhkhoangcach(c);
		double bd2 = b.Tinhkhoangcach(d);
		double cd2 = c.Tinhkhoangcach(d);
		double p2 = (bc2 + bd2 + cd2) / 2;
		double s2 = sqrt(p2*(p2 - bc2)*(p2 - bd2)*(p2 - cd2));
		if (Dientich() >= s&&Dientich() >= s1&&Dientich() >= s2){
			return 1;
		}
		return 0;
	}
};
int main(){
	Tamgiac a;
	cin >> a;
	Diem d;
	cin >> d;
	int kt = a.Xacdinhdiem(d);
	if (kt == 1){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	

	//system("pause");
	return 0;
}