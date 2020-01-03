#include<iostream>
using namespace std;
class Diem{
	float x, y;
public:
	void Nhapdiem(){
		cout << "Nhap hoanh do x = ";
		cin >> x;
		cout << "Nhap tung do y = ";
		cin >> y;
	}
	void Xuatdiem(){
		cout << "(" << x << ";" << y << ")" << endl;
	}
	Diem(){
		x = y = 0;
	}
	Diem(float a, float b){
		x = a;
		y = b;
	}
	Diem(const Diem&a){
		x = a.x;
		y = a.y;
	}
	~Diem(){

	}
	float Getter_x(){
		return x;
	}
	float Getter_y(){
		return y;
	}
	
};

class Duongtron{
	float r;
	Diem x;
public:
	void Nhapduongtron(){
		cout << "Nhap ban kinh r = ";
		cin >> r;
		cout << "Nhap toa do tam : " << endl;
		x.Nhapdiem();
	}
	void Xuatduongtron(){
		cout << "Ban kinh r = " << r;
		cout << "Toa do tam : ";
		x.Xuatdiem();
	}
	float Tinhkhoangcach2tam(Duongtron a){
		return sqrt(pow(x.Getter_x() - a.x.Getter_x(), 2) + pow(x.Getter_y() - a.x.Getter_y(), 2));
	}
	int Kiemtracatnhau(Duongtron b){
		float Khoangcach = Tinhkhoangcach2tam(b);
		float tong = r + b.r;
		if (tong > Khoangcach){
			return 1;
		}
		else if (tong == Khoangcach){
			return 0;
		}
		else{
			return -1;
		}
	}
	
};

int main(){
	Duongtron a, b;
	a.Nhapduongtron();
	b.Nhapduongtron();
	int kt = a.Kiemtracatnhau(b);
	if (kt == 1){
		cout << "Khong cat nhau " << endl;
	}
	else if (kt == 0){
		cout << "Tiep xuc nhau " << endl;
	}
	else{
		cout << "Cat nhau " << endl;
	}
	system("pause");
	return 0;
}