#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
const int MAX = 105;
vector<int> board[MAX];
bool visited[MAX];

int moveY[] = {-1,0,1,0};
int moveX[] = {0,-1,0,1};

void DFS(int cur){
    visited[cur] = true;
    ans++;
    for(auto next : board[cur]){
        if(!visited[next]){
            DFS(next);
        }
    }

}

void pro(){
    DFS(1);
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
}

int main(){
    input();
    pro();
    cout << ans -1 <<"\n";
}

//#include<iostream>
//#include<queue>
//#include<vector>
//
//using namespace std;
//
//int N;
//int vrcom;
//int board[101][101];
//bool visited[101];
//int ret = 0;
//queue<int> q;
//
//void bfs()
//{
//	q.push(1);
//	visited[1] = true;
//
//	while (!q.empty())
//	{
//		ret++;
//		int dirtyCum = q.front();
//		q.pop();
//
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && board[dirtyCum][i] == 1)
//			{
//				visited[i] = true;
//				q.push(i);
//			}
//		}
//	}
//}
//int main(int argc, char *argv[])
//{
//	cin >> N;
//	cin >> vrcom;
//	for (int i = 0; i < vrcom; i++)
//	{
//		int node1;
//		int node2;
//		cin >> node1 >> node2;
//		board[node1][node2] = 1;
//		board[node2][node1] = 1;
//	}
//
//	bfs();
//
//	cout << ret -1 << "\n";
//}
