#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Xacdinhnamnhuan(int);
class Ngaysinh{
	int ngay, thang, nam;
public:
	void Nhap(){
		int check;
		do{
			check = 1;

			do{
				cout << "Nhap ngay : ";
				cin >> ngay;
			} while (ngay<1 || ngay>31);
			do{
				cout << "Nhap thang : ";
				cin >> thang;
			} while (thang<1 || thang>12);
			do{
				cout << "Nhap nam : ";
				cin >> nam;
			} while (nam < 1949);
			if (thang == 4 || thang == 6 || thang == 9 || thang == 11){
				if (ngay>30){
					check = 0;
				}
			}
			if (thang == 2){
				if (Xacdinhnamnhuan(nam)){
					if (ngay > 29){
						check = 0;
					}
				}
				else{
					if (ngay > 28){
						check = 0;
					}
				}
			}
			if (check == 0){
				cout << "Thông tin ngày sinh không hợp lệ. Nhap lai : " << endl;
			}

		} while (check == 0);
	}
	void Xuat(){
		cout << ngay << "/" << thang << "/" << nam << endl;
	}
};

int Xacdinhnamnhuan(int x){
	return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}

class Sinhvien{
	string maso, hoten, lophoc, Cmnd;
	Ngaysinh ngay;
	float diemthi;
public:
	void Nhap(){
		cout << "Nhap ma so sinh vien : ";
		getline(cin, maso);
		cout << "Nhap ho ten sinh vien : ";
		getline(cin, hoten);
		cout << "Nhap so CMND : ";
		getline(cin, Cmnd);
		cout << "Nhap ngay sinh : " << endl;
		ngay.Nhap();
		cout << "Nhap diem thi chuyen nganh : ";
		cin >> diemthi;
		cin.ignore();
	}
	void Xuat(){
		cout << "\nXuat thong tin sinh vien : ";
		cout << "Ma so sinh  vien :  " << maso << endl;
		cout << "Ho ten sinh vien : " << hoten << endl;
		cout << "So CMND : " << Cmnd << endl;
		cout << "Ngay sinh : ";
		ngay.Xuat();
		cout << "Diem thi chuyen nganh : " << diemthi << endl;
	}
	float Getdiem(){
		return diemthi;
	}
	string Getten(){
		return hoten;
	}
};



void Hoanvi(Sinhvien &a, Sinhvien &b);
class Lophoc{
	int soluong;
	//Phải khai báo số lượng phần tử để khởi tạo số lượng phần tử trong mảng trước.
	Sinhvien *arr = new Sinhvien[3];
public:
	void Nhap(){
		do{
			cout << "Nhap so luong lop hoc : ";
			cin >> soluong;
			if (soluong <= 0){
				cout << "Thong tin so luong khong hop le. Yeu cau nhap lai : " << endl;
			}
		} while (soluong <= 0);
		cin.ignore();

		for (int i = 0; i < soluong; i++){
			cout << "\nNhap thong tin sinh vien thu " << i + 1 << endl;
			arr[i].Nhap();
		}
	}
	void Xuat(){
		for (int i = 0; i < soluong; i++){
			cout << "\nXuat thong tin sinh vien thu " << i + 1 << endl;
			arr[i].Xuat();
		}
	}
	float Diemcaonhat(){
		float Max = arr[0].Getdiem();
		for (int i = 0; i < soluong; i++){
			if (Max < arr[i].Getdiem()){
				Max = arr[i].Getdiem();
			}
		}
		return Max;
	}
	void Xuatsinhviendiemcao(){
		cout << "\nCac sinh vien co diem cao nhat : " << endl;
		vector<Sinhvien>ds;
		for (int i = 0; i < soluong; i++){
			if (Diemcaonhat() == arr[i].Getdiem()){
				ds.push_back(arr[i]);
			}
		}
		for (int i = 0; i < ds.size()-1; i++){
			for (int j = i + 1; j < ds.size(); j++){
				if (ds[i].Getten()>ds[j].Getten()){
					Hoanvi(ds[i], ds[j]);
				}
			}
		}
		for (int i = 0; i < ds.size() ; i++){
			ds[i].Xuat();
		}
	}
};

void Hoanvi(Sinhvien &a, Sinhvien &b){
	Sinhvien temp = a;
	a = b;
	b = temp;
}

int main(){
	Lophoc lh1;
	lh1.Nhap();
	lh1.Xuat();
	//cout << lh1.Diemcaonhat() << endl;
	lh1.Xuatsinhviendiemcao();
	/*Sinhvien sv1;
	sv1.Nhap();*/
	system("pause");
	return 0;
}