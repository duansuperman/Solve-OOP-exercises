#include<iostream>
using namespace std;
class Hinh{
protected:
	double  a, b;
	
public:
	Hinh(){
		cout << "Hinh" << endl;
		a = b = 0;
	}
	Hinh(double x, double y){
		a = x;
		b = y;
	}
	virtual double Dientich() = 0 ;
};
class HCN :public Hinh{
	
public:
	void Nhap(){
		cin >> a >> b;
	
	}
	HCN(){
		
		a = b = 0;
	}
	HCN(double x, double y){
		a = x;
		b = y;
	}
	double Dientich(){
		cout << "HCN : " << a*b << endl;
		
		return a*b;
	}
};
class Tamgiac:public Hinh{
public:
	Tamgiac(){
		a = b = 0;
	}
	Tamgiac(double x, double y){
		a = x;
		b = y;
	}
	double Dientich(){
		cout << "Tam giac " << endl;
		return 0;
	}
};
int main(){
	Hinh *a[100];
	HCN b[3];
	for (int i = 0; i < 3; i++){
		
		b[i].Nhap();
		
		a[i] = &b[i];
		
		
	}
	for (int i = 0; i < 3; i++){
		a[i]->Dientich();
	}
	system("pause");
	return 0;
}