#include<iostream>
#include<vector>

using namespace std;
class ArrInt{
	int n;
	vector<char>a;
public:
	void Nhap(){
		
		for (int i = 0; i < n; i++){
			char k;
			cin >> k;
			a.push_back(k);
		}
	}
	void Xuat(){
		cout << n << ": ";
		for (int i = n-1; i>= 0; i--){
			cout << a[i];
		}
		cout << endl;
	}
	ArrInt(){
		n = 1;
		a.push_back('0');
	}
	ArrInt(int k){
		n = k;
	}
	ArrInt operator-(ArrInt b){
		ArrInt tru;
		tru.a.erase(tru.a.begin());
		if (n > b.n){
			tru.n = n;
			
			for (int i = 0; i < n; i++){
				if (i < n - b.n){
					tru.a.push_back(a[i]);
				}
				else{
					int k = a[i] - b.a[i-(n-b.n)];
					if (k < 0){
						k *= -1;
					}
					tru.a.push_back((char)(k + 48));
				}
			}
		}
		else{
			tru.n = b.n;
			for (int i = 0; i < b.n; i++){
				if (i < b.n-n){
					tru.a.push_back(b.a[i]);
				}
				else{
					int k = a[i-(b.n-n)] - b.a[i];
					if (k < 0){
						k *= -1;
					}
					tru.a.push_back((char)(k + 48));
				}
			}
		}
		return tru;
	}
};
int main(){
	int a, b;
	cin>>a >> b;
	ArrInt arr1(a);
	ArrInt arr2(b);
	arr1.Nhap();
	arr2.Nhap();
	ArrInt tru = arr1 - arr2;
	tru.Xuat();
	//system("pause");
	return 0;
}