#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
int n, m;
int indegree[MAX];
vector<int> edge[MAX];
vector<int> ret;
void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int mount, prev;
        cin >> mount >> prev;
        for(int j = 1; j < mount; j++){
            int singer; cin >> singer;
            indegree[singer]++;
            edge[prev].push_back(singer);
            prev = singer;
        }
    }
}

void pro(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ret.push_back(cur);
        for(int next : edge[cur]){
            indegree[next]--;
            if(indegree[next] == 0)
                q.push(next);
        }
    }
    if(ret.size() != n)
        cout << 0 <<"\n";
    else{
        for(int num : ret){
            cout << num <<"\n";
        }
    }
}
int main(){
    input();
    pro();
}

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
//const int MAX = 1001;
//int indegree[MAX];
//vector<int> board[MAX];
//int ret[MAX];
//int n, m;
//
//int main(void)
//{
//	fastio;
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int k, p, c;
//		cin >> k >> p;
//
//		for (int i = 1; i < k; i++)
//		{
//			cin >> c;
//			board[p].push_back(c);
//			indegree[c]++;
//			p= c;
//		}
//	}
//
//	queue<int> q;
//	for (int i = 1; i <= n; i++)
//	if (indegree[i] == 0)
//		q.push(i);
//
//	for (int i = 0; i < n; i++)
//	{
//		if (q.empty())
//		{
//			cout << 0 << "\n";
//			return 0;
//		}
//
//		int cur = q.front();
//		q.pop();
//
//		ret[i] = cur;
//		for (int next : board[cur])
//		{
//			if (--indegree[next] == 0)
//				q.push(next);
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << ret[i] << "\n";
//}
//
