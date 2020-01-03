#include<iostream>
#include<vector>
using namespace std;
class Mang{
	vector<int> a;
public:
	void Nhap(){
		while (1){
			int k;
			cin >> k;
			if (k == -1){
				break;
			}
			a.push_back(k);

		}
	}
	void Xuat(){
		for (int i = 0; i < a.size(); i++){
			cout << a[i];
		}
	}
};
int main(){
	Mang a;
	a.Nhap();
	a.Xuat();
	system("pause");
	return 0;
}
