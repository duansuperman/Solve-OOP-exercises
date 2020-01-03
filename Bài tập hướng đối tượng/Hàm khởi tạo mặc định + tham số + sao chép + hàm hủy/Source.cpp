#include<iostream>
using namespace std;
int Ucln(int a, int b);
class Phanso{
private:
	int tu, mau;
public:
	int dem=0;
	void Nhapphanso(){
		cout << "Nhap tu so : ";
		cin >> tu;
		cout << "Nhap mau so : ";
		cin >> mau;
	}
	void Xuatphanso(){
		cout << "Xuat phan so : " << tu << "/" << mau << endl;
	}
	//hàm khởi tạo mặc định :
	Phanso(){
		tu = 0;
		mau = 1;
		dem++;
	}
	//hàm khởi tạo có tham sô
	Phanso(int a, int b){
		tu = a;
		mau = b;
	}
	//hàm khởi tạo sao chép
	Phanso(const Phanso &a){
		tu = a.tu;
		mau = a.mau;
	}
	//Hàm gủy :
	~Phanso(){
		//Có con trỏ mới xây dựng
	}
	Phanso Cong2phanso(Phanso a){
		Phanso tong;
		tong.tu = a.tu*mau + a.mau*tu;
		tong.mau = a.mau*mau;
		return tong;
	}
	void Rutgonphanso(){
		int ucln = Ucln(tu, mau);
		tu /= ucln;
		mau /= ucln;
	}
};

int Ucln(int a, int b){
	if (a < 0){
		a *= -1;
	}
	if (b < 0){
		b *= -1;
	}
	while (a != b){
		if (a < b){
			a -= b;
		}
		else{
			b -= a;
		}
	}
	return a;
}
int main(){
	Phanso ps1;
	ps1.Nhapphanso();
	ps1.Xuatphanso();
	cout << ps1.dem << endl;
	system("pause");
	return 0;
}