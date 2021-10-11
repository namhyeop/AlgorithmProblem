#include<bits/stdc++.h>

using namespace std;
const int MAX = 201;
#define INF 987654321
vector<pair<int,int>> edge[201];
int N;

vector<int> dijkstra(int start){
    vector<int> dist(N + 2, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto[cost, cur] = pq.top();
        pq.pop();

        //거리 값이 현재 비교값도다 크다면 갱신 할 이유가 없음
        if(dist[cur] < cost)
            continue;

        for(auto next : edge[cur]){
            int nextCost = cost + next.first;
            int neighbor = next.second;
            if(dist[neighbor] > nextCost){
                dist[neighbor] = nextCost;
                pq.push({nextCost, neighbor});
            }
        }
    }
    return dist;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    int answer = INF;
    for(int i = 0; i < fares.size(); i++){
        edge[fares[i][0]].push_back({fares[i][2], fares[i][1]});
        edge[fares[i][1]].push_back({fares[i][2], fares[i][0]});
    }
    //시작점에서 갈 수 있는 최단거리
    vector<int> start = dijkstra(s);
    //A지점에서 갈 수 있는 최단거리
    vector<int> startA = dijkstra(a);
    //B지점에서 갈 수 있는 최단거리
    vector<int> startB = dijkstra(b);

    //경유지를 신경쓰든지 말든지 3개의 잇는 최소의 거리 값이 정답
    for(int i = 1; i <= n; i++){
        if(start[i] == INF || startA[i] == INF || startB[i] == INF)
            continue;
       answer = min(answer,start[i] + startA[i] + startB[i]);
    }
    return answer;
}

int main(){
    cout << solution(6, 4, 6, 2,{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) <<"\n";
}