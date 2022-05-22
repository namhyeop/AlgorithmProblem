#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
int n, r, q;
vector<int> arr[MAX];

int subTreeCnt[MAX];

void search_parent(int cur, int prev){
    subTreeCnt[cur] = 1;
    for(int next : arr[cur]){
        if(next != prev){
            search_parent(next, cur);
            subTreeCnt[cur] += subTreeCnt[next];
        }
    }
}

void input(){
    cin >> n >> r >> q;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    search_parent(r, -1);
}

void pro(){
    for(int t = 0; t < q; t++){
        int target; cin >> target;
        cout << subTreeCnt[target] <<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}