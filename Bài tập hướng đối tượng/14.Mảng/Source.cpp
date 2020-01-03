#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class Arr{
	vector<int>a;
public :
	void Nhapmang(){
		
		int k;
		a.erase(a.begin());
		
		while (cin >> k){

			a.push_back(k);
		}
	}
	void Xuatmang(){
		for (int i = 0; i < a.size(); i++){
			cout << a[i] ;
		}
		cout << endl;
	}
	Arr(){
		a.push_back(0);
	}
	Arr(const Arr & b){
		a = b.a;
	}
	int Get_size(){
		return a.size();
	}
	void Tangdan(){
		sort(a.begin(), a.end());
	}
	void Giamdan(){
		sort(a.begin(), a.end(), greater<int>());
	}
	void Addkdonvi(int k){
		for (int i = 0; i < a.size(); i++){
			a[i] += k;
		}
	}
	void Addkbegin(int k){
		a[0] += k;
	}
	bool Timso(int s){
		for (int i = 0; i < a.size(); i++){
			if (a[i] == s){
				return true;
			}
			
		}
		return false;
	}
};
int main(){
	int s;
	cin >> s;
	Arr a;
	a.Nhapmang();
	cout << a.Get_size() << endl;
	if (a.Timso(s)){
		cout << "TRUE" << endl;
	}
	else{
		cout << "FALSE" << endl;
	}
	Arr b(a);#
	b.Tangdan();
	
	b.Xuatmang();
	a.Addkbegin(1);
	a.Giamdan();
	a.Xuatmang();

	//system("pause");
	return 0;
}