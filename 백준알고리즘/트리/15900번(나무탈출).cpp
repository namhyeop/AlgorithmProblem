#include <bits/stdc++.h>

using namespace std;
const int MAX = 500000 +5;
int n;
vector<int> arr[MAX];
bool visited[MAX];
int leaf[MAX];

bool check(int cur){
    for(int c : arr[cur]){
        if(!visited[c])
            return false;
    }
    return true;
}

void search(int cur, int parent, int cost){
    if(check(cur)){
        leaf[cur] = cost;
        return;
    }

    visited[cur] = true;
    for(int next : arr[cur]){
        if(!visited[next]){
            search(next, cur, cost + 1);
            leaf[cur] += leaf[next];
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int p, c;
        cin >> p >> c;
        arr[p].push_back(c);
        arr[c].push_back(p);
    }

    search(1, -1, 0);
    if(leaf[1] % 2 == 0)
        cout << "No" <<"\n";
    else
        cout << "Yes" <<"\n";
}