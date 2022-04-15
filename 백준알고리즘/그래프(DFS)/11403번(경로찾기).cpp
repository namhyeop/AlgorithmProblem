#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX = 105;
int board[MAX][MAX];
vector<int> edge[MAX];
bool visited[MAX];

void DFS(int cur, int goal, int origin){
    visited[cur] = true;
    for(auto next : edge[cur]){
        if(next == goal){
            board[origin][goal] = 1;
            break;
        }
        if(!visited[next]) {
            DFS(next, goal, origin);
        }
    }
}

void pro(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            memset(visited, false, sizeof(visited));
            DFS(i, j, i);
        }
    }
}

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int tmp; cin >> tmp;
            if(tmp == 1){
                edge[i].push_back(j);
            }
        }
    }
}

int main(){
    input();
    pro();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout <<"\n";
    }
}

//#include<iostream>
//#include<string.h>
//#define MAX 101
//
//using namespace std;
//
//int N;
//int board[MAX][MAX];
//bool visited[MAX];
//
//void dfs(int here)
//{
//	for (int i = 0; i < N; i++)
//	{
//		if (board[here][i] && !visited[i])
//		{
//			visited[i] = true;
//			dfs(i);
//		}
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	cin >> N;
//
//
//	for (int i = 0; i < N; i++)
//	for (int j = 0; j < N; j++)
//		cin >> board[i][j];
//
//	for (int i = 0; i < N; i++)
//	{
//		memset(visited, false, sizeof(visited));
//		dfs(i);
//
//		for (int j = 0; j < N; j++)
//		{
//			if (visited[j])
//				board[i][j] = 1;
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//			cout << board[i][j] << " ";
//		cout << "\n";
//	}
//
//	return 0;
//}
