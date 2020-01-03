#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int ucln(int a, int b);
class Phanso{
 int tu, mau;
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
		int uc = ucln(p.tu, p.mau);
		p.tu /= uc;
		p.mau /= uc;
		cout << p.tu << "/" << p.mau << endl;
		return cout;
	}
	int Get_tu(){
		return tu;
	}
	int Get_mau(){
		return mau;
	}

};
int ucln(int a,int b){
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
	return b;
}
int main(){
	float t = 0.7500;
	t -= 0;
	cout << t;
	system("pause");
	return 0;
}