#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
class Nhanvien{
	int manv;
	string ho;
	string ten;
	double luong;
public:
	void Nhapthongtin(){
		cin >> manv;
		cin.ignore();
		getline(cin, ho);
		getline(cin, ten);
		cin >> luong;
	}
	void Xuatthongtin(){
		cout << "Employee[id=" << manv << ",name=" << ho << " " << ten << ",salary=";
		printf("$%0.2f]\n", luong);
	}
	double Luongsaukhitang(double b){
		return luong*(1 + b);
	}
	double Luong1nam(double b){
		return Luongsaukhitang(b) * 12;
	}
};
int main(){
	Nhanvien a;
	a.Nhapthongtin();
	double b;
	cin >> b;
	b = b / 100;
	a.Xuatthongtin();
	
	/*cout << int(a.Luongsaukhitang(b) * 100)*1.0 / 100 << endl;
	cout << int(a.Luong1nam(b) * 100)*1.0 / 100 << endl;*/
	printf("$%0.2f\n", a.Luongsaukhitang(b));
	printf("$%0.2f", a.Luong1nam(b));
	//system("pause");
	return 0;
}