#include<iostream>
#include<string>
#include<vector>
using namespace std;
string Doichuoi(double a);
class BankAccount{
protected:
	string ID;
	string CustomerName;
	string IDCardNumber;
	double Balance;
	double WithdrawLimit;
public:
	BankAccount(){
		ID = "000000";
		CustomerName = "No name";
		IDCardNumber = "xxx";
		Balance = 0;
	}
	BankAccount(string id, string customername, string idcardnumber, double money){
		ID = id;
		CustomerName = customername;
		IDCardNumber = idcardnumber;
		Balance = money;
	}
	bool WithDraw(double withdrawmoney){
		if (withdrawmoney > WithdrawLimit){
			return 0;
		}
		return 1;
	}
	double Deposit(double depositmoney){
		Balance += depositmoney;
		return Balance;
	}
	string toString(){
		return "{" + ID + "}" + ":{" + CustomerName + "}:{" + Doichuoi(Balance) + "}";
	}
};

class CheckingAccount :public BankAccount{
	double OverDraftLimit;
public:
	
	double WithdrwLimit(){
		return Balance + OverDraftLimit;
	}
	CheckingAccount(){

	}
	CheckingAccount(string id, string customername, string idcardnumber, double money,double overdraftlimit){
		ID = id;
		CustomerName = customername;
		IDCardNumber = idcardnumber;
		Balance = money;
		OverDraftLimit = overdraftlimit;
		WithdrawLimit = Balance + OverDraftLimit;
	}
	bool WithDraw(double depositmoney){
		if (BankAccount::WithDraw(depositmoney)){
			Balance -= depositmoney;
			return 1;
		}
		return 0;
	}
};
class SavingAccount:public BankAccount{
	double InterestRate;
	double InterestMoney;
public:
	
	SavingAccount(){

	}
	SavingAccount(string id, string customername, string idcardnumber, double money){
		ID = id;
		CustomerName = customername;
		IDCardNumber = idcardnumber;
		Balance = money;
		
		WithdrawLimit = Balance;
	}
	double WithDrawLimit(){
		return Balance;
	}
	double Deposit(double depositmoney){
		BankAccount::Deposit(depositmoney);
	}
	bool WithDraw(double depositmoney){
		if (BankAccount::WithDraw(depositmoney)){
			Balance -= depositmoney;
			return 1;
		}
		return 0;
	}
	string toString(){
		if (Balance < 1000000){
			InterestMoney = Balance* 0.1;
		}
		else if (Balance >= 1000000 && Balance < 50000000){
			InterestMoney = Balance* 0.3;
		}
		else if (Balance >= 50000000 && Balance < 200000000){
			InterestMoney = Balance* 0.5;
		}
		else if (Balance >= 200000000 && Balance < 1000000000){
			InterestMoney = Balance * 1;
		}
		else{
			InterestMoney = Balance* 1.94;
		}
		return "{" + ID + "}" + ":{" + CustomerName + "}:{" + Doichuoi(Balance + InterestMoney) + "}";
	}
	
};

string Doichuoi(double a){
	string t = to_string(a);
	string chuoi = "";
	int dem = 0;
	
	for (int i = t.length() - 1; i >= 0; i--){
		if (t[i] == '0'){
			dem++;
		}
		if (t[i] == '.'){
			dem++;
			break;
		}
		if (t[i] != '0'){
			break;
		}
	}
	t.erase(t.length() - dem, dem);
	return t;
}
int main(){
	char k;
	cin >> k;
	if (k == 'C'){
		
		string t;
		cin >> t;
		vector<string>in;
		string chuoi = "";
		for (int i = 0; i < t.length(); i++){

			if (t[i] != '/'){
				chuoi += t[i];
			}
			if (i == t.length() - 1){
				in.push_back(chuoi);
			}
			if (t[i] == '/'){
				in.push_back(chuoi);
				chuoi = "";

			}
		}
		double rut;
		cin >> rut;
		CheckingAccount a(in[0], in[1], in[2], atof((char*)in[3].c_str()), atof((char*)in[4].c_str()));
		cout << a.toString() << endl;
		if (a.WithDraw(rut)){
			cout << "Yes " << a.toString() << endl;
		}
		else{
			cout << "No" <<endl;
		}
		cout << "Checking Account" << endl;
	}
	else{
		string t;
		cin >> t;
		vector<string>in;
		string chuoi = "";
		for (int i = 0; i < t.length(); i++){

			if (t[i] != '/'){
				chuoi += t[i];
			}
			if (i == t.length() - 1){
				in.push_back(chuoi);
			}
			if (t[i] == '/'){
				in.push_back(chuoi);
				chuoi = "";

			}
		}
		SavingAccount b(in[0],in[1],in[2],atof((char*)in[3].c_str()));
		
		double rut;
		cin >> rut;
		cout << b.BankAccount::toString() << endl;
		if (b.WithDraw(rut)){
			cout << "Yes " << b.BankAccount::toString() << endl;
		}
		else{
			cout << "No" << endl;
		}
		cout << b.toString() << endl;
	}
	system("pause");
	return 0;
	
}