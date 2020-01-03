#include<iostream>
#include<cmath>
using namespace std;
int dem;
class Toado{
private:
	float x, y;
public:
	void Nhaptoado(){
		cout << "Nhap hoanh do x = ";
		cin >> x;
		cout << "Nhap tung do y = ";
		cin >> y;
	}
	void Xuattoado(){
		cout << "(" << x << ";" << y << ")" << endl;
	}
	Toado(){
		x = 0;
		y = 0;
		dem++;
	}
	Toado(float a, float b){
		x = a;
		y = b;
		dem++;
	}
	Toado(const Toado &a){
		x = a.x;
		y = a.y;
	}
	~Toado(){
		//Khi có con trỏ mới hủy
	}
	float Tinhkhoangcach2diem(Toado a){
		return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
	}
};
int main(){
	Toado a(1,2);
	Toado b;
	a.Xuattoado();
	b.Xuattoado();
	cout << dem << endl;
	cout << "khoang cach a & b : " << a.Tinhkhoangcach2diem(b) <<endl;
	system("pause");
	return 0;
}