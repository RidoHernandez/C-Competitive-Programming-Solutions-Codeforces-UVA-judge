//PROBLEM OF CODEFORCES

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define iosbase  ios_base::sync_with_stdio(0);

struct publicacion{
    int posicion;
    int alta;
    int baja;
};

int main() {
    iosbase;
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector <int> likes(m + 1, 0);
    for(int i = 1; i <= m; i++){
        cin >> likes[i];
    }

    vector <int> post(n + 1, 0);
    vector <publicacion> publicaciones;
    for(int i = 0; i <= n; i++){
        publicaciones.push_back({i, i, i});
        post[i] = i;
    }

    for(int i = 1; i <= m; i++){
        int Postlike = likes[i];

        if(publicaciones[Postlike].posicion != 1){
            int posi = publicaciones[Postlike].posicion;
            int next = post[posi - 1];

            swap(post[posi], post[posi - 1]);

            int alta = publicaciones[Postlike].alta;
            int baja = publicaciones[next].baja;

            publicaciones[Postlike].posicion -= 1;
            publicaciones[next].posicion += 1;

            publicaciones[Postlike].alta = min(alta, publicaciones[Postlike].posicion);
            publicaciones[next].baja = max(baja, publicaciones[next].posicion);
        }        
    }
    for(int i = 1; i <= n; i++)
        cout << publicaciones[i].alta << " " << publicaciones[i].baja << endl;
    return 0;
}