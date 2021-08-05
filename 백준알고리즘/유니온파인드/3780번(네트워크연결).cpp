#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

//교수님은 기다리지 않는다와 매우 유사함

using namespace std;
const int MAX = 2e4 + 1;
int parent[MAX];
int dist[MAX];

int find(int c)
{
    if(parent[c] == c)
        return c;
    int idx = find(parent[c]); // 갱신해줄 상위 루트 검색
    dist[c] += dist[parent[c]]; // 거리 갱신
    return parent[c] = idx;
}

void merge(int c, int p)
{
    dist[c] = abs(c - p) % 1000;
    parent[c] = p;
}

int main(void)
{
    fastio;
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            dist[i] = 0;
        }

        while(1)
        {
            char cmd; //명령어 입력을 위한 변수
            cin >> cmd;
            if(cmd == 'O')
                break;
            else if(cmd == 'E')
            {
                int x;
                cin >> x;
                find(x);
                cout << dist[x] << "\n";
            }
            else if(cmd == 'I')
            {
                int x , y;
                cin >> x >> y;
                merge(x, y);
            }
        }
    }
}
