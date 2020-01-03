#include<iostream>
#include<string>
using namespace std;
class Hinh{
protected:
	int a, b;
public:
	void Nhap(){
		cin >> a >> b;
	}
	virtual int Chuvi() = 0;
	virtual void Xuat() = 0;
};
class HCN:public Hinh{
public :
	friend istream & operator>>(istream& is, HCN & h){
		cin >> h.a >> h.b;
		return cin;
	}
	void Xuat(){
		cout << Chuvi() << endl;
	}
	int Chuvi(){
		return (a+b)*2;
	}
};
class HV: public Hinh{
public:
	friend istream & operator>>(istream & is, HV &h){
		int k;
		cin >> k;
		h.a = h.b = k;
		return cin;
	}
	void Xuat(){
		cout << Chuvi() << endl;
	}
	int Chuvi(){
		return a*4;
	}
};
int main(){
	Hinh *a[100];
	HCN b[100];
	HV c[100];
	int dem = 0;
	int dem1 = 0;
	int dem2 = 0;
	while (1){
		string k;
		cin >> k;
		if (k == "a"){
			cin >> c[dem2];
			a[dem++] = &c[dem2];
			dem2++;
		}
		else if (k == "b"){
			cin >> b[dem1];
			a[dem++] = &b[dem1];
			dem1++;
		}
		else{
			break;
		}
	}
	for (int i = 0; i < dem; i++){
		a[i]->Xuat();
	}
	//system("pause");
	return 0;
}