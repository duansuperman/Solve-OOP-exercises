#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Diem{
	vector<float>diem;
public:
	void Nhap(){
		float k;
		while (cin >> k){
			diem.push_back(k);
		}
	}
	float DTB(){
		float Tong;
		for (int i = 0; i < diem.size(); i++){
			Tong += diem[i];
		}
		Tong /= diem.size();
		Tong *= 10;
		int dtb = Tong;
		return (float)dtb / 10;
	}
};

class Sinhvien{
	string hoten;
	string mssv;
	Diem diem;
public:
	void Nhap(){
		getline(cin, hoten);
		getline(cin, mssv);
		diem.Nhap();
	}
	void Xuat(){
		cout << "Ho Ten:" << hoten <<endl;
		cout << "Ma So Sinh Vien:" << mssv << endl;
		cout << "DTB:" << diem.DTB() << endl;
	}
};
int main(){
	Sinhvien a;
	a.Nhap();
	a.Xuat();
	return 0;
}