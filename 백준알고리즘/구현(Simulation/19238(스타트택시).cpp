#include <bits/stdc++.h>

using namespace std;
const int MAX = 21;
int my[] = {-1,0,1,0};
int mx[] = {0,-1,0,1};

struct Car{
    int y, x, gas;
};

bool operator < (const Car &a, const Car &b){
    if(a.gas != b.gas){
        return a.gas < b.gas;
    }
    if(a.y != b.y){
        return a.y > b.y;
    }
    if(a.x != b.x){
        return a.x > b.x;
    }
    return false;
}

struct drive{
    int n, m, k;
    int board[MAX][MAX];
    Car car;
    drive(int n, int m, int k) : n(n), m(m), k(k) {}
    tuple<int,int,int,int> cityzen[401];
    bool visited[MAX][MAX];
    int fNum;

    bool isValid(int y, int x){
        return (y >= 0 && y < n && x >= 0 && x < n);
    }

    void init(){
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
                if(board[i][j] == 1)
                    board[i][j] = -1;
            }
        }
        cin >> car.y >> car.x;
        car.gas = k;
        car.y--, car.x--;
        for(int i = 1; i <= m; i++){
            int sy, sx, ey, ex;
            cin >> sy >> sx >> ey >> ex;
            sy--, sx--, ey--, ex--;
            board[sy][sx] = i;
            cityzen[i] = {sy, sx, ey, ex};
        }
    }

    bool find_BFS(){
        priority_queue<Car> pq;
        pq.push({car.y, car.x, car.gas});
        visited[car.y][car.x] = true;
        memset(visited, false, sizeof visited);

        int cnt = 0;
        while(!pq.empty()){
            int pqSize = pq.size();

            for(int i = 0; i < pqSize; i++){
                auto[y, x, gas] = pq.top();
                pq.pop();

                if(board[y][x] > 0){
                    if(gas >= 0){
                        car.y = y;
                        car.x = x;
                        car.gas = gas;
                        fNum = board[y][x];
                        return true;
                    }
                    else
                        return false;
                }
                for(int d = 0; d < 4; d++){
                    int ny = y + my[d];
                    int nx = x + mx[d];
                    if(isValid(ny, nx)){
                        if(!visited[ny][nx] && board[ny][nx] != -1){
                            pq.push({ny, nx, gas - 1});
                            visited[ny][nx] = true;
                        }
                    }
                }
            }
            cnt++;
        }
        return false;
    }

    bool goal_BFS(){
        memset(visited, false, sizeof visited);
        queue<pair<int,int>> q;
        q.push({car.y, car.x});
        visited[car.y][car.x] = true;
        auto[sy, sx, ey, ex] = cityzen[fNum];
        int cnt = 0;

        while(!q.empty()){
            int qSize = q.size();
            for(int i =  0; i < qSize; i++){
                auto[y, x] = q.front();
                q.pop();
                if(y == ey && x == ex){
                    car.gas -= cnt;
                    if(car.gas >= 0){
                        car.gas += cnt * 2;
                        car.y = ey;
                        car.x = ex;
                        board[sy][sx] = 0;
                        return true;
                    } else{
                        return false;
                    }
                }
                for(int d = 0; d < 4; d++){
                    int ny = y + my[d];
                    int nx = x + mx[d];
                    if(isValid(ny, nx)){
                        if(!visited[ny][nx] && board[ny][nx] != -1){
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }
            }
            cnt++;
        }
        return false;
    }

    void printBoard(){
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] <<" ";
            }
            cout <<"\n";
        }
        cout <<"========board========" <<"\n";
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    drive op(n,m,k);
    op.init();
    //op.printBoard();
    for(int i = 0; i < m; i++){
        if(!op.find_BFS()){
            cout << "-1" <<"\n";
            return 0;
        }
        if(!op.goal_BFS()){
            cout << "-1" <<"\n";
            return 0;
        }
    }
    cout << op.car.gas << "\n";
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
//const int MAX = 21;
//typedef struct
//{
//	int y, x;
//	int gas;
//}Car;
//
//bool operator < (Car a, Car b)
//{
//	if (a.gas < b.gas)
//		return true;
//	if (a.gas == b.gas)
//	{
//		if (a.y > b.y)
//			return true;
//		if (a.y == b.y)
//		{
//			if (a.x > b.x)
//				return true;
//		}
//	}
//	return false;
//}
//
//int board[MAX][MAX];
//int moveY[] = {-1,0,1,0};
//int moveX[] = {0,-1,0,1};
//bool visited[MAX][MAX];
//int n, m, g;
//Car car;
//
//int main(void)
//{
//	fastio;
//
//	cin >> n >> m >> g;
//
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//	{
//		cin >> board[i][j];
//		if (board[i][j] == 1)
//			board[i][j] = INT_MAX;
//	}
//	int carY, carX;
//	cin >> carY >> carX;
//	carY--, carX--;
//	car.y = carY, car.x = carX, car.gas = g;
//
//	vector<tuple<int, int, int, int>> road(m + 1);
//
//	for (int i = 1; i <= m; i++)
//	{
//		int sy, sx, ey, ex;
//		cin >> sy >> sx >> ey >> ex;
//		sy--, sx--, ey--, ex--;
//		road[i] = make_tuple( sy, sx, ey, ex );
//		board[sy][sx] = i;
//	}
//
//	auto BFS = [&]() -> bool
//	{
//		memset(visited, false, sizeof(visited));
//		priority_queue<Car> pq;
//		pq.push({ car.y,car.x, car.gas});
//		visited[car.y][car.x] = true;
//		int sdGas = 0;
//		while (!pq.empty())
//		{
//			int qSize = pq.size();
//			for (int i = 0; i < qSize; i++)
//			{
//				int curY = pq.top().y;
//				int curX = pq.top().x;
//				int curGas = pq.top().gas;
//				pq.pop();
//				if (board[curY][curX] != 0 && board[curY][curX] != INT_MAX)
//				{
//					car.gas -= sdGas;
//					if (car.gas >= 0)
//					{
//						car.y = curY;
//						car.x = curX;
//						int pnum = board[curY][curX];
//						int pY = get<0>(road[board[curY][curX]]);
//						int pX = get<1>(road[board[curY][curX]]);
//						auto BFS2 = [&](int y, int x, int pnum) -> bool
//						{
//							memset(visited, false, sizeof(visited));
//							queue<pair<int, int>> q;
//							int sY = get<0>(road[pnum]);
//							int sX = get<1>(road[pnum]);
//							int eY = get<2>(road[pnum]);
//							int eX = get<3>(road[pnum]);
//							q.push({ car.y, car.x });
//
//							int sdGas = 0;
//							while (!q.empty())
//							{
//								int qSize = q.size();
//								for (int i = 0; i < qSize; i++)
//								{
//									int y = q.front().first;
//									int x = q.front().second;
//									q.pop();
//
//									if (y == eY && x == eX)
//									{
//										car.gas -= sdGas;
//										if (car.gas >= 0)
//										{
//											car.gas += sdGas * 2;
//											car.y = eY;
//											car.x = eX;
//											board[sY][sX] = 0;
//											return true;
//										}
//										else
//											return false;
//									}
//									for (int i = 0; i < 4; i++)
//									{
//										int nextY = y + moveY[i];
//										int nextX = x + moveX[i];
//
//										if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n)
//										if (board[nextY][nextX] != INT_MAX && !visited[nextY][nextX])
//										{
//											q.push({ nextY, nextX });
//											visited[nextY][nextX] = true;
//										}
//									}
//								}
//								sdGas++;
//							}
//							return false;
//						};
//						if (BFS2(pY, pX, pnum))
//							return true;
//						else
//							return false;
//					}
//					else
//						return false;
//				}
//
//				for (int i = 0; i < 4; i++)
//				{
//					int nextY = curY + moveY[i];
//					int nextX = curX + moveX[i];
//
//					if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n)
//					if (board[nextY][nextX] != INT_MAX && !visited[nextY][nextX])
//					{
//						pq.push({ nextY, nextX, curGas -1 });
//						visited[nextY][nextX] = true;
//					}
//				}
//			}
//			sdGas++;
//		}
//		return false;
//	};
//
//	for (int i = 0; i < m; i++)
//	{
//		if (!BFS())
//		{
//			cout << -1 << '\n';
//			return 0;
//		}
//	}
//
//	cout << car.gas << '\n';
//}

/*
#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int moveY[] = { 1, -1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

typedef struct
{
	int y, x;
	int gas;
}State;

bool operator < (State a, State b)
{
	if (a.gas < b.gas)
		return true;

	if (a.gas == b.gas)
	{
		if (a.y > b.y)
			return true;

		if (a.y == b.y)
		{
			if (a.x > b.x)
			{
				return true;
			}
		}
	}
	return false;
}

int N, M;
int gas;
int road[MAX][MAX];
map<pair<int, int>, pair<int, int>> start2Destination;

bool func(pair<int, int> start)
{
	pair<int, int> destination = start2Destination[start];

	queue<pair<State, int>> q;
	q.push({ { start.first, start.second, gas }, 0 });

	bool visited[MAX][MAX] = { false };
	visited[start.first][start.second] = true;
	
	while (!q.empty())
	{
		int y = q.front().first.y;
		int x = q.front().first.x;
		int curGas = q.front().first.gas;
		int cnt = q.front().second;
		q.pop();

		if (curGas == -1)
			return false;

		if (y == destination.first && x == destination.second)
		{
			gas = curGas + cnt * 2;
			return true;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = y + moveY[k];
			int nextX = x + moveX[k];

			if (!(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N))
			if (!(visited[nextY][nextX] || road[nextY][nextX]))
			{
				visited[nextY][nextX] = true;
				q.push({ { nextY, nextX, curGas - 1 }, cnt + 1 });
			}
		}
	}
	return false;
}
int main(void)
{
	cin >> N >> M >> gas;

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		cin >> road[i][j];
	}

	pair<int, int> startCar;
	cin >> startCar.first >> startCar.second;
	startCar.first--;
	startCar.second--;

	for (int i = 0; i < M; i++)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		start2Destination[{y1 - 1, x1 - 1}] = { y2 - 1, x2 - 1 };
	}

	while (1)
	{
		priority_queue<State> pq;
		pq.push({ startCar.first, startCar.second, gas });

		bool visited[MAX][MAX] = { false, };
		visited[startCar.first][startCar.second] = true;

		bool flag = false;

		while (!pq.empty())
		{
			int y = pq.top().y;
			int x = pq.top().x;
			int curGas = pq.top().gas;
			pq.pop();

			if (curGas == -1)
				break;

			if (start2Destination.count({ y, x }) && start2Destination[{y, x}].first != -1)
			{
				startCar = { y, x };
				flag = true;
				gas = curGas;
				break;
			}

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveY[k];
				int nextX = x + moveX[k];

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
					continue;

				if (visited[nextY][nextX] || road[nextY][nextX])
					continue;

				visited[nextY][nextX] = true;
				pq.push({ nextY, nextX, curGas - 1 });
			}
		}

		if (flag == false)
		{
			cout << -1 << "\n";
			return 0;
		}

		if (func(startCar) == false)
		{
			cout << -1 << "\n";
			return 0;
		}

		M--;
		if (M == 0)
		{
			cout << gas << "\n";
			return 0;
		}

		pair<int, int> temp = startCar;
		startCar = start2Destination[{startCar.first, startCar.second}];
		start2Destination[{temp.first, temp.second}] = { -1, -1 };
	}
	return 0;	
}
*/
