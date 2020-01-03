#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Robot{
protected:
	string name, username;
	int e;
	int x, y;
public:
	void Nhap(string t){

		name = t;
		getline(cin, username);
		cin >> e;
		cin >> x >> y;
		cin.ignore();
	}
	void Xuat(){
		cout << "{" << name << "}:{" << username << "}" << endl;
		cout << "(" << x << "," << y << ")" << endl;
		cout << e << endl;
	}
	Robot(string a, string b, int c, int d){
		name = a;
		username = b;
		e = 100;
		x = c;
		y = d;
	}
	Robot(string a, string b){
		name = a;
		username = b;
		x = y = 0;
		e = 100;
	}
	Robot(){
		name = "Robot";
		username = "NoName";
		x = y = 0;
		e = 100;
	}
	Robot(const Robot &a){
		name = a.name;
		username = a.username;
		x = a.x;
		y = a.y;
		e = a.e;
	}
	void Charge(){
		e += 10;
	}
	bool Move(int dir){
		if (e <= 0){
			return false;
		}
		else{
			if (dir == 0 || dir == 1 || dir == 2 || dir == 3){
				if (dir == 0){
					x -= 1;
				}
				if (dir == 1){
					x += 1;
				}
				if (dir == 2){
					y += 1;
				}
				if (dir == 3){
					y -= 1;
				}
				e -= 5;
			}
			else{
				return false;
			}
		}
	}
	void Move_robot(string t){
		vector<int>a;
		for (int i = 0; i < t.length() - 2; i++){
			if (i % 2 == 0){

				a.push_back(t[i] - 48);

			}
		}
		for (int i = 0; i < a.size(); i++){
			if (e < 0){
				break;
			}
			if (a[i] == 0){
				x -= 1;
			}
			if (a[i] == 1){
				x += 1;
			}
			if (a[i] == 2){
				y += 1;
			}
			if (a[i] == 3){
				y -= 1;
			}

			if (a[i] == 4){
				Charge();
				continue;
			}
			e -= 5;



		}
	}
};
class AdaptiveRobot :public Robot{
public:
	void Move(string t){
		vector<int>a;
		for (int i = 0; i < t.length() - 2; i++){
			if (i % 2 == 0){
				a.push_back(t[i] - 48);

			}
		}

		int dem = 0;

		for (int i = 0; i < a.size(); i++){
			if (e < 0){
				break;
			}
			if (e>50){
				if (a[i] == 0){
					x -= 1;
				}
				if (a[i] == 1){
					x += 1;
				}
				if (a[i] == 2){
					y += 1;

				}
				if (a[i] == 3){
					y -= 1;
				}
				dem++;
				if (dem == 3){
					e -= 12;
					dem = 0;
				}
				continue;
			}
			if (e <= 50 && e > 20){
				if (a[i] == 0){
					x -= 1;
				}
				if (a[i] == 1){
					x += 1;
				}
				if (a[i] == 2){
					y += 1;
				}
				if (a[i] == 3){
					y -= 1;
				}
				dem++;
				if (dem == 2){
					e -= 9;
					dem = 0;
				}
				continue;
			}
			if (e <= 20){
				if (a[i] == 0){
					x -= 1;
				}
				if (a[i] == 1){
					x += 1;
				}
				if (a[i] == 2){
					y += 1;
				}
				if (a[i] == 3){
					y -= 1;
				}
				e -= 6;
				continue;
			}
			if (a[i] == 4){
				Charge();
			}


		}

	}
};
int main(){

	vector<AdaptiveRobot>a;
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++){
		string t;
		getline(cin, t);
		AdaptiveRobot c;
		c.Nhap(t);

		string k;
		getline(cin, k);
		if (t[0] == 'A'){
			c.Move(k);
		}
		else{
			c.Move_robot(k);
		}
		a.push_back(c);
	}
	for (int i = 0; i < a.size(); i++){
		a[i].Xuat();
	}
	//system("pause");
	return 0;
}