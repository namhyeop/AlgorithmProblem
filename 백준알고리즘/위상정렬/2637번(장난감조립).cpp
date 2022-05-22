#include <bits/stdc++.h>

using namespace std;
const int MAX = 101;
int n, m, k;
int cnt[MAX][MAX], indegree[MAX];
vector<pair<int, int>> arr[MAX];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        arr[y].push_back({x, k});
        indegree[x]++;
    }
}

void pro() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            cnt[i][i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto next: arr[cur]) {
            auto[x, k] = next;
            indegree[x]--;
            for(int i = 1; i <= n; i++)
                cnt[x][i] += cnt[cur][i] * k;
            if(indegree[x] == 0) q.push(x);
        }
    }
    for(int i = 1; i<= n; i++){
        if(cnt[n][i] != 0){
            cout << i << " " << cnt[n][i] << "\n";
        }
    }
}

int main() {
    input();
    pro();
}
//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 101;
//int n, m;
//vector<int> arr[MAX];
//int needBoard[MAX][MAX];
//int indegre[MAX], toyNum[MAX], ret[MAX];
//bool visited[MAX];
////arr[i][j]를 만드는데 k개의 기본부품이 필요하다.
//void input(){
//    cin >> n >> m;
//    for(int i = 0; i < m; i++){
//        int x, y, k; cin >> x >> y >> k;
//        visited[x] = true;
//        arr[x].push_back(y);
//        needBoard[x][y] = k;
//        indegre[y]++;
//    }
//}
//
//void pro(){
//    queue<int> q;
//    for(int i = 1; i <= n; i++){
//        if(indegre[i] == 0) {
//            ret[i] = 1;
//            q.push(i);
//        }
//    }
//
//    while(!q.empty()){
//        auto cur = q.front();
//        q.pop();
//        for(auto next : arr[cur]){
//            indegre[next]--;
//            ret[next] += ret[cur] * needBoard[cur][next];
//            if(indegre[next] == 0) q.push(next);
//        }
//    }
//    for(int i = 1; i <= n; i++){
//        if(!visited[i])
//            cout << i << " " << ret[i] <<"\n";
//    }
//}
//int main(){
//    input();
//    pro();
//}