#include<iostream>
using namespace std;

class Diem{
	float x, y;
public:
	void Nhapdiem(){
		cout << "Nhap toa do diem : " << endl;
		cout << "Nhap hoanh do : ";
		cin >> x;
		cout << "Nhap tung do : ";
		cin >> y;
	}
	void Xuat(){
		cout << "(" << x << "," <<y<< ")" << endl;
	}
	float Tinhkhoangcach(Diem a){
		return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
	}
	Diem TimdiemdoixungquaO(){
		Diem ddx;
		ddx.x = -x;
		ddx.y = -y;
		return ddx;
	}
	Diem Timdiemdoixungquatruchoanh(){
		Diem ddx;
		ddx.x = x;
		ddx.y = -y;
		return ddx;
	}
	Diem Timdiemdoixungquatructung(){
		Diem ddx;
		ddx.x = -x;
		ddx.y = y;
		return ddx;
	}
	Diem(void){
		x = 0;
		y = 0;
	}

	Diem(float a, float b){
		x = a;
		y = b;
	}
	~Diem(void){
		
	}
};

int main(){
	Diem a,b;
	/*a.Nhapdiem();*/
	b.Nhapdiem();
	a.Xuat();
	b.Xuat();
	a.TimdiemdoixungquaO().Xuat();
	a.Timdiemdoixungquatruchoanh().Xuat();
	a.Timdiemdoixungquatructung().Xuat();
	cout << "Khoang cach giua 2 toa do : " << a.Tinhkhoangcach(b) << endl;
	system("pause");
	return 0;
}