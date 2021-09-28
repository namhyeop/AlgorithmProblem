//먼저 l단계를 결정한다.
//2^l * 2 ^ l로 나눈다
//그 후 모든 분 격자를 시계 방향으로 90도 회전
//인접해있는 얼음이 3개가 아닐 경우 cnt--

#include<bits/stdc++.h>

using namespace std;
const int MAX = 1 << 7;

int my[] = {-1,0,1,0};
int mx[] = {0,-1,0,1};

struct game{
    int n, q;
    int board[MAX][MAX];
    vector<int> L;
    game(int n, int q) : n(n), q(q), L(q) {} //여기에다가 초기화 하고 싶은데 어떻게 하는거죠?

    bool isvalid(int y, int x){
        return (y >= 0 && y < n && x >= 0 && x < n);
    }
    void init(){
        n = (1 << n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        for(int i = 0; i < q; i++){
            cin >> L[i];
        }
    }

    void divide(){
        for(int t = 0; t < q; t++){
            int powValue = L[t];
            for(int i = 0; i < n; i+= (1 << powValue)){
                for(int j = 0; j < n; j+=(1 << powValue)){
                    rotate(i, j, powValue);
                }
            }
            minusIce();
        }
    };

    void rotate(int i, int j, int l){
        int tmpA[MAX][MAX];
        for (int y = i; y < i + (1 << l); y++)
            for (int x = j; x < j + (1 << l); x++)
                tmpA[y][x] = board[y][x];

            for (int y = i; y < i + (1 << l); y++)
                for (int x = j; x < j + (1 << l); x++)
                    board[x + i - j][i + (1 << l) - (y + 1) + j] = tmpA[y][x];
                //        int tmpboard[1 << 7][1 << 7];
                //        memcpy(tmpboard, board, sizeof tmpboard);
                //
                //
                //        for(int i = 0; i < (1 << powValue); i++){
                //            for(int j = 0; j < (1 << powValue); j++){
                //                board[y + j][x + (1 << powValue) - i - 1] = tmpboard[y + i][x + j];
                //            }
                //        }
    }

    void minusIce(){
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0)
                    continue;
                int cnt = 0;
                for(int d = 0; d <4; d++){
                    int ny = i + my[d];
                    int nx = j + mx[d];
                    if(!isvalid(ny, nx))
                        continue;
                    if(board[ny][nx] == 0)
                        continue;
                    cnt++;
                }
                if(cnt < 3)
                    q.push({i, j});
            }
        }

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            board[y][x]--;
        }
    }

    int sumIce(){
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += board[i][j];
            }
        }
        return sum;
    }

    int landCnt(){
        bool visited[1 << 7][1 << 7];
        memset(visited, false, sizeof visited);
        int ret = 0;

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                auto BFS = [&](int y, int x) -> int{
                    queue<pair<int,int>> q;
                    q.push({y, x});
                    visited[y][x] = true;
                    int cnt = 0;
                    while(!q.empty()){
                        auto[cy, cx] = q.front();
                        q.pop();

                        //if(board[cy][cx] > 0)
                        cnt++;

                        for(int d = 0; d < 4; d++){
                            int ny = cy + my[d];
                            int nx = cx + mx[d];

                            if(isvalid(ny, nx)){
                                if(board[ny][nx] != 0 && !visited[ny][nx]){
                                    // cout << "ny : " << ny << " nx" << nx <<"\n";
                                    q.push({ny, nx});
                                    visited[ny][nx] = true;
                                }
                            }
                        }
                    }
                    return cnt;
                };
                if(!visited[i][j] && board[i][j])
                    ret = max(ret, BFS(i, j));
            }
        }
        return ret;
    }

    void printBoard(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout <<"\n";
        }
        cout <<"=========board========" <<"\n";
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    game op(n, q);
    op.init();
    op.divide();
    cout << op.sumIce() <<"\n";
    cout << op.landCnt() <<"\n";
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
//const int MAX = 64;
//
//int moveY[] = { -1, 0, 1, 0 };
//int moveX[] = { 0, -1, 0, 1 };
//bool visited[MAX][MAX];
//int board[MAX][MAX];
//int n, q;
//
//int main(void)
//{
//	fastio;
//
//	cin >> n >> q;
//
//	for (int i = 0; i < (1 << n); i++)
//	for (int j = 0; j < (1 << n); j++)
//		cin >> board[i][j];
//
//	while (q--)
//	{
//		int l;
//		cin >> l;
//
//		auto fireStorm = [&]()
//		{
//			queue<pair<int, int>> q;
//			for (int i = 0; i < (1 << n); i++)
//			for (int j = 0; j < (1 << n); j++)
//			{
//				if (!board[i][j])
//					continue;
//
//				int adjacentCnt = 0;
//				for (int d = 0; d < 4; d++)
//				{
//					int nextY = i + moveY[d];
//					int nextX = j + moveX[d];
//
//					if (nextY >= 0 && nextY < (1 << n) && nextX >= 0 && nextX < (1 << n))
//					{
//						if (board[nextY][nextX])
//							adjacentCnt++;
//					}
//				}
//				if (adjacentCnt < 3)
//					q.push({ i, j });
//			}
//
//			while (!q.empty())
//			{
//				int y = q.front().first;
//				int x = q.front().second;
//				q.pop();
//
//				board[y][x]--;
//			}
//		};
//
//		auto rotate = [&](int i , int j , int l)
//		{
//			int tmpA[MAX][MAX];
//			for (int y = i; y < i + (1 << l); y++)
//			for (int x = j; x < j + (1 << l); x++)
//				tmpA[y][x] = board[y][x];
//
//			for (int y = i; y < i + (1 << l); y++)
//			for (int x = j; x < j + (1 << l); x++)
//				board[x + i - j][i + (1 << l) - (y + 1) + j] = tmpA[y][x];
//		};
//		//i = 3, j = 0;
//		//tmp[j][n - i - 1] = tmp[i][j]
//		for (int i = 0; i < (1 << n); i += (1 << l))
//		for (int j = 0; j < (1 << n); j += (1 << l))
//			rotate(i, j, l);
//
//		fireStorm();
//	}
//
//	auto iceSum = [&]() -> int
//	{
//		int ret = 0;
//		for (int i = 0; i < (1 << n); i++)
//		for (int j = 0; j < (1 << n); j++)
//			ret += board[i][j];
//		return ret;
//	};
//
//	auto bigestPart = [&]() -> int
//	{
//		auto BFS = [&](int y, int x)
//		{
//			queue<pair<int, int>> q;
//			q.push({ y, x });
//			visited[y][x] = true;
//			int cnt = 0;
//
//			while (!q.empty())
//			{
//				int y = q.front().first;
//				int x = q.front().second;
//				q.pop();
//
//				cnt++;
//				for (int d = 0; d < 4; d++)
//				{
//					int nextY = y + moveY[d];
//					int nextX = x + moveX[d];
//
//					if (nextY >= 0 && nextY < (1 << n) && nextX >= 0 && nextX < (1 << n))
//					if (board[nextY][nextX] && !visited[nextY][nextX])
//					{
//						q.push({ nextY, nextX });
//						visited[nextY][nextX] = true;
//					}
//				}
//			}
//			return cnt;
//		};
//
//		int ret = 0;
//		for (int i = 0; i < (1 << n); i++)
//		for (int j = 0; j < (1 << n); j++)
//		if (!visited[i][j] && board[i][j])
//			ret = max(ret, BFS(i, j));
//		return ret;
//	};
//
//	cout << iceSum() << "\n";
//	cout << bigestPart() << "\n";
//}
///*
//#include<bits/stdc++.h>
//#define MAX 64
//using namespace std;
//
//int N, Q;
//int board[MAX][MAX];
//int temp[MAX][MAX];
//bool checkMelt[MAX][MAX];
//bool visited[MAX][MAX];
//
//int moveY[] = { -1, 1, 0, 0 };
//int moveX[] = { 0, 0, -1, 1 };
//
//int validRange(int nextY, int nextX)
//{
//	return nextY >= 0 && nextX >= 0 && nextY < N && nextX < N;
//}
//
//int dfs(int y, int x)
//{
//	visited[y][x] = true;
//	int ret = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int nextY = y + moveY[i];
//		int nextX = x + moveX[i];
//		if (validRange(nextY, nextX) && !visited[nextY][nextX])
//		if (board[nextY][nextX] > 0)
//			ret += dfs(nextY, nextX);
//	}
//	return ret;
//}
//
//int maxValue()
//{
//	int ret = 0;
//	for (int i = 0; i < N; i++)
//	for (int j = 0; j < N; j++)
//	{
//		if (board[i][j] > 0 && !visited[i][j])
//			ret = max(ret, dfs(i, j));
//	}
//	return ret;
//}
//
//int allSum()
//{
//	int sum = 0;
//	for (int i = 0; i < N; i++)
//	for (int j = 0; j < N; j++)
//		sum += board[i][j];
//	return sum;
//}
//
//void rotate(int y, int x, int L)
//{
//	for (int i = 0; i < L; i++)
//	for (int j = 0; j < L; j++)
//		temp[i][j] = board[y + L - 1 - j][x + i];
//
//	for (int i = 0; i < L; i++)
//	for (int j = 0; j < L; j++)
//		board[y + i][x + j] = temp[i][j];
//}
//
//void solve(int L)
//{
//	L = (1 << L);
//
//	for (int i = 0; i < N; i+= L)
//	for (int j = 0; j < N; j+= L)
//		rotate(i, j, L);
//
//	memset(checkMelt, false, sizeof(checkMelt));
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (board[i][j] == 0)
//				continue;
//			int cnt = 0;
//			for (int k = 0; k < 4; k++)
//			{
//				int nextY = i + moveY[k];
//				int nextX = j + moveX[k];
//				if (!validRange(nextY, nextX))
//					continue;
//				if (board[nextY][nextX] > 0)
//					cnt++;
//			}
//			if (cnt < 3)
//				checkMelt[i][j] = true;
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	for (int j = 0; j < N; j++)
//	if (checkMelt[i][j])
//		board[i][j]--;
//}
//
//int main()
//{
//	cin >> N >> Q;
//
//	N = (1 << N);
//
//	for (int i = 0; i < N; i++)
//	for (int j = 0; j < N; j++)
//		cin >> board[i][j];
//
//	for (int i = 0; i < Q; i++)
//	{
//		int L;
//		cin >> L;
//		solve(L);
//	}
//
//	cout << allSum() << "\n";
//	cout << maxValue() << "\n";
//
//	return 0;
//}
//*/
