//#include<bits/stdc++.h>
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pii pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define mt(X,Y) make_tuple(X,Y)
//#define mtt(X,Y,Z) make_tuple(X,Y,Z)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//const int MAX = 1e5 + 1;
//int n, m, k;
//ll parent[MAX];
//ll cost[MAX];
//
//ll find(ll p)
//{
//    if(parent[p] == p)
//        return p;
//    else
//        return parent[p] = find(parent[p]);
//}
//
//void merge(ll p, ll c)
//{
//    p = find(p);
//    c = find(c);
//
//    if(p == c)
//        return;
//
//    if(cost[p] < cost[c])
//        parent[c] = p;
//    else
//        parent[p]= c;
//
//    return ;
//}
//
//int main(void)
//{
//    fastio;
//    cin >> n >> m >> k;
//
//    for(int i = 1; i <= n; i++)
//    {
//        parent[i] = i;
//        cin >> cost[i];
//    }
//
//    for(int j = 0; j < m; j++)
//    {
//        int p, c;
//        cin >> p >> c;
//        merge(p, c);
//    }
//
//    ll ret = 0;
//    for(int i = 1; i <= n; i++)
//        if(parent[i] == i)
//            ret += cost[i];
//
//        if(ret > k)
//            cout << "Oh no";
//        else
//            cout << ret;
//
//        return 0;
//}