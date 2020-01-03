#include<iostream>
#include<vector>
using namespace std;
class Dathuc{
	int n;
	vector<float>a;
public:
	void Nhap(){
		cin >> n;
		a.erase(a.begin());
		for (int i = 0; i < n; i++){
			int k;
			cin >> k;
			a.push_back(k);
		}
	}
	void Xuat(){
		for (int i = 0; i < n; i++){
			if (i == 0){
				cout << a[i];
			}
			else if (i == 1){
				if (a[i] == 0){
					continue;
				}
				else if (a[i] < 0){
					if (a[i] == -1){
						cout << "-x";
					}
					else{
						cout << a[i] << "x";
					}
				}
				else{
					if (a[i] == 1){
						cout << "+" << "x" ;
					}
					else{
						cout << "+" << a[i] << "x";
					}
				}
			}
			else{
				if (a[i] == 0){
					continue;
				}
				else if (a[i] < 0){
					if (a[i] == -1){
						cout << "-x^" << i;
					}
					else{
						cout << a[i] << "x^" << i;
					}
				}
				else{
					if (a[i] == 1){
						cout << "+"<< "x^" << i;
					}
					else{
						cout << "+" << a[i] << "x^" << i;
					}
				}
			}
		}
		cout << endl;
	}
	Dathuc(){
		n = 0;
		a.push_back(0);
	}
	Dathuc(int k, vector<float>&b){
		n = k;
		for (int i = 0; i < k; i++){
			a.push_back(b[i]);
		}

	}
	Dathuc(int k){
		n = k;
		for (int i = 0; i < n; i++){
			a.push_back(1);
		}
	}
	float getGiatri(int gt){
		float Tong = 0;
		for (int i = 0; i < n; i++){
			Tong += a[i] * pow(gt, i);
		}
		return Tong;
	}
	Dathuc getDaoHamB1(){
		Dathuc dt;
		dt.a.erase(dt.a.begin());
		dt.n = n-1;
		for (int i = 1; i < a.size(); i++){
			dt.a.push_back(a[i] * i);
		}
		return dt;
	}
	friend istream& operator >>(istream&is, Dathuc&dt){
		is >> dt.n;
		dt.a.erase(dt.a.begin());
		for (int i = 0; i < dt.n; i++){
			int k;
			cin >> k;
			dt.a.push_back(k);
		}
		return is;
	}
	friend ostream& operator<<(ostream&os, Dathuc dt){
		for (int i = 0; i < dt.n; i++){
			if (i == 0){
				cout << dt.a[i];
			}
			else if (i == 1){
				if (dt.a[i] == 0){
					continue;
				}
				else if (dt.a[i] < 0){
					if (dt.a[i] == -1){
						cout << "-x";
					}
					else{
						cout << dt.a[i] << "x";
					}
				}
				else{
					if (dt.a[i] == 1){
						cout << "+" << "x";
					}
					else{
						cout << "+" << dt.a[i] << "x";
					}
				}
			}
			else{
				if (dt.a[i] == 0){
					continue;
				}
				else if (dt.a[i] < 0){
					if (dt.a[i] == -1){
						cout  << "-x^" << i;
					}
					else{
						cout << dt.a[i] << "x^" << i;
					}
				}
				else{
					if (dt.a[i] == 1){
						cout << "+" << "x^" << i;
					}
					else{
						cout << "+" << dt.a[i] << "x^" << i;
					}
				}
			}
		}
		cout << endl;
		return os;
	}
	float operator[](int id){
		return a[id];
	}
	Dathuc operator+(Dathuc b){
		Dathuc cong;
		cong.a.erase(cong.a.begin());
		if (n == b.n){
			cong.n = n;
			for (int i = 0; i < n; i++){
				cong.a.push_back(a[i] + b.a[i]);
			}
		}
		else if (n < b.n){
			cong.n = b.n;
			for (int i = 0; i < n; i++){
				cong.a.push_back(a[i] + b.a[i]);
			}
			for (int i = n; i < b.n; i++){
				cong.a.push_back(b.a[i]);
			}

		}
		else{
			cong.n = n;
			for (int i = 0; i < b.n; i++){
				cong.a.push_back(a[i] + b.a[i]);
			}
			for (int i = b.n; i < n; i++){
				cong.a.push_back(a[i]);
			}
		}
		return cong;
	}
	Dathuc operator-(Dathuc b){
		Dathuc tru;
		tru.a.erase(tru.a.begin());
		if (n == b.n){
			tru.n = n;
			for (int i = 0; i < n; i++){
				tru.a.push_back(a[i] - b.a[i]);
			}
		}
		else if (n < b.n){
			tru.n = b.n;
			for (int i = 0; i < n; i++){
				tru.a.push_back(a[i] - b.a[i]);
			}
			for (int i = n; i < b.n; i++){
				tru.a.push_back(-1*b.a[i]);
			}

		}
		else{
			tru.n = n;
			for (int i = 0; i < b.n; i++){
				tru.a.push_back(a[i] - b.a[i]);
			}
			for (int i = b.n; i < n; i++){
				tru.a.push_back(a[i]);
			}
		}
		return tru;
	}
};
int main(){
	Dathuc dt1;
	cin >> dt1;
	
	cout <<"dt1 = "<< dt1;
	cout << "Gia tri cua dt1 khi k = 2 la " << dt1.getGiatri(2) <<endl;
	cout << "Bieu thuc sau khi dao ham cap 1 : ";
	Dathuc dtdh = dt1.getDaoHamB1();
	dtdh.Xuat();
	cout << "Lay gia tri tai vi tri ak tai vi tri = 2 la : " << dt1[2] << endl;
	Dathuc dt2;
	cin >> dt2;
	cout << "dt2 = " << dt2;
	Dathuc tong = dt1 + dt2;
	cout <<"Tong khi cong dt1 + dt2 = "<< tong;
	Dathuc tru = dt1 - dt2;
	cout << "Tong khi cong dt1 - dt2 = " << tru;
	system("pause");
	return 0;
}