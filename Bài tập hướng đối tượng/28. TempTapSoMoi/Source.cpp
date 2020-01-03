#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Tapsomoi{
	int x, y, z, t;
public:
	void Nhap(){
		cin >> x >> y >> z >> t;
	}
	friend istream & operator>>(istream &is, Tapsomoi &a){
		cin >> a.x >> a.y >> a.z >> a.t;
		return cin;
	}
	void Xuat(){
		cout << "[TapSoMoi] " << x << ";" << y << ";" << z << ";" << t << endl;
	}
	friend ostream& operator<<(ostream & os, Tapsomoi a){
		cout << "[TapSoMoi] " << a.x << ";" << a.y << ";" << a.z << ";" << a.t;
		return cout;
	}
	Tapsomoi operator+(Tapsomoi a){
		Tapsomoi tong;
		tong.x = x + a.x;
		tong.y = y + a.y;
		tong.z = z + a.z;
		tong.t = t + a.t;
		return tong;
	}
	int operator<(Tapsomoi a){
		if (x<a.x){
			return 1;
		}
		else{
			return 0;
		}

	}
	void operator=(int a){
		x = y = z = t = 0;
	}
	Tapsomoi(){
		x = y = z = t = 0;
	}
};
template<class bien>
class Arr{
	bien a[100];
public:
	void Nhap(){
		bien k;
		int dem = 0;
		while (cin >> k){
			a[dem++] = k;
		}
		bien tong;
		tong = 0;
		bien Max = a[0];
		for (int i = 0; i<dem; i++){
			tong = tong + a[i];
			if (Max<a[i]){
				Max = a[i];
			}
		}
		cout << Max << endl;
		cout << tong << endl;
	}
};
int main(){
	char t;
	cin >> t;
	if (t == 'A'){
		Arr<int>a;
		a.Nhap();
	}
	else{
		Arr<Tapsomoi>a;
		a.Nhap();
	}

	return 0;
}