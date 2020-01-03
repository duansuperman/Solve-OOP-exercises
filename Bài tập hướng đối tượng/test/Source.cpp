#include<iostream>
#include<vector>
#include<string>
using namespace std;
class HCN{
protected: int a, b;
public:
	friend istream& operator>>(istream& is, HCN& h){
		cin >> h.a >> h.b;
		return cin;
	}
	int Dientich(){
		return a*b;
	}
	int Chuvi(){
		return (a + b) * 2;
	}
};
class HV :public HCN{
public:
	friend istream& operator>>(istream& is, HV& h){
		int k;
		cin >> k;
		h.a = h.b = k;
		return cin;
	}
};
int main(){
	string t;
	vector<HCN>a;
	vector<HV> b;
	cin >> t;
	if (t == "HCN"){
		HCN h;
		while (cin >> h){
			a.push_back(h);
		}
		int Max = a[0].Chuvi();
		for (int i = 0; i<a.size(); i++){
			if (Max<a[i].Chuvi()){
				Max = a[i].Chuvi();
			}
		}
		cout << Max << endl;
	}
	else{
		HV h;
		while (cin >> h){
			b.push_back(h);
		}
		int Max = b[0].Chuvi();
		for (int i = 0; i<b.size(); i++){
			if (Max<b[i].Chuvi()){
				Max = b[i].Chuvi();
			}
		}
		cout << Max << endl;
	}
	system("pause");
	return 0;
}