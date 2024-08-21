#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string.h>

using namespace std;

#define iosbase  ios_base::sync_with_stdio(0);
typedef unsigned long long Ull;

struct variable{
    string nombre;
    int casos;
    string lineas;
};

unsigned long long binary(string lon){
    int size = lon.size();
    unsigned long long numero = 0;
    
    for(int i = 0; i < size; i++){
        char n = lon[size - 1 - i];
        unsigned long long potencia = 1ULL << i;
        numero += (n - '0') * potencia;
    }
    return numero;
}

int main() {
    iosbase;
    cin.tie(0);

    int bytes, n, cases = 0; 
    
    while(cin >> bytes >> n){
        map <string, unsigned long long> result;
        vector <variable> variables;

        while(n--){
            string name; cin >> name;
            int y; cin >> y;
            cin.clear();
            variables.push_back({name, y, ""}); cases += y;
            result[name] = 0;
        }

        int pos = 0;
        while(cases != 0){
            int m = variables[pos].casos;
            string name = variables[pos].nombre;
            string bin;
            for(int i = 0; i < m; i++){
                cin >> bin;
                variables[pos].lineas += bin;
            }
            result[name] = binary(variables[pos].lineas);
            cases -= m; pos ++;
        }

        int k; cin >> k;
        while(k--){
            string bus; cin >> bus;
            if(!result.count(bus)) cout << bus << "=" << endl;
            else cout << bus << "=" << result[bus] << endl;
        }
    }
    return 0;
}