#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin. tie(0);

    int n, m; cin >> n >> m;
    vector <string> nombres(n);
    string nombre;
    
    for(int i = 0; i < m; i++){
        cin >> nombre;
        nombres[i] = nombre;
    }
    int k, cont = 0; cin >> k;
    while(k--){
        char pregunta; cin >> pregunta;
        if(pregunta == 'P'){
            string busca; cin >> busca;
            int posicion;
            for(int i = 0; i < m; i++){
                if(nombres[i] == busca){
                    posicion = ((i + cont) % n) + 1;
                    break;
                } 
            }
            cout << posicion << endl;
        } else if(pregunta == 'T') cont ++;
    }
    return 0;
}