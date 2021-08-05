#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

//n: 통신탑 개수
//m: 통신탑 사이의 연결 개수
//q: 통신망 연결 분할 횟수
//문제 해결 전략
//이미 결합된 간선을 분해하는것은 너무 어렵다. 사고의 전환이 필요한 문제이다.
//1. 삭제할 간선들을 제외하고 연결한다.(예시 1-2, 3, 4)
//2. 삭제할 간선들의 역순으로 간선을 연결하면서 결합된 값을 더해준다.
//2-1((예시 1-2, 3-4) -> 3,4가 연결 되었으므로 1 * 1 = 1)
//2-2((예시 1-2-3-4) -> 1-2,3-4가 연결 되었으므로 2 * 2 = 4)
//2-3((예시 1-2-3-4-1) -> 이미 다 연 연결되어 있ㅇ므로 0) = 합은 5
//3. 이때 전체 기준이 아닌 결합된 집합을 기준으로 한다.

int n, m, q;
const int MAX = 1e5 + 1;
int parent[MAX];
int edge[MAX][2];
int dCmd[MAX];
bool check[MAX];

int find(int c)
{
    if(parent[c] < 0)
        return c;
    else
        return parent[c] = find(parent[c]);
}

void merge(int p, int c)
{
    if(parent[p] > parent[c]) //
        swap(p, c);
    parent[p] += parent[c];
    parent[c] = p;
}

int main(void)
{
    fastio;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
       parent[i] = -1;

    for(int i = 1; i <= m; i++)
        cin >> edge[i][0] >> edge[i][1];

    for(int i = q; i >= 1; i--)
    {
        cin >> dCmd[i];
        check[dCmd[i]] = true; //연결된 간선들을 체크한뒤에 간선들을 결합할 때 체크한 간선은 연결해주지 않는다.
    }

    for(int i = 1; i <= m; i++)
    {
        if(!check[i])
        {
            int x = find(edge[i][0]);
            int y = find(edge[i][1]);
            if(x != y)
            {
                merge(x, y);
            }
        }
    }

    ll ret = 0;
    for(int i = 1; i <= q; i++)
    {
        int x = find(edge[dCmd[i]][0]);
        int y = find(edge[dCmd[i]][1]);
        if(x == y)
            continue;
        ret += (parent[x] * parent[y]);
        merge(x, y);
    }
    cout << ret << "\n";
    return 0;
}
