#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 32000 + 1;
int n, m;
int indegree[MAX];
vector<int> edge[MAX];

void pro(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int node : edge[cur]){
            indegree[node]--;
            if(indegree[node] == 0){
                q.push(node);
            }
        }
    }
    cout <<"\n";
}

void input(){
    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int smP, bigP;
        cin >> smP >> bigP;
        edge[smP].push_back(bigP);
        indegree[bigP]++;
    }
}

int main(void)
{
    fastio;
    input();
    pro();
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
//const int MAX = 32001;
//int inDegree[MAX];
//vector<int> board[MAX];
//int main(void)
//{
//	fastio;
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		inDegree[b]++;
//		board[a].push_back(b);
//	}
//
//	queue<int> q;
//	int ret[MAX];
//	for (int i = 1; i <= n; i++)
//	if (inDegree[i] == 0)
//		q.push(i);
//
//	for (int i = 0; i < n; i++)
//	{
//		if (q.empty())
//			break;
//
//		int cur = q.front();
//		q.pop();
//
//		ret[i] = cur;
//		for (auto next : board[cur])
//		if (--inDegree[next] == 0)
//			q.push(next);
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << ret[i] << " ";
//}
