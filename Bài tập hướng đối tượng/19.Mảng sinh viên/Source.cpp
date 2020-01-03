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
		float Tong = 0;
		for (int i = 0; i < diem.size(); i++){
			Tong += diem[i];
		}
		float dtb = Tong / diem.size();
		return dtb;
	}
};
class SinhVien{
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
		cout << "Ho Ten:" << hoten << endl;
		cout << "Ma Sinh Vien:" << mssv <<endl;
		printf("%.1f\n", diem.DTB());

	}
	float Get_DTB(){
		return diem.DTB();
	}
};
class MangSinhVien{
	int n;
	vector<SinhVien> a;
public:
	void Nhap(){
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++){
			
			
			SinhVien b;
			b.Nhap();
			cin.clear();
			
			a.push_back(b);
			
			
		}
	}
	void Xuat(){
		for (int i = 0; i < a.size(); i++){
			a[i].Xuat();
		}
	}
	float MaxDTB(){
		float Max = a[0].Get_DTB();
		for (int i = 1; i < a.size(); i++){
			if (Max < a[i].Get_DTB()){
				Max = a[i].Get_DTB();
			}
		}
		return Max;
	}
	void Xuatthongtindiemcaonhat(){
		float Max = MaxDTB();
		for (int i = 0; i < a.size(); i++){
			if (a[i].Get_DTB() == Max){
				a[i].Xuat();
				break;
			}
		}
	}
	
};
int main(){
	MangSinhVien a;
	a.Nhap();
	a.Xuatthongtindiemcaonhat();
	//system("pause");
	return 0;
}