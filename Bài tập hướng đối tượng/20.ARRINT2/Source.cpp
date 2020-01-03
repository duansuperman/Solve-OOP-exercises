#include<iostream>
#include<vector>
using namespace std;
class ArrInt2{
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
		for (int i = a.size()-1; i >= 0; i--){
			cout << a[i];
		}
		cout << endl;
	}
	ArrInt2 operator-(ArrInt2 b){
		ArrInt2 tru;
		tru.a.erase(tru.a.begin());
		vector<char>c;
		if (n > b.n){
			tru.n = n;
			for (int i = n - 1; i >= 0; i--){
				if (i >= n-b.n){
					
					int k = a[i] - b.a[i-(n-b.n)];
					if (k < 0){
						k *= -1;
					}
					c.push_back((char)(k + 48));
				}
				else{
					c.push_back(a[i]);
				}
			}
		}
		else{
			tru.n = b.n;
			for (int i = b.n - 1; i >= 0; i--){
				if (i >= b.n-n){
					int k = b.a[i]-a[i-(b.n-n)];
					if (k < 0){
						k *= -1;
					}
					c.push_back((char)(k + 48));
				}
				else{
					c.push_back(b.a[i]);
					
				}
			}
		}
		for (int i = c.size() - 1; i >= 0; i--){
			tru.a.push_back(c[i]);
		}
		return tru;

	}
	ArrInt2(){
		n = 1;
		a.push_back('0');
	}
	ArrInt2(int k){
		n = k;
	}
};
int main(){
	int m, n;
	cin >> m >> n;
	ArrInt2 a(m);
	ArrInt2 b(n);
	
	a.Nhap();
	b.Nhap();
	ArrInt2 tru = a - b;
	tru.Xuat();
	//system("pause");
	return 0;
}