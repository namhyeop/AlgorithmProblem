#include <bits/stdc++.h>

using namespace std;

int r, c;
const int MAX = 55;
int board[MAX][MAX];
bool visited[MAX][MAX];

int moveY[] = {-1,-1,-1,0,0,1,1,1};
int moveX[] = {-1,0,1,-1,1,-1,0,1};

void BFS(int i, int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        auto[y, x] = q.front();
        q.pop();

        for(int d = 0; d < 8; d++){
            int ny = y + moveY[d];
            int nx = x + moveX[d];
            if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                if(!visited[ny][nx] && board[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int pro(){
    int count = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) {
            if (!visited[i][j] && board[i][j]) {
                BFS(i, j);
                count++;
            }
        }
    }
    return count;
}

void input(){
    fill(&board[0][0], &board[r][c + 1], 0);
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }
}

int main(){

    while(1){
        cin >> c >> r;
        if(r == 0 && c == 0)
            break;
        input();
        int ans = pro();
        cout << ans <<"\n";
    }
}

//#include<iostream>
//#include<queue>
//#include<string.h>
//
//using namespace std;
//
//int board[50][50];
//bool visited[50][50];
//int height;
//int width;
//int moveY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//int moveX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//
//void BFS(int i, int j)
//{
//	queue<pair<int, int>> q;
//	q.push({ i, j });
//	visited[i][j] = true;
//
//	while (!q.empty())
//	{
//		int curY = q.front().first;
//		int curX = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 8; i++)
//		{
//			int nextY = curY + moveY[i];
//			int nextX = curX + moveX[i];
//
//			if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
//			if (board[nextY][nextX] == 1 && !visited[nextY][nextX])
//			{
//				q.push({ nextY, nextX });
//				visited[nextY][nextX] = true;
//			}
//		}
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	while (1)
//	{
//		int cnt = 0;
//
//		cin >> width >> height;
//		if (width == 0 && height == 0)
//			break;
//
//		memset(board, 0, sizeof(board));
//		memset(visited, false, sizeof(visited));
//		for (int i = 0; i < height; i++)
//		for (int j = 0; j < width; j++)
//			cin >> board[i][j];
//
//		for (int i = 0; i < height; i++)
//		for (int j = 0; j < width; j++)
//		{
//			if (!visited[i][j] && board[i][j] == 1)
//			{
//				BFS(i, j);
//				cnt++;
//			}
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}
