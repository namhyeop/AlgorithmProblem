#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
int n, m;
string board[MAX];
int dist[MAX][MAX];

int moveY[] = {-1, 0, 1, 0};
int moveX[] = {0, -1, 0, 1};

void BFS() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        auto[y, x] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + moveY[i];
            int nx = x + moveX[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(dist[ny][nx] == -1 && board[ny][nx] == '1'){
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
}

void pro() {
    fill(&dist[0][0], &dist[n + 1][m + 1], -1);
    BFS();
    cout << dist[n - 1][m - 1] <<"\n";
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
}

int main() {
    input();
    pro();
}

//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//#define MAX 100
//
//int height, width;
//int moveY[4] = { -1, 1, 0, 0 };
//int moveX[4] = { 0, 0, -1, 1 };
//string input[MAX];
//bool visited[100][100];
//int cache[100][100];
//
//void bfs(int y, int x)
//{
//	visited[y][x] = true;
//
//	queue<pair<int,int>> q;
//	q.push(make_pair(y,x));
//
//	while (!q.empty())
//	{
//		int tmpY = q.front().first;
//		int tmpX = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int dy = tmpY + moveY[i];
//			int dx = tmpX + moveX[i];
//			if (0 <= dy && dy < height &&
//				0 <= dx && dx < width &&
//				input[dy][dx] == '1' &&
//				!visited[dy][dx] )
//			{
//				cache[dy][dx] = cache[tmpY][tmpX] + 1;
//				visited[dy][dx] = true;
//				q.push(make_pair(dy, dx));
//			}
//
//		}
//	}
//}
//int main(int argc, char *argv[])
//{
//	cin >> height >> width;
//
//	for (int i = 0; i < height; i++)
//		cin >> input[i];
//	bfs(0,0);
//	cout << cache[height - 1][width - 1] +1<< "\n";
//
//	return 0;
//}
