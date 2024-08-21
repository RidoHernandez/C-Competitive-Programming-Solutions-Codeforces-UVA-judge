#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool existePalabra(vector<vector<char>>& matriz, const string& palabra) {
    for (const vector<char>& fila : matriz) {
        if (palabra.size() != fila.size()) continue;
        
        bool igual = true;
        for (int i = 0; i < palabra.size(); i++) {
            if (palabra[i] != fila[i]) {
                igual = false;
                break;
            }
        }
        if (igual) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<char>> matriz;
    string nombre;
    
    while (n--) {
        cin >> nombre;
        if (!existePalabra(matriz, nombre)) {
            matriz.push_back(vector<char>(nombre.begin(), nombre.end()));
        } else {
            cout << "Ese nombre ya existe" << endl;
        }
    }
    cout << matriz.size() << endl;
    for (const vector<char>& fila : matriz) {
        for (char c : fila) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}