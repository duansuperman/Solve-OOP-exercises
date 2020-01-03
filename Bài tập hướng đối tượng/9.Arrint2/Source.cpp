#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class ArrInt1{
	int n;
	vector<char> a;
public:
	void Nhap_n(){
		cin >> n;

	}
	void Nhap_mang(){
		a.erase(a.begin());
		for (int i = 0; i < n; i++){
			char k;
			cin >> k;
			a.push_back(k);
			if (k == '#'){

				break;
			}

		}
	}
	void Xuat(){
		cout << n << ": ";
		for (int i = n - 1; i >= 0; i--){
			cout << a[i];
		}
	}
	ArrInt1(){
		n = 1;
		a.push_back('0');
	}
	ArrInt1(int len){
		n = len;
		for (int i = 0; i< n; i++){
			a.push_back('1');
		}
	}
	ArrInt1(int m, vector<char>b){
		n = m;
		for (int i = 0; i < b.size(); i++){
			a.push_back(b[i]);
		}

	}

	int Get_len(){
		return n;
	}
	char Get_arr(){
		return a[0];
	}
	void Set_len(int len){
		n = len;
	}
	int Get_mod(int b){
		int Tong = 0;
		for (int i = 0; i < a.size(); i++){
			Tong += (a[i] - 48) % b;
		}
		return Tong;
	}
	vector<char> Getoldnumber(){

		vector<char>b;
		for (int i = 0; i < a.size(); i++){
			if ((a[i] - 48) % 2 != 0){
				b.push_back(a[i]);
			}
		}
		return b;

	}

};
int main(){
	ArrInt1 a;
	a.Nhap_n();
	int b;
	cin >> b;
	a.Nhap_mang();

	cout << a.Get_mod(b) << endl;
	vector<char> le = a.Getoldnumber();
	ArrInt1 arr_le(le.size(), le);
	arr_le.Xuat();
	system("pause");
	return 0;
}

//Không thể chèn vào vị trí đã push_back trước đó 
//a.push_back(5);
//a.push_back(1);