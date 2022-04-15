#include<bits/stdc++.h>

using namespace std;

const int MAX = 51;
vector<pair<int,int>> board[MAX];
const int INF = 987654321;
vector<int> dist;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (const auto &v: road) {
        int vilage = v[0], dest = v[1], dist = v[2];
        board[vilage].push_back({dist, dest});
        board[dest].push_back({dist, vilage});
    }

    auto dijkstra = [&](int start) -> vector<int>{
        dist.resize(N + 1, INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if(dist[cur] < cost)
                continue;

            for(auto next : board[cur]){
                int nextCost = next.first + cost;
                int neighbor = next.second;

                if(dist[neighbor] > nextCost){
                    dist[neighbor] = nextCost;
                    pq.push({nextCost, neighbor});
                }
            }
        }
        return dist;
    };

    vector<int> retV = dijkstra(1);

    for (const auto &item: retV) {
        if(item <= K)
            answer++;
    }
    return answer;
}

int main() {
    cout << solution(5, {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}}, 3) << "\n";
}