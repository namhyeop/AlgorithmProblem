#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
int dist[MAX];
int cache[MAX];
int n, m;
vector<pair<int,int>> edge[MAX];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main(void)
{
    fastio;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int node1, node2, value;
        cin >> node1 >> node2 >> value;
        edge[node1].push_back({value, node2});
        edge[node2].push_back({value, node1});
    }
    fill(dist, dist + MAX, INT_MAX);
    //cache[i]는 i번에서 부터 시작하는 합리적인 이동 경로의 갯수
    //거꾸로 탐색을 시작하기 때문에 dist[2] = 0으로 설정해준다.
    dist[2] = 0;
    cache[2] = 1;
    pq.push({0, 2});

    while(!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[cur] < cost)
            continue;

        for(auto idx : edge[cur])
        {
            int neighbor = idx.second;
            int neighborCost = idx.first + cost;

            if(neighborCost < dist[neighbor])
            {
                dist[neighbor] = neighborCost;
                pq.push({neighborCost, neighbor});
            }
            if(dist[neighbor] < dist[cur])
                cache[cur] += cache[neighbor];
        }
    }
    cout << cache[1] << "\n";
}