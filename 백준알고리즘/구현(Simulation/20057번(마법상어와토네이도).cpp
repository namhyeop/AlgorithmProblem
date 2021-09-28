#include <bits/stdc++.h>

using namespace std;
const int MAX = 501;

int my[] = {0, 1, 0, -1};
int mx[] = {-1, 0, 1, 0};

struct cane {
    int y, x;
    double perboard[5][5];
};

struct play {
    int n;
    int sum;
    cane c;
    int board[MAX][MAX];

    play(int n) : n(n), sum(0) {}

    //입력값, 토네이토로 인해 날아가나는 위치별 비율값 설정
    void init() {
        memset(board, 0, sizeof board);
        memset(c.perboard, 0, sizeof c.perboard);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        c.y = n / 2;
        c.x = n / 2;
        c.perboard[0][2] = 0.02;
        c.perboard[1][1] = 0.1, c.perboard[1][2] = 0.07, c.perboard[1][3] = 0.01;
        c.perboard[2][0] = 0.05, c.perboard[2][1] = 0.55;
        c.perboard[3][1] = 0.1, c.perboard[3][2] = 0.07, c.perboard[3][3] = 0.01;
        c.perboard[4][2] = 0.02;
    }

    //범위 초과 학인 함수
    bool isValid(int y, int x) {
        return (y >= 0 && y < n && x >= 0 && x < n);
    }

    //태풍을 이동시키면서 비율에 맞게 모래를 뿌리는 함수
    void moveCane() {
        int s = 1, dir = 0;
        while (1) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < s; j++) {
                    if (c.y == 0 && c.x == 0) {
                        return;
                    }
                    c.y += my[dir];
                    c.x += mx[dir];

                    int curSand = board[c.y][c.x];
                    board[c.y][c.x] = 0;
                    if (curSand == 0)
                        continue;

                    for (int i = -2; i <= 2; i++) {
                        for (int j = -2; j <= 2; j++) {
                            double curPercent = c.perboard[i + 2][j + 2];

                            int moveSand;
                            //알파의 범위는 먼지가 날리가 남은 만큼이다.
                            if (curPercent >= 0.55) {
                                moveSand = curSand
                                        - floor(curSand * 0.02) * 2
                                        - floor(curSand * 0.07) * 2
                                        - floor(curSand * 0.10) * 2
                                        - floor(curSand * 0.01) * 2
                                        - floor(curSand * 0.05);
                            } else {
                                moveSand = floor(curSand * curPercent);
                            }

                            int nextY = c.y + i;
                            int nextX = c.x + j;
                            //범위를 초과해 정답에 더해야 하는경우
                            if (!isValid(nextY, nextX)) {
                                sum += moveSand;
                            } else
                                board[nextY][nextX] += moveSand;
                        }
                    }
                }
                dir++;
                if (dir == 4)
                    dir = 0;
                rotateCane();
            }
            s++;
        }
    }

    //태풍을 회전시키는 함수
    void rotateCane() {
        double tmpboard[5][5];
        memcpy(tmpboard, c.perboard, sizeof tmpboard);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                c.perboard[5 - j - 1][i] = tmpboard[i][j];
            }
        }
    }

    //디버깅용
    void printBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "==============" << "\n";
    }
};

int main() {
    int n;
    cin >> n;
    play op(n);
    op.init();
    op.moveCane();
    cout << op.sum << "\n";
}
//
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
//
//const int MAX = 500;
//
//int moveY[] = { 0, 1, 0, -1 };
//int moveX[] = { -1, 0, 1, 0 };
//
//double sandPercentage[5][5] = {
//	{ 0, 0, 0.02, 0, 0 },
//	{ 0, 0.1, 0.07, 0.01, 0 },
//	{ 0.05, 0.55, 0, 0, 0 },
//	{ 0, 0.1, 0.07, 0.01, 0 },
//	{ 0, 0, 0.02, 0, 0 }
//};
//
//int board[MAX][MAX];
//int ret;
//int main(void)
//{
//	fastio;
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//		cin >> board[i][j];
//
//	int y = n / 2;
//	int x = n / 2;
//	int cnt = 1;
//	int dir = 0;
//
//	while (1)
//	{
//		if (y == 0 && x == 0)
//			break;
//
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < cnt; j++)
//			{
//				y += moveY[dir];
//				x += moveX[dir];
//
//				auto moveSand = [&](int y, int x)
//				{
//					int curSand = board[y][x];
//					board[y][x] = 0;
//
//					if (curSand == 0)
//						return;
//
//					for (int i = -2; i <= 2; i++)
//					for (int j = -2; j <= 2; j++)
//					{
//						double curSandPercentage = sandPercentage[i + 2][j + 2];
//
//						if (curSandPercentage == 0)
//							continue;
//
//						auto alphaSand = [&](int curSand) -> int
//						{
//							return curSand
//								- floor(curSand * 0.02) * 2
//								- floor(curSand * 0.07) * 2
//								- floor(curSand * 0.10) * 2
//								- floor(curSand * 0.01) * 2
//								- floor(curSand * 0.05);
//						};
//
//						int moveSand;
//						if (curSandPercentage < 0.55)
//							moveSand = floor(curSandPercentage * curSand);
//						else
//							moveSand = alphaSand(curSand);
//
//						int nextY = y + i;
//						int nextX = x + j;
//
//						if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
//							ret += moveSand;
//						else
//							board[nextY][nextX] += moveSand;
//					}
//				};
//				moveSand(y, x);
//				if (y == 0 && x == 0)
//				{
//					cout << ret << '\n';
//					return 0;
//				}
//			}
//			dir = (dir == 3) ? 0 : dir + 1;
//
//			auto rotateSand = [&]()
//			{
//				double tmpsandPercentage[5][5];
//
//				for (int i = 0; i < 5; i++)
//				for (int j = 0; j < 5; j++)
//					tmpsandPercentage[i][j] = sandPercentage[i][j];
//
//				for (int i = 0; i < 5; i++)
//				for (int j = 0; j < 5; j++)
//					sandPercentage[5 - j -1][i] = tmpsandPercentage[i][j];
//			};
//			rotateSand();
//		}
//		cnt++;
//	}
//}
