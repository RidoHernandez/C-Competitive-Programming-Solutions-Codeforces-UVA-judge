#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int a, b; cin >> a >> b;
    bitset <1000 + 1> primos;
    
    primos.set();
    primos[0] = 0, primos[1] = 0;
    for(int i = 2; i * i <= 1000; i++){
        if(primos[i]){
            for(int j = i * i; j <= 1000; j += i){
                primos[j] = 0;
            }
        }
    }
    
    int cont = 0;
    for(int i = a; i <= b; i++){
        cont += primos[i];
    }
    cout << cont << endl;
    return 0;
}