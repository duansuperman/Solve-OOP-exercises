#include<iostream>
#include<string>
using namespace std;
class Employee{
	int id;
	string firstName;
	string  lastname;
	double salary;
public :
	void Nhap(){
		cin >> id;
		cin.ignore();
		getline(cin, firstName);
		getline(cin, lastname);
		cin >> salary;
	}
	void Xuat(){
		double luong = salary * 100;
		luong = (int)luong;
		luong /= 100;
		cout << "Employee[id=" << id << ",name=" << firstName << " " << lastname << ",salary=" << luong << "]" << endl;
	}
	Employee(){
		id = 0;
		firstName = "";
		lastname = "";
		salary = 0;
	}
	Employee(int a, string b, string c, double d){
		id = a;
		firstName = b;
		lastname = c;
		salary = d;
	}
	int getID(){
		return id;
	}
	string getLastName(){
		return lastname;
	}
	string getFirstName(){
		return firstName;
	}
	double getSalary(){
		return salary;
	}
	void setSalary(double a){
		salary = a;
	}
	double getAnnualSalary(){
		return 12 * salary;
	}
	double RaiseSalary(double a){
		return (1 + a)*salary;
	}
	/*string toString(){
		
		return t;
	}*/
	void  operator++(){
		salary = (1 + 0.1)*salary;
	

	}

};
int main(){
	Employee a;
	Employee b;
	a.Nhap();
	b.Nhap();
	double m, n;
	cin >> m >> n;
	a.Xuat();
	b.Xuat();
	if (a.getSalary() > b.getSalary()){
		cout << "LON HON" << endl;
	}
	else if (a.getSalary() == b.getSalary()){
		cout << "BANG NHAU" << endl;
	}
	else{
		cout << "NHO HON" << endl;
	}
	a++;
	double luong = a.getSalary() - m;
	luong *= 100;
	luong = (int)luong;
	luong /= 100;
	cout << luong << endl;
	//system("pause");
	return 0;
}