#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string numeros; cin >> numeros;
    int contador = 0;

    for(int i = 0; i < numeros.size(); i++){
        string subnumeros;
        for(int j = i; j < i + 4; j++)
            subnumeros += numeros[j];
        if(subnumeros < "2000"){
            i += 3;
            contador ++;
        } else {
            i += 2;
            contador ++;
        }
    }
    cout << contador << " ";
    contador = 0;

    for(int i = numeros.size(); i > 0;){
        string subnumeros;
        for(int j = i - 4; j < i; j++)
            subnumeros += numeros[j];
        if(subnumeros < "2000"){
            i -= 4;
            contador ++;
        }else{
            i -= 3;
            contador ++;
        }
    }
    cout << contador << endl;
    return 0;
}
