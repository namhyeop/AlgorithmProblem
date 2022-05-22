#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e5 + 10;
int n, m;
vector<int> arr[MAX];
int point[MAX];

void input(){
    cin >> n >> m;
    for(int p = 1; p <= n; p++){
        int c; cin >> c;
        if(c == -1)
            continue;
        arr[p].push_back(c);
        arr[c].push_back(p);
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        point[x] += y;
    }
}

void search_tree(int cur, int prev){
    for(auto next : arr[cur]){
        if(next != prev){
            point[next] += point[cur];
            search_tree(next, cur);
        }
    }
}

void pro(){
    search_tree(1, -1);
    for(int i = 1; i <= n; i++){
        cout << point[i] <<" ";
    }
}

int main(void)
{
    fastio;
    input();
    pro();
}
