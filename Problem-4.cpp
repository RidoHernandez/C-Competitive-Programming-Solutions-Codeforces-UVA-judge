#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void func(vector<pair<int, int>>& inter, int n, int m) {
    vector<int> numeros(n + 1, 0);

    for (int i = 0; i < m; i++) {
        numeros[inter[i].first]++;
        numeros[inter[i].second]--;
    }

    int acumulado = 0;

    for (int i = 0; i < n; i++) {
        acumulado += numeros[i];
        cout << acumulado << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> intervalos;
    
    for (int i = 0; i < m; i++) {
        pair<int, int> num;
        int k, l; cin >> k >> l;
        num.first = k;
        num.second = l;
        intervalos.push_back(num);
    }
    func(intervalos, n, m);
    return 0;
}