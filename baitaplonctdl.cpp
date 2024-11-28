#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;


class SinhVien {
private:
    string maSV;
    string hoTen;
    int tuoi;
    double diemTB;

public:
    SinhVien(string ma = "", string ten = "", int t = 0, double diem = 0.0)
        : maSV(ma), hoTen(ten), tuoi(t), diemTB(diem) {}

    friend istream& operator>>(istream& in, SinhVien& sv) {
        cout << "Nhap ma sinh vien: ";
        in >> sv.maSV;
        cout << "Nhap ho ten: ";
        in.ignore();
        getline(in, sv.hoTen);
        cout << "Nhap tuoi: ";
        in >> sv.tuoi;
        cout << "Nhap diem trung binh: ";
        in >> sv.diemTB;
        return in;
    }

    friend ostream& operator<<(ostream& out, const SinhVien& sv) {
        out << "Ma SV: " << sv.maSV
           << ", Ho ten: " << sv.hoTen
           << ", Tuoi: " << sv.tuoi
           << ", Diem TB: " << sv.diemTB;
        return out;
    }

    bool operator<(const SinhVien& other) const {
        return diemTB < other.diemTB;
    }

    string getMaSV() const { return maSV; }
    double getDiemTB() const { return diemTB; }
};

class DanhSachSinhVien {
private:
    list<SinhVien> danhSach;

public:
    void nhapDanhSach() {
        int soLuong;
        cout << "Nhap so luong sinh vien: ";
        cin >> soLuong;

        for (int i = 0; i < soLuong; ++i) {
            SinhVien sv;
            cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
            cin >> sv;
            danhSach.push_back(sv);
        }
    }

    void xuatDanhSach() const {
        cout << "Danh sach sinh vien:\n";
        for (const auto& sv : danhSach) {
            cout << sv << endl;
        }
    }

    void sapXepTheoDiem() {
        danhSach.sort();
    }

    SinhVien maxdiem() const {
        if (danhSach.empty()) {
            throw runtime_error("Danh sach rong");
        }
        return *max_element(danhSach.begin(), danhSach.end());
    }

    void xoaSinhVien(const string& maSV) {
        auto it = danhSach.begin();
        while (it != danhSach.end()) {
            if (it->getMaSV() == maSV) {
                it = danhSach.erase(it);
                cout << "Da xoa sinh vien co ma " << maSV << endl;
                return;
            } else {
                ++it;
            }
        }
        cout << "Khong tim thay sinh vien co ma " << maSV << endl;
    }

    void themSinhVien(const SinhVien& sv) {
        danhSach.push_back(sv);
    }
};

class app {
private:
    DanhSachSinhVien danhSach;

public:
    void hienThiMenu() {
        while (true) {
            cout << "\n----- QUAN LY SINH VIEN -----\n";
            cout << "1. Nhap danh sach sinh vien\n";
            cout << "2. Xuat danh sach sinh vien\n";
            cout << "3. Sap xep theo diem\n";
            cout << "4. Tim sinh vien diem cao nhat\n";
            cout << "5. Xoa sinh vien\n";
            cout << "6. Them sinh vien moi\n";
            cout << "0. Thoat\n";
            cout << "Chon chuc nang: ";

            int luaChon;
            cin >> luaChon;

            switch (luaChon) {
                case 1:
                    danhSach.nhapDanhSach();
                    break;
                case 2:
                    danhSach.xuatDanhSach();
                    break;
                case 3:
                    danhSach.sapXepTheoDiem();
                    cout << "Da sap xep xong!\n";
                    break;
                case 4: {
                    try {
                        SinhVien svMax = danhSach.maxdiem();
                        cout << "Sinh vien co diem cao nhat: " << svMax << endl;
                    } catch (const exception& e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
                case 5: {
                    string maSV;
                    cout << "Nhap ma sinh vien can xoa: ";
                    cin >> maSV;
                    danhSach.xoaSinhVien(maSV);
                    break;
                }
                case 6: {
                    SinhVien svMoi;
                    cout << "Nhap thong tin sinh vien moi:\n";
                    cin >> svMoi;
                    danhSach.themSinhVien(svMoi);
                    break;
                }
                case 0:
                    cout << "Ket thuc chuong trinh.\n";
                    return;
                default:
                    cout << "Lua chon khong hop le. Vui long thu lai.\n";
            }
        }
    }
};

int main() {
    app App
    App.hienThiMenu();
    return 0;
}

