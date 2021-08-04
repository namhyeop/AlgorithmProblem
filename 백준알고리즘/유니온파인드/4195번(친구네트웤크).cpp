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
//
//int testcase;
//
//const int MAX = 2e5 + 2;
//int parent[MAX];
//int values[MAX];
//
//int find(int c)
//{
//    if(parent[c] == c)
//        return c;
//    else
//        return parent[c] = find(parent[c]);
//}
//
//void merge(int a, int b)
//{
//    a = find(a);
//    b = find(b);
//
//    if(a != b)
//    {
//        if(values[a] < values[b])
//            swap(a, b);
//        values[a] += values[b];
//        parent[b] = a;
//    }
//}
//int main(void)
//{
//    fastio;
//    cin >> testcase;
//
//    while(testcase--)
//    {
//        int f;
//        cin >> f;
//
//        for(int i = 0; i < MAX; i++)
//        {
//            parent[i] = i;
//            values[i] = 1;
//        }
//
//        int nodeNum = 1;
//        map<string,int> m;
//        for(int i=0; i < f; i++)
//        {
//            string a , b;
//            cin >> a >> b;
//            if(!m.count(a))
//                m[a] = nodeNum++;
//            if(!m.count(b))
//                m[b] = nodeNum++;
//
//            merge(m[a], m[b]);
//
//            int value1 = find(m[a]);
//            int value2 = find(m[b]);
//
//            cout << max(values[value1], values[value2]) << "\n";
//        }
//    }
//}