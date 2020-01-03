#include<iostream>
#include<string>
using namespace std;
class Napchongham{
public:
	void Napchongham_1(string t){
		cout << t << endl;
	}
	void Napchongham_1(int t){
		cout << t << endl;
	}
	double Napchongham_1(double t){
		return t;
	}
	bool Napchongham_1(bool t){
		return t;
	}
	
};
	
int main(){
	Napchongham nch;
	nch.Napchongham_1(2);
	nch.Napchongham_1("Nap chong ham");
	double a=nch.Napchongham_1(3.01);
	cout << a << endl;
	bool t=nch.Napchongham_1(true);
	cout << t << endl;
	system("pause");
	return 0;
}