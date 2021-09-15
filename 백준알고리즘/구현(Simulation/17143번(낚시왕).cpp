#include<bits/stdc++.h>

using namespace std;

const int MAX = 101;

typedef struct{
    int s,d,z;
}shark;

int my[] = {-1,1,0,0};
int mx[] = {0,0,1,-1};
int R, C, M;
shark board[MAX][MAX];
shark tmpboard[MAX][MAX];
int main(){
    cin >> R >> C >> M;

    for(int i = 0; i < M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >>z;
        r--, c--, d--;
        board[r][c] = {s,d,z};
    }


    int ret = 0;
    //물고기를 잡는 과정(물고기 == 상어로 표현했습니다.)
    for(int t = 0; t < C; t++){
        for(int i = 0; i < R; i++){
            if(board[i][t].z > 0){
                ret += board[i][t].z;
                board[i][t].z = 0;
                break;//물고기가 있으는 행이면 값을 더하고 없애준다.
            }
        }

        //기존에 있던 물고기 정보를 tmpboard에 복사해준다. 이동 시킬때 한 가지 배열로 이동하면
        //이동한 물고기에서 값이 또 갱신되므로 잘못된 갱신이 일어난다. ex:) i, j이 물고기가 i + 3, j + 3으로 이동했을때 반묵문이 i + 3, j + 3에서 또 일어나므로 물고기가 두 번 이동한다.
        memcpy(tmpboard, board, sizeof tmpboard);
        fill(&board[0][0], &board[R][C], shark{0,0,0});

        //물고기 이동과정
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(tmpboard[i][j].z > 0){
                    shark &cur = tmpboard[i][j];
                    int ny = i + my[cur.d] * cur.s;
                    int nx = j + mx[cur.d] * cur.s;

                    if(ny < 0){ //먼저 음수면 양수로 바꿔주고 진행 방향의 반대 방향으로 설정
                        ny = -ny;
                        cur.d = 1;
                    }
                    //만약 행 값이 초과되면 나머지 연산을 통해 위치를 정해준다. 이 때 시작과 끝 벽을 도달한 시도가 같다면 시작점에서 떨어진 위치 이므로 나머지 값을 대입해주면 된다.
                    //만약 시작과 끝 벽을 부딪친 갯수가 동일하지 않다면 끝에서 떨어진 부분을 계산해준다.
                    if(ny > R - 1){

                        int a = ny / (R - 1);
                        int b = ny % (R - 1);
                        if(a % 2 == 0){
                            ny = b;
                        }
                        else{
                            ny = R - 1 - b;
                            cur.d = 0;
                        }
                    }
                    //위와 동일
                    if(nx < 0){
                        nx = -nx;
                        cur.d = 2;
                    }
                    if(nx > C - 1){
                        int a = nx / (C - 1);
                        int b = nx % (C - 1);

                        if(a % 2 == 0){
                            nx = b;
                        }
                        else{
                            nx = C - 1 - b;
                            cur.d = 3;
                        }
                    }
                    //이동한 위치에 있는 물고기보다 큰 경우 값 갱신
                    if(board[ny][nx].z < cur.z){
                        board[ny][nx] = cur;
                    }
                }
            }
        }
    }
    cout << ret <<"\n";
}

//#include<bits/stdc++.h>
//#define MAX 100
//using namespace std;
//
//struct shark
//{
//	int s, d, z;
//};
//
//shark board[MAX][MAX];
//shark tmpboard[MAX][MAX];
//int R, C, M;
//int moveY[] = { -1, 1, 0, 0 };
//int moveX[] = { 0, 0, 1, -1 };
//
///*
//   1
//4     3
//   2
//*/
//
//int main(void)
//{
//	cin >> R >> C >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int r, c, s, d, z;
//		cin >> r >> c >> s >> d >> z;
//		r -= 1;
//		c -= 1;
//		d -= 1;
//		board[r][c] = { s, d, z };
//	}
//
//	int sum = 0;
//	for (int t = 0; t < C; t++)
//	{
//		for (int i = 0; i < R; i++)
//		{
//			if (board[i][t].z > 0)
//			{
//				sum += board[i][t].z;
//				board[i][t].z = 0;
//				break;
//			}
//		}
//
//		memcpy(tmpboard, board, sizeof(tmpboard));
//		memset(board, 0, sizeof(board));
//
//		for (int i = 0; i < R; i++)
//		for (int j = 0; j < C; j++)
//		{
//			shark &curr = tmpboard[i][j];
//			if (curr.z > 0)
//			{
//				int nextY = i + curr.s * moveY[curr.d];
//				int nextX = j + curr.s * moveX[curr.d];
//				if (nextY < 0)
//				{
//					nextY = -nextY; //남쪽으로 가다가 부호 바꿔주고 방향 바꿔준거니가 방향을 북쪽으로 바꿔준다
//					curr.d = 1;
//				}
//				if (nextY > R - 1) //영역을 초과해줬다면, 짝수일때(왕복할 겨우), 홀수일때(가기만한 경우)
//				{
//					int a = nextY/(R - 1);
//					int b = nextY % (R - 1);
//					if (a % 2 == 0)
//					{
//						nextY = b;
//					}
//					else
//					{
//						nextY = R - 1 - b;
//						curr.d = 0;
//					}
//				}
//				if (nextX < 0)
//				{
//					nextX = -nextX;
//					curr.d = 2;
//				}
//				if (nextX > C - 1)
//				{
//					int a = nextX / (C - 1);
//					int b = nextX % (C - 1);
//					if (a % 2 == 0)
//						nextX = b;
//					else
//					{
//						nextX = C - 1 - b;
//						curr.d = 3;
//					}
//				}
//				if (board[nextY][nextX].z < curr.z)
//					board[nextY][nextX] = curr;
//
//			}
//		}
//	}
//
//	cout << sum << "\n";
//
//	return 0;
//}
