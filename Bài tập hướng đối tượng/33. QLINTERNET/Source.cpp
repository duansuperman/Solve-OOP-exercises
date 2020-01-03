#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Khachhang{
protected:

	string ten;
	int thoigian;
	int somay;
	int dongia;
public:
	void Nhap(){
		getline(cin, ten);
		cin >> thoigian >> somay;
	}
	virtual void Xuat(){

	}
	virtual int Tinhtien() = 0;
};
class Vip : public Khachhang{
	int dongiavip;
public:
	void Nhap(int a, int b){
		Khachhang::Nhap();
		dongiavip = a;
		dongia = b;
	}
	void Xuat(){
		cout << "Loai khach: VIP" << endl;
		cout << "Ho Ten: " << ten << endl;
		cout << "Thoi gian su dung: " << thoigian << endl;
		cout << "So may: " << somay << endl;
		cout << Tinhtien() << endl;
	}
	int Tinhtien(){
		if (thoigian >= 4){
			return dongiavip*thoigian;
		}
		else{
			return dongia*thoigian;
		}
	}
};
class Tx : public Khachhang{
	int hesokm;
public:
	void Nhap(int b){
		Khachhang::Nhap();
		cin >> hesokm;
		dongia = b;
	}
	void Xuat(){

		cout << "Loai khach: TX" << endl;
		cout << "Ho Ten: " << ten << endl;
		cout << "Thoi gian su dung: " << thoigian << endl;
		cout << "So may: " << somay << endl;
		cout << Tinhtien() << endl;
	}
	int Tinhtien(){
		return thoigian*(dongia - hesokm);
	}
};
class Ktx : public Khachhang{
	int dungluong;
	int dongiadowload;
public:
	void Nhap(int a, int b){
		Khachhang::Nhap();
		cin >> dungluong;
		dongiadowload = a;
		dongia = b;
	}
	void Xuat(){
		cout << "Loai khach: VIP" << endl;
		cout << "Ho Ten: " << ten << endl;
		cout << "Thoi gian su dung: " << thoigian << endl;
		cout << "So may: " << somay << endl;
		cout << Tinhtien() << endl;
	}
	int Tinhtien(){
		return (thoigian*dongia + dungluong*dongiadowload);
	}
};
int main(){
	int n;
	int dongia, dongiavip, dongiadowload;
	cin >> n >> dongia >> dongiavip >> dongiadowload;
	Khachhang *a[100];
	Vip b[100];
	Tx c[100];
	Ktx d[100];
	cin.ignore();
	for (int i = 0; i < n; i++){
		string t;
		getline(cin, t);
		if (t[0] == 'V'){
			
			b[i].Nhap(dongiavip, dongia);
			cin.ignore();
			a[i] = &b[i];


		}
		else if (t[0] == 'T'){
			
			c[i].Nhap(dongia);
			cin.ignore();
			a[i] = &c[i];

		}
		else{
			
			d[i].Nhap(dongiadowload, dongia);
			cin.ignore();
			a[i] = &d[i];

		}

	}
	for (int i = 0; i < n; i++){
		cout << i + 1 << ": ";
		a[i]->Xuat();
	}


	//system("pause");
	return 0;
}