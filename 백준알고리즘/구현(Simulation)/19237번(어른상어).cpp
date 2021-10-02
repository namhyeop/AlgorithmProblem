#include<bits/stdc++.h>

using namespace std;
const int MAX = 21;
int my[] = {-1,1,0,0};
int mx[] = {0,0,-1,1};

struct shark{
    int y, x, d, live;
};
struct smell{
    int own, time;
};
struct game{
    int n, m, k;
    smell smells[MAX][MAX];
    int board[MAX][MAX];
    int spd[MAX*MAX][4][4];
    shark sharks[401];
    game(int n, int m, int k) : n(n), m(m), k(k) {}

    bool isValid(int y, int x){
        return (y >= 0 && y < n && x >= 0 && x < n);
    }

    void init(){
        memset(smells, 0, sizeof(smells));
        memset(board, 0, sizeof(board));
        memset(spd, 0 , sizeof(spd));
        memset(sharks, 0, sizeof(sharks));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
                if(board[i][j]){
                    sharks[board[i][j]] = {i, j, 0, true};
                    smells[i][j] = {board[i][j], k};
                }
            }
        }

        for(int i = 1; i <= m; i++){
            int dir;
            cin >> dir, dir--;
            sharks[i].d = dir;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    int dir;
                    cin >> dir, dir--;
                    spd[i][j][k] = dir;
                }
            }
        }
    }

    void moveShark(){
        for(int i = 1; i <= m; i++){
            auto[y,x,d,live] = sharks[i];
            bool findFlag = false;
            if(live == true){
                for(int dir = 0; dir < 4; dir++){
                    int ny = y + my[spd[i][d][dir]];
                    int nx = x + mx[spd[i][d][dir]];
                    if(isValid(ny,nx) && smells[ny][nx].own == 0){
                        //이동시키려는 상어의 우선순익 더 높은 경우
                        //상어의 정보 안에 있는(sharks) 좌표값을, 방향을 변경하고,
                        //상어의 보드 값을 갱신시킨다.
                        //이동하는 위치에 있던 상어는 죽인다.
                        if(board[ny][nx] != 0){
                            if(board[ny][nx] > i){
                                sharks[i] = {ny, nx, spd[i][d][dir], true};
                                sharks[board[ny][nx]].live = false;
                                board[ny][nx] = i;
                                board[y][x] = 0;
                            }
                            //이동시키려는 상어의 우선순위가 더 낮아서 죽어야 하는 경우
                            else{
                                board[y][x] = 0;
                                sharks[i].live = false;
                            }
                        }
                        //이동하려는 칸에 아무 상어가 없는 경우라면 위치를 갱신 시켜주고 상어 board값을 갱신한다.
                        else{
                            sharks[i] = {ny, nx, spd[i][d][dir], true};
                            board[y][x] = 0;
                            board[ny][nx] = i;
                        }
                        findFlag = true;
                        break;
                    }
                }
                //상어의 4방향에 냄새만 있는 경우 자신의 냄새가 있는 칸으로 방향을 잡는다.
                if(!findFlag){
                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + my[spd[i][d][dir]];
                        int nx = x + mx[spd[i][d][dir]];
                        if(isValid(ny, nx) && smells[ny][nx].own == i){
                            sharks[i] = {ny, nx, spd[i][d][dir], true};
                            board[ny][nx] = i;
                            board[y][x] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    //기존 상어들의 냄새를 1씩 감축
    void minusSmell(){
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                if(smells[i][j].time-- > 0){
                    if(smells[i][j].time == 0){
                        smells[i][j].own = 0;
                    }
                }
            }
        }
    }

    //현재 상어의 위치에 냄새를 더해준다.
    void addSmell(){
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != 0){
                    smells[i][j] = {board[i][j], k};
                }
            }
        }
    }

    //상어 1번만 남아있는지 확인 하는 기능
    bool check(){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] > 1){
                    return false;
                }
            }
        }
        return true;
    }

    //디버깅 용도
    void printboard(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] <<" ";
            }
            cout <<"\n";
        }
        cout << "====== board =======" <<"\n";
    }
    void printSmell(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << smells[i][j].own <<" ";
            }
            cout <<"\n";
        }
        cout << "====== smells =======" <<"\n";
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    game op(n, m, k);
    op.init();

    if(op.check()){
        cout << 0 <<"\n";
        return 0;
    }

    for(int t = 1; t <= 1000; t++){
        op.moveShark();
        //op.printboard();
        //op.printSmell();
        op.minusSmell();
        op.addSmell();
        if(op.check()){
            cout <<t <<"\n";
            return 0;
        }
    }
    cout << -1 <<"\n";
    return 0;
}

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
//int moveY[] = { 0, -1, 1, 0, 0 };
//int moveX[] = { 0, 0, 0, -1, 1 };
//
//int board[21][21];
//pair<int, int> smell[21][21]; //냄새의 주인 상어번호, 남아있는 횟수
//
//typedef struct
//{
//	int isDead;
//	int dir;
//	int y;
//	int x;
//	int rank[5][4];
//}Shark;
//
//Shark shark[401];
//int n, m, k;
//
//bool valid(int y, int x)
//{
//	if (y < 0 || x < 0 || y >= n || x >= n)
//		return false;
//	return true;
//}
//
//int main(void)
//{
//	fastio;
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> board[i][j];
//			if (board[i][j] != 0)
//			{
//				shark[board[i][j]].y = i;
//				shark[board[i][j]].x = j;
//			}
//		}
//	}
//
//	for (int i = 1; i <= m; i++)
//	{
//		int input;
//		cin >> input;
//		shark[i].dir = input;
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int k = 1; k <= 4; k++)
//		{
//			for (int j = 0; j < 4; j++)
//				cin >> shark[i].rank[k][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (board[i][j] != 0)
//				smell[i][j] = make_pair(board[i][j], k);
//		}
//	}
//	auto simulation = [&]() -> int
//	{
//		int time = 0;
//		while (time <= 1000)
//		{
//			bool flag = false;
//			for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//			{
//				if (board[i][j] != 0 && board[i][j] != 1)
//				{
//					flag = true;
//					break;
//				}
//			}
//			if (!flag)
//				break;
//
//			auto moving = [&]()
//			{
//				for (int i = 1; i <= m; i++)
//				{
//					int dir = shark[i].dir;
//					int y = shark[i].y;
//					int x = shark[i].x;
//
//					bool isFind = false;
//					if (shark[i].isDead == false)
//					{
//						for (int j = 0; j < 4; j++)
//						{
//							int f_dir = shark[i].rank[dir][j]; // dir일 때 상어의 탐색 우선수위
//							int ty = y + moveY[f_dir];
//							int tx = x + moveX[f_dir];
//
//							if (valid(ty, tx) && smell[ty][tx].second == 0)//범위가 유효하고 다음 상어가 갈 위치에 냄새가 없다면
//							{
//								if (board[ty][tx] != 0) //이동하는 칸이 상어인경우
//								{
//									if (board[ty][tx] > i) // 기존에 있는 칸의 상어가 이동할려는 상어보다 큰 경우, 번호가 작으면 남아있고 큰 경우 쫓김을 당한다.
//									{
//										board[y][x] = 0;
//										shark[board[ty][tx]].isDead = true;
//										board[ty][tx] = i;
//										shark[i].y = ty;
//										shark[i].x = tx;
//										isFind = true;
//										shark[i].dir = f_dir;
//									}
//									else if (board[ty][tx] < i)
//									{
//										board[y][x] = 0;
//										shark[i].isDead = true;
//										isFind = true;
//									}
//								}
//								else
//								{
//									board[y][x] = 0;
//									board[ty][tx] = i;
//									shark[i].y = ty;
//									shark[i].x = tx;
//									isFind = true;
//									shark[i].dir = f_dir;
//								}
//								break;
//							}
//						}
//						if (!isFind)
//						{
//							for (int j = 0; j < 4; j++) //근처가 전부 냄새가 있어서 자기의 냄새로 가야할 경우
//							{
//								int f_dir = shark[i].rank[dir][j];//자기 냄새의 우선순위에 맞게
//								int ty = y + moveY[f_dir];
//								int tx = x + moveX[f_dir];
//
//								if (valid(ty, tx) && smell[ty][tx].first == i)
//								{
//									board[y][x] = 0;
//									board[ty][tx] = i;
//									shark[i].y = ty;
//									shark[i].x = tx;
//									shark[i].dir = f_dir;
//									break;
//								}
//							}
//						}
//					}
//				}
//				for (int i = 1; i <= m; i++)
//				{
//					if (shark[i].isDead == false)
//					{
//						int y = shark[i].y;
//						int x = shark[i].x;
//						smell[y][x].first = i;
//						smell[y][x].second = k;
//					}
//				}
//			};
//
//			auto remove_smell = [&]()
//			{
//				for (int i = 0; i < n; i++)
//				for (int j = 0; j < n; j++)
//				{
//					if (board[i][j] == 0 && smell[i][j].second > 0) //냄새이면서 냄새 횟수가 남아있을 경우
//					{
//						smell[i][j].second -= 1;
//						if (smell[i][j].second == 0)
//							smell[i][j].first = 0;
//					}
//				}
//			};
//			moving();
//			remove_smell();
//			time += 1;
//		}
//		if (time > 1000)
//			return -1;
//		return time;
//	};
//	cout << simulation();
//
//	return 0;
//}
//
///*
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int moveY[5] = { 0, -1, 1, 0, 0 };
//int moveX[5] = { 0, 0, 0, -1, 1 };
//
//int board[21][21];
//pair<int, int> smell[21][21];
//
//typedef struct
//{
//	int isDead;
//	int dir;
//	int y;
//	int x;
//	int rank[5][4];
//}Shark;
//
//Shark shark[401];
//int N, M, K;
//
//bool valid(int y, int x)
//{
//	if (y < 0 || x < 0 || y >= N || x >= N)
//		return false;
//	return true;
//}
//
//void remove_smell()
//{
//	for (int i = 0; i < N; i++)
//	for (int j = 0; j < N; j++)
//	{
//		if (board[i][j] == 0 && smell[i][j].second > 0)
//		{
//			smell[i][j].second -= 1;
//			if (smell[i][j].second == 0)
//			{
//				smell[i][j].first = 0;
//			}
//		}
//	}
//}
//
//void moving()
//{
//	for (int i = 1; i <= M; i++)
//	{
//		int dir = shark[i].dir;
//		int y = shark[i].y;
//		int x = shark[i].x;
//
//		bool isFind = false;
//
//		if (shark[i].isDead == false)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				int f_dir = shark[i].rank[dir][j];
//				int ty = y + moveY[f_dir];
//				int tx = x + moveX[f_dir];
//
//				if (valid(ty, tx) && smell[ty][tx].second == 0)
//				{
//					if (board[ty][tx] != 0)
//					{
//						if (board[ty][tx] > i)
//						{
//							board[y][x] = 0;
//							board[ty][tx] = i;
//							shark[i].y = ty;
//							shark[i].x = tx;
//							shark[board[ty][tx]].isDead = true;
//							isFind = true;
//							shark[i].dir = f_dir;
//						}
//						else if (board[ty][tx] < i)
//						{
//							board[y][x] = 0;
//							shark[i].isDead = true;
//							isFind = true;
//							break;
//						}
//					}
//					else
//					{
//						board[y][x] = 0;
//						board[ty][tx] = i;
//						shark[i].y = ty;
//						shark[i].x = tx;
//						isFind = true;
//						shark[i].dir = f_dir;
//					}
//
//					break;
//				}
//			}
//
//			if (!isFind)
//			{
//				for (int j = 0; j < 4; j++)
//				{
//					int f_dir = shark[i].rank[dir][j];
//					int ty = y + moveY[f_dir];
//					int tx = x + moveX[f_dir];
//
//					if (valid(ty, tx) && smell[ty][tx].first == i)
//					{
//						board[y][x] = 0;
//						board[ty][tx] = i;
//						shark[i].y = ty;
//						shark[i].x = tx;
//
//						shark[i].dir = f_dir;
//						break;
//					}
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i <= M; i++)
//	{
//		if (shark[i].isDead == false)
//		{
//			int y = shark[i].y;
//			int x = shark[i].x;
//
//			smell[y][x].first = i;
//			smell[y][x].second = K;
//		}
//	}
//}
//
//int simulation()
//{
//	int time = 0;
//
//	while (time <= 1000)
//	{
//		bool flag = false;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (board[i][j] != 0 && board[i][j] != 1)
//				{
//					flag = true;
//					break;
//				}
//			}
//		}
//		if (!flag)
//			break;
//
//		moving();
//		remove_smell();
//		time += 1;
//	}
//
//	if (time > 1000)
//		return -1;
//
//	return time;
//}
//
//int main()
//{
//	cin >> N >> M >> K;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> board[i][j];
//			if (board[i][j] != 0)
//			{
//				shark[board[i][j]].y = i;
//				shark[board[i][j]].x = j;
//			}
//		}
//	}
//
//	for (int i = 1; i <= M; i++)
//	{
//		int input;
//		cin >> input;
//		shark[i].dir = input;
//	}
//
//	for (int i = 1; i <= M; i++)
//	{
//		for (int k = 1; k <= 4; k++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				cin >> shark[i].rank[k][j];
//			}
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (board[i][j] != 0)
//				smell[i][j] = make_pair(board[i][j], K);
//		}
//	}
//
//	int res = simulation();
//	cout << res;
//
//	return 0;
//}
//*/
