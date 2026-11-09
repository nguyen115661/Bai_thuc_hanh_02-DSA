#include <bits/stdc++.h>

using namespace std;

class SinhVien {
    private:
        string name;
        int ID;
        float d1,d2,d3;
    public:
    void inp(){
        cin.ignore(); //xoa bo dem
        getline(cin, name);
        cin >> ID >> d1 >> d2 >> d3;
    }
    void outp(){
        cout << "Ten: " <<  name << endl;
        cout << "MaSinhVien: " << ID << "" << endl;
        cout << "Diem mon 1: ";
        cout << fixed << setprecision (2) << "Diem mon 1: " << d1 <<endl;
        cout << "Diem mon 2: "<< d2 << endl;
        cout << "Diem mon 3: " << d3 << endl;
    }
};

int main (){
    int n;
    cin >> n;
    vector <SinhVien> dsSV(n);

    for (int i = 0; i < n; i++){
        dsSV[i].inp();
    }
    for (int i = 0; i < n; i++){
        dsSV[i].outp();
    }
    return 0;
}