#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 5;
int n, m;
int arrA[MAX], arrB[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arrA[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> arrB[i];
    }

    int ca = 1, cb = 1;
    while (ca <= n && cb <= m) {
        if (arrA[ca] <= arrB[cb]) {
            cout << arrA[ca++] << " ";
        } else {
            cout << arrB[cb++] << " ";
        }
    }

    for (int i = ca; i <= n; i++) {
        cout << arrA[i] << " ";
    }
    for (int i = cb; i <= m; i++) {
        cout << arrB[i] << " ";
    }
}