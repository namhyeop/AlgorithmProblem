#include <bits/stdc++.h>

using namespace std;
const int MAX = 100005;
#define MOD 9901;

int n;
int a[MAX][2], cache[MAX][3];

void input(){
    cin >> n;
}

void pro(){
    cache[1][0] = 1;
    cache[1][1] = 1;
    cache[1][2] = 1;

    for(int i = 2; i <= n; i++){
        for(int prev = 0; prev <= 2; prev++){
            cache[i][0] += cache[i - 1][prev];
            cache[i][0] %= MOD
            for(int j = 0; j <= 1; j++){
                if(prev & (1 << j)) continue;
                cache[i][1 << j] += cache[i - 1][prev];
                cache[i][1 << j] %= MOD;
            }
        }
    }
    cout << (cache[n][0] + cache[n][1] + cache[n][2]) % MOD;
}
int main(){
    input();
    pro();
}