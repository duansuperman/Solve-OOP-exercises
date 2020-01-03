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
int main(){
	Diem a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	double ab = a.Tinhkhoangcach(b);
	double bc = b.Tinhkhoangcach(c);
	double ac = a.Tinhkhoangcach(c);

	if (abs(pow(ab, 2) + pow(bc, 2) - pow(ac, 2)) < 0.00001){
		if (abs(ab - bc) < 0.00001){
			cout << "tam giac vuong can" << endl;
		}
		else{
			cout << "tam giac vuong" << endl;
		}
		return 0;
	}
	if (abs(pow(ab, 2) + pow(ac, 2) - pow(bc, 2)) < 0.00001){
		if (abs(ab - ac) < 0.00001){
			cout << "tam giac vuong can" << endl;
		}
		else{
			cout << "tam giac vuong" << endl;
		}
		return 0;
	}
	if (abs(pow(ac, 2) + pow(bc, 2) - pow(ab, 2)) < 0.00001){
		if (abs(ac - bc) < 0.00001){
			cout << "tam giac vuong can" << endl;
		}
		else{
			cout << "tam giac vuong" << endl;
		}
		return 0;
	}
	if (abs(ab - bc)<0.00001&& abs(bc - ac)<0.00001){
		cout << "tam giac deu" << endl;
		return 0;
	}
	if (abs(ab - bc) < 0.00001 || abs(ab - ac) < 0.00001 || abs(ac - bc) < 0.00001){
		cout << "tam giac can" << endl;
		return 0;
	}
	if ((ab + bc < ac && abs(ab - bc) < 0.00001) || (ab + ac < bc && abs(ab - bc) < 0.00001) || (ac + bc < ab && abs(ab - bc) < 0.00001)){
		cout << "khong la tam giac" << endl;
	}
	else{
		cout << "tam giac thuong" << endl;
	}

	//system("pause");
	return 0;
}