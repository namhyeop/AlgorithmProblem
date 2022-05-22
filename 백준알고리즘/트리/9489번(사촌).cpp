#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;
int n , k, arr[MAX], parent[MAX];

void input(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
}

void pro(){
    parent[0] = -1;
    parent[1] = 0;

    int last = 1;
    for(int i = 2; i <= n; i++, last++){
        for(; i <= n; i++){
            parent[i] = last;
            if(i < n && arr[i] + 1 != arr[i + 1]){
                break;
            }
        }
    }

    int kIdx = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] == k){
            kIdx = i;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(parent[parent[i]] == parent[parent[kIdx]] && parent[i] != parent[kIdx])
            ans++;
    }
    cout << ans <<"\n";
}
int main(){
    for(;;){
        input();
        if(n == 0 && k == 0)
            break;
        pro();
    }
}