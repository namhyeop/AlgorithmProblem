#include <bits/stdc++.h>

using namespace std;
const int MAX = 52;
int n, m;
string board[MAX];
pair<int, int> start, endpos;
int dist[MAX][MAX];
int moveY[] = {-1, 0, 1, 0};
int moveX[] = {0, -1, 0, 1};
queue<pair<int, int>> q, wq;

bool isValid(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

int BFS() {
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        int qSize = q.size();
        int wqSize = wq.size();
        for (int s = 0; s < wqSize; s++) {
            auto[wy, wx] = wq.front();
            wq.pop();
            for (int i = 0; i < 4; i++) {
                int ny = wy + moveY[i];
                int nx = wx + moveX[i];
                if (isValid(ny, nx))
                    if (board[ny][nx] == '.') {
                        board[ny][nx] = '*';
                        wq.push({ny, nx});
                    }
            }
        }
        for (int a = 0; a < qSize; a++) {
            auto[y, x] = q.front();
            q.pop();
            if (y == endpos.first && x == endpos.second) {
                return dist[endpos.first][endpos.second];
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + moveY[i];
                int nx = x + moveX[i];
                if (isValid(ny, nx)) {
                    if (dist[ny][nx] == -1 && (board[ny][nx] == '.' || board[ny][nx] == 'D')) {
                        dist[ny][nx] = dist[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
    return -1;
}

void pro() {
    int answer = BFS();
    if(answer == -1)
        cout <<"KAKTUS" <<"\n";
    else
        cout << answer << "\n";
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'D') {
                endpos = {i, j};
            } else if (board[i][j] == 'S') {
                start = {i, j};
            }else if(board[i][j] == '*'){
                wq.push({i, j});
            }
        }
    }
    fill(&dist[0][0], &dist[n + 1][m + 1], -1);
}

int main() {
    input();
    pro();
}

//#include<iostream>
//#include<queue>
//#include<string.h>
//#include<string>
//
//using namespace std;
//
//#define MAX 51
//
//
//int row;
//int col;
//string board[MAX];
//int moveY[4] = { -1, 1, 0, 0 };
//int moveX[4] = { 0, 0, -1, 1 };
//bool visited[MAX][MAX];
//pair<int, int> start,finish;
//vector<pair<int, int>> bigwater;
//
//int bfs()
//{
//	queue<pair<int,int>> q;
//	q.push(start);
//	queue<pair<int,int>> flowwater;;
//	for (int i = 0; i < bigwater.size(); i++)
//		flowwater.push(bigwater[i]);
//
//	int ret = 0;
//
//	while (!q.empty())
//	{
//		int flowwaterSize = flowwater.size();
//
//		for (int i = 0; i < flowwaterSize; i++)
//		{
//			int y = flowwater.front().first;
//			int x = flowwater.front().second;
//			flowwater.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				int dy = y + moveY[i];
//				int dx = x + moveX[i];
//
//				if (0 <= dy && dy < row && 0 <= dx && dx < col)
//				if (board[dy][dx] == '.')
//				{
//					board[dy][dx] = '*';
//					flowwater.push(make_pair(dy, dx));
//				}
//			}
//		}
//
//		int curSize = q.size();
//		for (int i = 0; i < curSize; i++)
//		{
//			int y = q.front().first;
//			int x = q.front().second;
//			q.pop();
//
//			if (finish.first == y && finish.second == x)
//				return ret;
//
//			for (int i = 0; i < 4; i++)
//			{
//				int dy = y + moveY[i];
//				int dx = x + moveX[i];
//
//				if (0 <= dy && dy < row && 0 <= dx && dx < col)
//				if (!visited[dy][dx] && board[dy][dx] != '*' &&board[dy][dx] != 'X')
//				{
//					visited[dy][dx] = true;
//					q.push(make_pair(dy, dx));
//				}
//			}
//		}
//		ret++;
//	}
//	return -1;
//}
//
//int main(int argc, char *argv[])
//{
//	cin >> row >> col;
//
//	for (int i = 0; i < row; i++)
//	{
//		cin >> board[i];
//		for (int j = 0; j < col; j++)
//		{
//			if (board[i][j] == 'S')
//				start = make_pair(i, j);
//			else if (board[i][j] == 'D')
//				finish = make_pair(i, j);
//			else if (board[i][j] == '*')
//				bigwater.push_back(make_pair(i, j));
//		}
//	}
//
//	int ret = bfs();
//
//	if (ret == -1)
//		cout << "KAKTUS" << "\n";
//	else
//		cout << ret << "\n";
//
//	return 0;
//}
