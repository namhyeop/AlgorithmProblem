#include <bits/stdc++.h>

using namespace std;

int r, c, v, o;
const int MAX = 255;
string board[MAX];
bool visited[MAX][MAX];

int moveY[] = {-1,0,1,0};
int moveX[] = {0,-1,0,1};

void BFS(int i, int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int curV = 0, curO = 0;
    while(!q.empty()){
        auto[y, x] = q.front();
        q.pop();
        if(board[y][x] == 'v')
            curV++;
        if(board[y][x] == 'o')
            curO++;

        for(int d = 0; d < 4; d++){
            int ny = y + moveY[d];
            int nx = x + moveX[d];
            if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                if(!visited[ny][nx] && board[ny][nx] != '#'){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }

    if(curV >= curO){
        v += curV;
    }else{
        o += curO;
    }
}

void pro(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) {
            if (!visited[i][j] && board[i][j] != '#') {
                BFS(i, j);
            }
        }
    }
}

void input(){
    cin >> r >> c;
    for(int i = 0; i <r; i++){
        cin >> board[i];
    }
}

int main(){
    input();
    pro();
    cout << o <<" " << v <<"\n";
}

//#include<iostream>
//#include<queue>
//#include<string>
//
//#define MAX 250
//using namespace std;
//
//int height;
//int width;
//string board[MAX];
//int moveY[4] = { -1, 1, 0, 0 };
//int moveX[4] = { 0, 0, -1, 1 };
//int visited[MAX][MAX];
//int sheep;
//int wolf;
//
//void BFS(int y, int x)
//{
//	queue<pair<int, int>> q;
//	q.push({ y, x });
//	visited[y][x] = true;
//
//	int cntSheep = 0;
//	int cntWolf = 0;
//	if (board[y][x] == 'o')
//		cntSheep++;
//	else if (board[y][x] == 'v')
//		cntWolf++;
//
//	while (!q.empty())
//	{
//		int curY = q.front().first;
//		int curX = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextY = curY + moveY[i];
//			int nextX = curX + moveX[i];
//
//			if (nextY >= 0 && nextY < height && nextX >=0 && nextX < width)
//			if (!visited[nextY][nextX] && board[nextY][nextX] != '#')
//			{
//				visited[nextY][nextX] = true;
//				if (board[nextY][nextX] == 'o')
//					cntSheep++;
//				else if (board[nextY][nextX] == 'v')
//					cntWolf++;
//				q.push({ nextY, nextX });
//			}
//		}
//	}
//
//	if (cntSheep > cntWolf)
//		wolf -= cntWolf;
//	else
//		sheep -= cntSheep;
//}
//int main(int argc, char *argv[])
//{
//	cin >> height >> width;
//
//	for (int i = 0; i < height; i++)
//	{
//		cin >> board[i];
//		for (int j = 0; j < width; j++)
//		{
//			if (board[i][j] == 'o')
//				sheep++;
//			if (board[i][j] == 'v')
//				wolf++;
//		}
//	}
//
//	for (int i = 0; i < height; i++)
//	for (int j = 0; j < width; j++)
//	{
//		if ((board[i][j] == 'o' || board[i][j] == 'v') && !visited[i][j])
//			BFS(i, j);
//	}
//
//	cout << sheep << " " << wolf;
//
//	return 0;
//}
