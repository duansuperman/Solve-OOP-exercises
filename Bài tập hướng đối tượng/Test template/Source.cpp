#include<iostream>
#include<vector>
using namespace std;
template<class bien>
class Arr{
	int n;
	bien a[10];
public:
	void Nhap(){
		cin >> n;
		for (int i = 0; i < n; i++){
			bien k;
			cin >> k;
			a[i] = k;
		}
	}
	void Xuat(){
		for (int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}

};
template<class bien>
class Arr2{
	int n;
	bien a[10];
public:
	void Nhap(){
		cin >> n;
		for (int i = 0; i < n; i++){
			bien k;
			cin >> k;
			a[i] = k;
		}
	}
	void Xuat(){
		for (int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
};
int main(){
	Arr<float> a;
	Arr2<float> b;

	b.Nhap();
	b.Xuat();
	system("pause");
	return 0;
}