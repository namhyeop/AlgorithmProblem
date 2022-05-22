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
int t,n,k,w;
int arr[MAX];
int T_done[MAX];
int indegree[MAX];
vector<int> edge[MAX];

void input(){
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        cin >> n >> k;

        for (int i = 1; i <= n; i++){
            cin >> arr[i];
            edge[i].clear();
            T_done[i] = 0;
            indegree[i] = 0;
        }

        for (int i = 0; i < k; i++){
            int x, y; cin >> x >> y;
            edge[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
                T_done[i] = arr[i];
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int next : edge[cur]){
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
                T_done[next] = max(T_done[next], T_done[cur] + arr[next]);
            }
        }
        cout << T_done[w] <<"\n";
    }
}

int main(void)
{
    fastio;
    input();
}

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
//const int MAX = 1001;
//int t,n,k,w;
//int arr[MAX];
//int indegree[MAX];
//vector<int> edge[MAX];
//
//void input(){
//    cin >> t;
//    for(int _ = 0; _ < t; _++) {
//        cin >> n >> k;
//
//        for(int i = 1; i <= n; i++){
//            edge[i].clear();
//            indegree[i] = 0;
//            arr[i] = 0;
//        }
//
//        for (int i = 1; i <= n; i++){
//            cin >> arr[i];
//        }
//
//        for (int i = 0; i < k; i++){
//            int x, y; cin >> x >> y;
//            edge[x].push_back(y);
//            indegree[y]++;
//        }
//        cin >> w;
//
//        int retTime = 0;
//        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
//
//        for(int i = 1; i <= n; i++){
//            if(indegree[i] == 0){
//                q.push({arr[i], i});
//            }
//        }
//        while(!q.empty()){
//            int cur = q.top().second;
//            int time = q.top().first;
//            q.pop();
//
//            if(cur == w){
//                retTime = time;
//                break;
//            }
//
//            for(int next : edge[cur]){
//                indegree[next]--;
//                if(indegree[next] == 0) {
//                    q.push({time + arr[next], next});
//                }
//            }
//        }
//        cout << retTime <<"\n";
//    }
//}
//
//int main(void)
//{
//    fastio;
//    input();
//}

//#include<bits/stdc++.h>
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pill pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define mt(X,Y) make_tuple(X,Y)
//#define mtt(X,Y,Z) make_tuple(X,Y,Z)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//
//const int MAX = 1005;
//int t,w;
//int timeArr[MAX];
//int ret[MAX];
//int pre[MAX];
//
//int main(void)
//{
//	fastio;
//	cin >> t;
//
//	while (t--)
//	{
//		int n, m;
//		cin >> n >> m;
//		fill(ret, ret + MAX, 0);
//		fill(pre, pre + MAX, 0);
//		vector<int> board[MAX];
//		for (int i = 1; i <= n; i++)
//			cin >> timeArr[i];
//
//		for (int i = 0; i < m; i++)
//		{
//			int p, c;
//			cin >> p >> c;
//			board[p].push_back(c);
//			pre[c]++;
//		}
//		cin >> w;
//		queue<int> q;
//		for (int i = 1; i <= n; i++)
//		{
//			if (!pre[i])
//				q.push(i);
//		}
//
//		while (pre[w] > 0)
//		{
//			int cur = q.front();
//			q.pop();
//
//			for (int next : board[cur])
//			{
//				ret[next] = max(ret[next], ret[cur] + timeArr[cur]);
//				if (--pre[next] == 0)
//					q.push(next);
//			}
//		}
//		cout << ret[w] + timeArr[w] << "\n";
//	}
//	return 0;
//}
