#include<iostream>
using namespace std;
class Phanso{
	int tu, mau;
public:
	void Nhap(){
		cin >> tu;
		cin >> mau;
	}
	
	void Xuat(){
		if (mau < 0){
			tu *= -1;
			mau *= -1;
		}
		cout << tu << "/" << mau << endl;
	}
	Phanso(){
		tu = 0;
		mau = 1;
	}
	Phanso(int a, int b){
		tu = a;
		mau = b;
	}
	Phanso(const Phanso&a){
		tu = a.tu;
		mau = a.mau;
	}
	~Phanso(){
		//Neu co con tro thi huy ;
	}
	Phanso Tinhtong(Phanso a){
		Phanso tong;
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = mau*a.mau;
		return tong;
	}
	Phanso operator+(Phanso a){
		Phanso tong;
		tong.tu = tu*a.mau + mau*a.tu;
		tong.mau = mau*a.mau;
		return tong;
	}
	Phanso operator+(int n){
		Phanso b(n, 1);
		return b + *this;
	}
	Phanso Tinhhieu(Phanso a){
		Phanso hieu;
		hieu.tu = tu*a.mau - a.tu*mau;
		hieu.mau = mau*a.mau;
		return hieu;
	}
	Phanso operator-(Phanso a){
		Phanso hieu;
		hieu.tu = tu*a.mau - a.tu*mau;
		hieu.mau = a.mau*mau;
		return hieu;
	}
	Phanso operator-(int n){
		Phanso b(n, 1);
		return *this - b;
	}
	friend  Phanso operator+(int n, Phanso a){
		return a + n;
	}
	friend istream & operator>>(istream &is, Phanso &a){
		is >> a.tu;
		is >> a.mau;
	
		return is;
	}
	friend ostream& operator<<(ostream &os, Phanso a){
		os << a.tu << "/" << a.mau << endl;
		return os;
	}
	Phanso & operator=(const Phanso & a){
		this->tu = a.tu;
		this->mau = a.mau;
		return *this;
	}
	void operator+=(Phanso a){
		/*tu = tu*a.mau + mau*a.tu;
		mau = mau*a.mau;*/
		*this = *this + a;
	}
	int Get_tu(){
		return tu;
	}
	Phanso operator++(){
		Phanso ps(1, 1);
		*this = *this + ps;
		return *this;
	}
	Phanso operator++(int x){
		Phanso ps(1, 1);
		Phanso temp = *this;
		*this = *this + ps;
		return temp;

	}

};
int main(){
	Phanso a;
	cin >> a;
	Phanso x = a++;
	cout << x << endl;
	cout << a << endl;
	system("pause");
	return 0;
}