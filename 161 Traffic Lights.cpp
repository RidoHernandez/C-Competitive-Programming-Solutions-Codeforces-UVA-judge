#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using  namespace std;
struct semaforo{
    int len;
    int estado;
    int tiemCont;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    vector <int> numeros;
    while(getline(cin, input)){
        istringstream iss(input);
        int x;

        while(iss >> x)
            numeros.push_back(x);
    }

    vector <semaforo> semaforos;
    for(int i = 0; i < numeros.size() - 3; i++){
        if(numeros[i] == 0){
            bool starGreen = true;
            bool findSolution = false;

            for(int sg = 0; sg <= 18000; sg++){
                bool green = true;
                for(int i = 0; i < semaforos.size(); i++){
                    semaforos[i].tiemCont ++;
                    if(semaforos[i].estado == 1 && semaforos[i].tiemCont > 5){
                        semaforos[i].estado = 2; semaforos[i].tiemCont = 1;
                    } else if (semaforos[i].estado == 0 && semaforos[i].tiemCont > semaforos[i].len - 5){
                        semaforos[i].estado = 1; semaforos[i].tiemCont = 1;
                    } else if (semaforos[i].estado == 2 && semaforos[i].tiemCont > semaforos[i].len){
                        semaforos[i].estado = 0; semaforos[i].tiemCont = 1;
                    }
                    if(semaforos[i].estado != 0){
                        green = false; starGreen = false;
                    }
                }
                if(green && !starGreen){
                    int tiempo = sg;
                    cout << setfill('0') << setw(2) << tiempo / 3600 << ":";
                    tiempo %= 3600;
                    cout << setfill('0') << setw(2) << tiempo / 60 << ":";
                    tiempo %= 60;
                    cout << setfill('0') << setw(2) << tiempo << endl;
                    findSolution = true; break;
                }
            }
            if(!findSolution)
                cout << "Signals fail to synchronise in 5 hours" << endl;
            semaforos.clear();
        }else semaforos.push_back({numeros[i], 0, 0});
    }
    return 0;
}