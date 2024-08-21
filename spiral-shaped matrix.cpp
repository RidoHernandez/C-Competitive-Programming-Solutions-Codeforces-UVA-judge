#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector <vector <int> > matriz(105, vector<int>(105,-1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            matriz[i][j] = 0;
    
    int cont = 1, x = 1, y = 1, orientacion = 3;

    while(cont <= n * n){
        matriz[x][y] = cont;
        cont ++;
        if(orientacion == 1){
            if(matriz[x-1][y] != 0) orientacion = 3;
        }else if(orientacion == 2){
            if(matriz[x+1][y] != 0) orientacion = 4;
        }else if(orientacion == 3){
            if(matriz[x][y+1] != 0) orientacion = 2;
        }else if(orientacion == 4){
            if(matriz[x][y-1] != 0) orientacion = 1;
        }
        if(orientacion == 1) x--;
        else if(orientacion == 2) x++;
        else if(orientacion == 3) y++;
        else if(orientacion == 4) y--;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
    return 0;
}