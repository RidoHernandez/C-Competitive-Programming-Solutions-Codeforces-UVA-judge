#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int calificacion, ponderacion; double promedio = 0;
    int aspectos;cin >> aspectos;
    
    for(int i = 0; i < aspectos; i++){
        cin >> calificacion >> ponderacion;
        for(int i = 0; i < calificacion; i++)
            cout << "*";
        cout << endl;
        promedio += double(calificacion) * (double(ponderacion) / 100);
    }
    if(promedio < 6){
        cout << "0" << endl;
        cout << ":(" << endl;
        return 0;
    } 
    promedio = round(promedio);
    if(promedio >= 6){
        cout << promedio << endl;
        cout << ":) " << endl;
    } 
    return 0;
}