#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX = 1005;
vector<int> board[MAX];
bool visited[MAX];

void DFS(int cur){
    visited[cur] = true;
    for(auto next : board[cur]){
        if(!visited[next])
            DFS(next);
    }
}

int pro(){
    int count = 0;
    for(int i = 1; i <= n ; i++){
        if(!visited[i]){
            DFS(i);
            count++;
        }
    }
    return count;
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int y, x;
        cin >> y >> x;
        board[y].push_back(x);
        board[x].push_back(y);
    }
}

int main(){
    input();
    cout << pro() << "\n";
}