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
//int g, p;
//int parent[MAX];
//int ret;
//
//int find(int u)
//{
//    if(u == parent[u])
//        return u;
//    else
//        return parent[u] = find(parent[u]);
//}
//
//void merge(int u, int v)
//{
//    u = find(u);
//    v = find(v);
//    parent[u] = v;
//}
//
//int main(void)
//{
//    fastio;
//    cin >> g >> p;
//
//    for(int  i = 1; i <= g; i++)
//        parent[i] = i;
//
//    for(int i = 1; i <= p; i++)
//    {
//        int gi;
//        cin >> gi;
//        int dock_num = find(gi);
//        if(dock_num != 0)
//        {
//            merge(dock_num, dock_num - 1);
//            ++ret;
//        }
//        else
//            break;
//    }
//    cout << ret << "\n";
//}
