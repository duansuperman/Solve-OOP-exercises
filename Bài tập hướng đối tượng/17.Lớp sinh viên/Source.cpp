#include<iostream>
#include<vector>
#include<string>
using namespace std;
class SinhVien{
	string hoten;
	string mssv;
	vector<float>diem;
public:
	void Nhap(){
		getline(cin, hoten);
		getline(cin, mssv);
		float k;
		while (cin>>k)
		{
			diem.push_back(k);
		}

	}
	void Xuat(){
		cout << "Ho Ten:" << hoten <<endl;
		cout << "Ma Sinh Vien:" << mssv << endl;
		cout << "DTB:" << DTB() << endl;
	}
	float DTB(){
		float Tong = 0;
		for (int i = 0; i < diem.size(); i++){
			Tong += diem[i];
		}
		float dtb = Tong / diem.size();
		dtb *= 10;
		int diem = dtb;
		return (float)diem / 10;
	}
	friend istream & operator>>(istream&is, SinhVien& sv){
		getline(cin, sv.hoten);
		getline(cin, sv.mssv);
		float k;
		while (cin>>k)
		{
			sv.diem.push_back(k);
		}
		return is;
	}
	friend ostream & operator<<(ostream&os, SinhVien sv){
		cout << "Ho Ten:" << sv.hoten << endl;
		cout << "Ma Sinh Vien:" << sv.mssv << endl;
		cout << "DTB:" << sv.DTB() << endl;
		return os;
	}
};
int main(){
	SinhVien a;
	cin >> a;
	cout << a;
	//system("pause");
	return 0;
}