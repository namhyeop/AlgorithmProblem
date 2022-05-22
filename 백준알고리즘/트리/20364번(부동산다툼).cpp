#include <bits/stdc++.h>

using namespace std;
const int MAX = 2000000;
int n, q;
bool visited[MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;

    for(int i = 0; i < q; i++){
        int land, copyLand;
        cin >> land;
        copyLand = land;

        int ret = 0;
        while(land){
            if(visited[land]){
                ret = land;
            }
            land >>= 1;
        }
        visited[copyLand] = 1;
        cout << ret <<"\n";
    }
}