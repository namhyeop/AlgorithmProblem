#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX = 100005;
vector<int> edge[MAX];
bool visited[MAX];
int ret[MAX];

void DFS(int cur) {
    visited[cur] = true;
    for (auto next: edge[cur]) {
        if (!visited[next]) {
            DFS(next);
            //2.가장 깊은 우선탐색을 한뒤 끝날 경우 자신의 부모를 넣어준다.
            ret[next] = cur;
        }
    }
}

void pro() {
    DFS(1);
    for(int i = 2; i <= n; i++){
        cout << ret[i] <<"\n";
    }
}

void input() {
    cin >> n;
    //1.간선 만들기
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
}

int main() {
    input();
    pro();
}