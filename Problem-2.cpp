#include <iostream>
#include <stdalign.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int casos, llantas = 0, puertas = 0, quemaCocos = 0, cofres = 0, cajuela = 0;
    cin >> casos;
    cin.ignore();

    for(int i = 0; i < casos; i++){
        string nombre, piezas1, piezas2, piezas3;
        getline(cin, nombre);

        cin >> piezas1 >> piezas2 >> piezas3;
        if(piezas1[0] == '#') llantas++;
        if(piezas1[2] == '#') llantas++;
        if(piezas3[0] == '#') llantas++;
        if(piezas3[2] == '#') llantas++;
        if(piezas1[1] == '#') puertas++;
        if(piezas3[1] == '#') puertas++;
        if(piezas2[0] == '#') cajuela++;
        if(piezas2[1] == '#') quemaCocos++;
        if(piezas2[2] == '#') cofres++;
        cin.ignore();
    }
    cout << llantas << endl;
    cout << puertas << endl;
    cout << cofres << endl;
    cout << quemaCocos << endl;
    cout << cajuela << endl;
    return 0;
}