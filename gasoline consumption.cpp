#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void consumoPorDia(vector <pair <int, int> > &vect, int &n){
    for(int i = 0; i < 7; i++){
        int consumo = vect[i].first * n;
        if(consumo > vect[i].second){
            int exedio = vect[i].second - consumo;
            vect[i + 1].second += exedio;
            cout << exedio << " ";
        } else {
            int sobro = vect[i].second - consumo;
            vect[i + 1].second += sobro;
            cout << sobro << " ";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, n; cin >> l >> n;
    int dia;
    vector <pair <int, int> > dias;
    
    for(int i = 0; i < 7; i++){
        cin >> dia;
        dias.emplace_back(dia, l);
    }
    consumoPorDia(dias, n);
}