//트리 + DFS풀이
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int N, M;
int ans;
vector<pair<int, int>> arr[MAX];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        arr[x].push_back({d, y});
        arr[y].push_back({d, x});
    }
}

void DFS(int cur, int prev, int goal, int cost){
    if(cur == goal){
        ans = cost;
        return ;
    }

    for(auto next : arr[cur]){
        if(next.second != prev){
            DFS(next.second, cur, goal, cost + next.first);
        }
    }
}
int main() {
    input();
    for(int t = 0; t < M; t++) {
        int sPos, gPos;
        cin >> sPos >> gPos;
        DFS(sPos, -1, gPos, 0);
        cout << ans <<"\n";
    }
}

//Dijkstra  풀이
//#include <bits/stdc++.h>
//
//using namespace std;
//const int MAX = 1001;
//int N, M;
//vector<pair<int,int>> arr[MAX];
//int dist[MAX];
//
//void dijkstra(int cur){
//    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//    fill(&dist[0], &dist[MAX], 987654321);
//    dist[cur] = 0;
//    pq.push({0, cur});
//
//    while(!pq.empty()){
//        auto[cost, cur] = pq.top();
//        pq.pop();
//
//        if(dist[cur] > cost)
//            continue;
//
//        for(auto next : arr[cur]){
//            int neighbor = next.second;
//            int nextCost = cost + next.first;
//            if(dist[neighbor] > nextCost){
//                dist[neighbor] = nextCost;
//                pq.push({nextCost, neighbor});
//            }
//        }
//    }
//}
//
//int main(){
//    cin >> N >> M;
//    for(int i = 0; i < N - 1; i++){
//        int x, y ,d;
//        cin >> x >> y >> d;
//        arr[x].push_back({d, y});
//        arr[y].push_back({d, x});
//    }
//
//    for(int i = 1; i <= M; i++){
//        int start, goalPos; cin >> start, cin >> goalPos;
//        dijkstra(start);
//        cout << dist[goalPos] <<"\n";
//    }
//}