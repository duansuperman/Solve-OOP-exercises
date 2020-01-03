#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int dem = 0;
class Sophuc{
private: float phanthuc, phanao;
public:
	void Nhapsophuc(){
		cout << "Nhap phan thuc : ";
		cin >> phanthuc;
		cout << "Nhap phan ao : ";
		cin >> phanao;
	}
	void Xuatsophuc(){
		if (phanao > 0){
			cout << phanthuc << "+" << phanao << "i" << endl;
		}
		else if (phanao == 0){
			cout << phanthuc << endl;
		}
		else{
			cout << phanthuc << phanao << "i" << endl;
		}
	}
	Sophuc(){
		dem++;
		phanthuc = phanao = 0;
	}
	Sophuc(float a, float b){
		dem++;
		phanthuc = a;
		phanao = b;
	}
	Sophuc(const Sophuc&a){
		phanthuc = a.phanthuc;
		phanao = a.phanao;
	}
	~Sophuc(){

	}
	Sophuc Tinhtong2sophuc(Sophuc a){
		Sophuc tong;
		tong.phanthuc = phanthuc + a.phanthuc;
		tong.phanao = phanao + a.phanao;
		return tong;
	}
	float Getter_phanthuc(){
		return phanthuc;
	}
	float Getter_phanao(){
		return phanao;
	}
	void Setter_phanthuc(float a){
		phanthuc = a;
	}
	void Setter_phanao(float b){
		phanao = b;
	}
	Sophuc operator+(const Sophuc &a){
		Sophuc tong;
		tong.phanthuc = phanthuc + a.phanthuc;
		tong.phanao = phanao + a.phanao;
		return tong;
	}
	Sophuc operator-(const Sophuc &a){
		Sophuc tong;
		tong.phanthuc = phanthuc - a.phanthuc;
		tong.phanao = phanao - a.phanao;
		return tong;
	}
	float Tinhmodul(){
		return sqrt(pow(phanthuc, 2) + pow(phanao, 2));
	}
};
int main(){
	Sophuc a, b;
	a.Nhapsophuc();
	b.Nhapsophuc();
	a.Xuatsophuc();
	b.Xuatsophuc();
	Sophuc c = a-b;
	c.Xuatsophuc();
	cout << "Modul cua a = " << a.Tinhmodul() << endl;
	cout << "Modul cua b = " << b.Tinhmodul() << endl;
	//a.Tinhtong2sophuc(b).Xuatsophuc();
	system("pause");
	return 0;
}