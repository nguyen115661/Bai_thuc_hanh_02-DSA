#include <bits/stdc++.h>

using namespace std;

void inp (float *a, int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void outp (float *a, int n){
    for (int i = 0; i < n; i++){
        cout << fixed << setprecision(2) << a[i] << " ";
    }
}

int main (){
    float *a = nullptr;
    int n;
    cin >> n;
    a = new float[n]; 
    inp (a, n);
    outp (a, n);

    delete[] a; 

    return 0;
}
