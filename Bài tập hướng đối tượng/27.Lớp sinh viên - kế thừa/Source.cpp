#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Nguoi{
protected:
	string hoten, namsinh, quequan;
public:
	Nguoi(){
		hoten = "";
		namsinh = "";
		quequan = "";

	}
	Nguoi(string a, string b, string c){
		hoten = a;
		namsinh = b;
		quequan = c;
	}
	void Nhap(){
		getline(cin, hoten);
		getline(cin, namsinh);
		getline(cin, quequan);
	}
	void Xuat(){
		cout << "Ho Ten: "<<hoten << endl;
		cout << "Nam Sinh: "<<namsinh << endl;
		cout << "Que quan: "<<quequan << endl;
	}
};
class Sinhvien :public Nguoi{
	string khoa;
	vector<double>diem;
public:
	void Nhap(){
		Nguoi::Nhap();
		cin >> khoa;
		double k;
		while (cin >> k){
			diem.push_back(k);
		}
	}
	void Xuat(){
		Nguoi::Xuat();
		cout <<"Khoa: "<< khoa << endl;
		cout << "Diem cac mon: ";
		for (int i = 0; i < diem.size(); i++){
			cout << diem[i] << " ";
		}
		printf("Diem trung binh: %.2f\n", DTB());
	}
	double DTB(){
		double tong = 0;
		for (int i = 0; i < diem.size(); i++){
			tong += diem[i];
		}
		return tong / diem.size();
	}
};
int main(){
	Sinhvien a;
	a.Nhap();
	a.Xuat();
	system("pause");
	return 0;
}