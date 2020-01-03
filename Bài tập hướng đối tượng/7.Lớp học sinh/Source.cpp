#include<iostream>
#include<vector>
#include<string>
using namespace std;
class HocSinh{
	string ten;
	float van, toan;
public:
	void Nhap(){
		fflush(stdin);
		//cin.ignore();
		getline(cin, ten);
		cin >> van;
		cin >> toan;
		

	}
	void Xuat(){
		cout << ten << endl;
		cout << van << endl;
		cout << toan << endl;
	}
	string Get_ten(){
		return ten;
	}
	float Get_van(){
		return toan;
	}
	float Get_toan(){
		return toan;
	}
	void Set_ten(string t){
		ten = t;
	}
	void Set_toan(float diemtoan){
		toan = diemtoan;
	}
	void Set_van(float diemvan){
		van = diemvan;
	}
	float TinhDTB(){
		return (toan + van) / 2;
	}
	void Xeploaihocluc(){
		if (TinhDTB() >= 8){
			cout << "Gioi" << endl;
		}
		else if (TinhDTB() >= 7){
			cout << "Kha";
		}
		else if (TinhDTB() >= 5){
			cout << "Trung binh";
		}
		else{
			cout << "Yeu";
		}
	}

};
void Nhap(vector<HocSinh> &a, int &n){
	cin >> n;
	for (int i = 0; i < n; i++){
		HocSinh hs;
		hs.Nhap();
		a.push_back(hs);
	}
}
HocSinh Xeploai(vector<HocSinh>&a){
	HocSinh Max = a[0];
	for (int i = 1; i < a.size(); i++){
		if (Max.TinhDTB()<a[i].TinhDTB()){
			Max = a[i];
		}
	}
	return Max;

}
int main(){
	int n;
	vector<HocSinh> a;
	Nhap(a, n);
	HocSinh hs = Xeploai(a);
	cout << hs.Get_ten() << endl;
	hs.Xeploaihocluc();
	vector<int> t = { 1, 2, 3, 4 };
	cout << t[1];
	system("pause");
	return 0;
}