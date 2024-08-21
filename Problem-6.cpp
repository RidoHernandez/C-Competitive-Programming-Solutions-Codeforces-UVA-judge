#include <iostream>
#include <string.h>
#include <map>

using  namespace std;

int cambiar(int posi, string &word, int size){
    char letra = word[posi];
    
    for(int i = posi + 1; i < size; i++)
        if(word[i] == letra) word[i] = '0';
    
    return posi + 1;
}
void buscar(string &word){
    string pal = "helo";
    int size = word.size(); int pos = 0, k = 0;
    bool bandera = true;

    for(int i = pos; i < size; i++){
        if(pal[k] == 'l' && word[i] == pal[k] && bandera) i += 1, bandera = false;
        if(pal[k] == word[i]){
            pos = cambiar(i, word, size);
            k++;
        } else word[i] = '0';
    }

    string res;
    for(char c : word)
        if(c != '0') res += c;
    cout << (res == "hello" ? "YES" : "NO") << endl; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string work; cin >> work;
    buscar(work);
    return 0;
}