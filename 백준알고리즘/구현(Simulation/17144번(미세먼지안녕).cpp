/**
 * 1.미세먼지가 동서남북으로 확산된다(공기청정기가 있거나 범위 초가시 제외
 * 2.확산되는 미세먼지양은 A(r,c) / 5
 * 3.남은 미세먼지양은 A(r,c) - (A(r,c)/ 5) * (확산된 방향의 개수)
 *
 * 1.위쪽 공기청정기는 반시계 방ㅇ향
 * 2.아래쪽은 시계 방향
 * 3.공기청정기쪽으로 들어오는 미세먼지는 사라진다
 */

#include<bits/stdc++.h>

using namespace std;

const int MAX = 51;
int board[MAX][MAX];
int r, c, t;

int my[] = {-1, 0, 1, 0};
int mx[] = {0, 1, 0, -1};
pair<int, int> condi[2];

int main() {
    cin >> r >> c >> t;
    bool condiflag = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (condiflag && board[i][j] == -1) {
                condi[0] = {i, j};
                condiflag = false;
            } else if (!condiflag && board[i][j] == -1) {
                condi[1] = {i, j};
            }
        }
    }

    auto spread = [&](){
        int tmpboard[MAX][MAX];
        fill(&tmpboard[0][0], &tmpboard[MAX - 1][MAX - 1], 0);
        tmpboard[condi[0].first][condi[0].second] = -1;
        tmpboard[condi[1].first][condi[1].second] = -1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] != -1) {
                    if (board[i][j] >= 5) {
                        int cnt = 0;
                        vector<pair<int, int>> v;
                        for (int d = 0; d < 4; d++) {
                            int ny = i + my[d];
                            int nx = j + mx[d];
                            if (ny >= 0 && ny < r && nx >= 0 && nx < c && board[ny][nx] != -1) {
                                cnt++;
                                v.push_back({ny, nx});
                            }
                        }

                        for (int k = 0; k < v.size(); k++) {
                            tmpboard[v[k].first][v[k].second] += board[i][j] / 5;
                        }
                        tmpboard[i][j] += board[i][j] - ((board[i][j] / 5) * cnt);
                    } else {
                        tmpboard[i][j] += board[i][j];
                    }
                }
            }
        }
        memcpy(board, tmpboard, sizeof(board));
    };

    auto upper_move = [&](){
        //좌
        int cy = condi[0].first;
        for(int i = cy - 1; i > 0; i--){
            board[i][0] = board[i - 1][0];
        }
        for(int i = 0; i < c - 1; i++){
            board[0][i] = board[0][i + 1];
        }

        for(int i = 0; i < cy; i++){
            board[i][c - 1] = board[i + 1][c - 1];
        }
        for(int i = c - 1; i > 1; i--){
            board[cy][i] = board[cy][i - 1];
        }
        board[cy][1] = 0;
        return;
    };

    auto bottom_move = [&](){
        int cy = condi[1].first;
        int R = r - 1;
        int C = c - 1;

        for(int i = cy + 1; i < R; i++){
            board[i][0] = board[i+1][0];
        }
        for(int i = 0; i < c; i++){
            board[R][i] = board[R][i + 1];
        }
        for(int i = R; i > cy; i--){
            board[i][C] = board[i - 1][C];
        }
        for(int i = C; i > 1; i--){
            board[cy][i] =board[cy][i - 1];
        }
        board[cy][1] = 0;
    };

    for (int i = 0; i < t; i++) {
        spread();
        upper_move();
        bottom_move();
    }

    int sum = 0;
    for(int i =0; i < r; i++){
        for(int j =0; j <c; j++){
            if(board[i][j] != -1)
                sum += board[i][j];
        }
    }
    cout <<sum <<"\n";
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
//const int MAX = 51;
//int r, c, T;
//int board[MAX][MAX];
//int copyboard[MAX][MAX] = { 0 };
//vector<pair<int, int>> dust;
//int moveY[] = { -1, 0, 1, 0 };
//int moveX[] = { 0, -1, 0, 1 };
//vector<pair<int, int>> air_ps;
//
///*
//3 3 3
//0 30 7
//-1 10 0
//-1 0 20
//*/
//int main(void)
//{
//	fastio;
//	cin >> r >> c >> T;
//
//	for (int i = 0; i < r; i++)
//	for (int j = 0; j < c; j++)
//	{
//		cin >> board[i][j];
//		if (board[i][j] != -1 && board[i][j])
//			dust.push_back({ i, j });
//		else if (board[i][j] == -1)
//			air_ps.push_back({ i, j });
//	}
//
//	for (int t = 0; t < T; t++)
//	{
//		memset(copyboard, 0, sizeof(copyboard));
//		for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++)
//		{
//			if (board[i][j] >= 5)
//			{
//				copyboard[i][j] = board[i][j] / 5;
//			}
//		}
//		for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++)
//		{
//			int cnt = 0;
//			for (int d = 0; d < 4; d++)
//			{
//				int nextY = i + moveY[d];
//				int nextX = j + moveX[d];
//				if (0 <= nextY && nextY < r && 0 <= nextX && nextX < c)
//				{
//					if (board[nextY][nextX] >= 0)
//					{
//						board[nextY][nextX] += copyboard[i][j];
//						cnt++;
//					}
//				}
//			}
//			board[i][j] -= cnt * copyboard[i][j];
//		}
//
//		//공기 위
//		for (int i = air_ps[0].first - 1; i > 0; i--)
//			board[i][0] = board[i - 1][0];
//		for (int i = 0; i < c - 1; i++)
//			board[0][i] = board[0][i + 1];
//		for (int i = 0; i < air_ps[0].first; i++)
//			board[i][c - 1] = board[i+1][c - 1];
//		for (int i = c - 1; i > 1; i--)
//			board[air_ps[0].first][i] = board[air_ps[0].first][i - 1];
//		board[air_ps[0].first][1] = 0;
//
//		//공기 아래
//
//		for (int i = air_ps[1].first + 1; i < r - 1; i++)
//			board[i][0] = board[i + 1][0];
//		for (int i = 0; i < c - 1; i++)
//			board[r - 1][i] = board[r - 1][i + 1];
//		for (int i = r - 1; i > air_ps[1].first; i--)
//			board[i][c - 1] = board[i - 1][c - 1];
//		for (int i = c - 1; i > 1; i--)
//			board[air_ps[1].first][i] = board[air_ps[1].first][i - 1];
//		board[air_ps[1].first][1] = 0;
//	}
//
//	int ret = 0;
//	for (int i = 0; i < r; i++)
//	for (int j = 0; j < c; j++)
//	{
//		if (board[i][j] != -1)
//			ret += board[i][j];
//	}
//	cout << ret << "\n";
//}
//
//
///*
//#include<bits/stdc++.h>
//#define MAX 55
//using namespace std;
//
//int R, C, T;
//int board[MAX][MAX];
//int srBoard[MAX][MAX];
//int visited[MAX][MAX];
//vector<int> aircleaner;
//int moveY[] = { -1, 1, 0, 0 };
//int moveX[] = { 0, 0, -1, 1 };
//
//void spread() //미세먼지 확장
//{
//	memset(srBoard, 0, sizeof(srBoard));
//	for (int i = 0; i < R; i++)
//	for (int j = 0; j < C; j++)
//	{
//		if (board[i][j] >=  5)
//		{
//			srBoard[i][j] = board[i][j] / 5;
//		}
//	}
//	for (int i = 0; i < R; i++)
//	for (int j = 0; j < C; j++)
//	{
//		int cnt = 0;
//		for (int d = 0; d < 4; d++)
//		{
//			if (i + moveY[d] >= 0 && i + moveY[d] < R && j + moveX[d] >= 0 && j + moveX[d] < C)
//			if (board[i + moveY[d]][j + moveX[d]] >= 0)
//			{
//				board[i + moveY[d]][j + moveX[d]] += srBoard[i][j];
//				cnt++;
//			}
//		}
//		board[i][j] -= cnt * srBoard[i][j];
//	}
//}
//
//void circulation1() //시계 방향 회전
//{
//	int y = aircleaner[0];
//
//	for (int i = y - 1; i > 0; i--)
//	{
//		board[i][0] = board[i - 1][0];
//		board[i - 1][0] = 0;
//	}
//	for (int i = 0; i < C - 1; i++)
//	{
//		board[0][i] = board[0][i + 1];
//		board[0][i + 1] = 0;
//	}
//	for (int i = 0; i < y; i++)
//	{
//		board[i][C - 1] = board[i + 1][C - 1];
//		board[i + 1][C - 1] = 0;
//	}
//	for (int i = C - 1; i > 1; i--)
//	{
//		board[y][i] = board[y][i - 1];
//		board[y][i - 1] = 0;
//	}
//}
//
//void circulation2() //반 시계 방향 회전
//{
//	int y = aircleaner[1];
//
//	for (int i = y + 1; i < R; i++)
//	{
//		board[i][0] = board[i + 1][0];
//		board[i + 1][0] = 0;
//	}
//	for (int i = 0; i < C - 1; i++)
//	{
//		board[R - 1][i] = board[R - 1][i + 1];
//		board[R - 1][i + 1] = 0;
//	}
//	for (int i = R - 1; i > y; i--)
//	{
//		board[i][C - 1] = board[i - 1][C - 1];
//		board[i - 1][C - 1] = 0;
//	}
//	for (int i = C - 1; i > 1; i--)
//	{
//		board[y][i] = board[y][i - 1];
//		board[y][i - 1] = 0;
//	}
//}
//
//int main(void)
//{
//	cin >> R >> C >> T;
//
//	for (int i = 0; i < R; i++)
//	for (int j = 0; j < C; j++)
//	{
//		cin >> board[i][j];
//		if (board[i][j] == -1)
//			aircleaner.push_back(i);
//	}
//
//	for (int i = 0; i < T; i++)
//	{
//		spread();
//		circulation1();
//		circulation2();
//	}
//
//	int sum = 0;
//	for (int i = 0; i < R; i++)
//	for (int j = 0; j < C; j++)
//	if (board[i][j] != -1)
//		sum += board[i][j];
//
//	cout << sum << "\n";
//
//	return 0;
//}
//*/
