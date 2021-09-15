#include<bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAX = 51;
int board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int ret = INT_MAX;
int vNum, zeroCnt;
vector<pair<int, int>> virus;
int my[] = {-1,1,0,0};
int mx[] = {0,0,-1,1};
int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                //조합의 경웅의 수를 만들 때 사용할 바이러스들을 저장합니다.
                virus.push_back({i, j});
                //조합을 구할 때 사용하기 위한 바이러스 갯수
                vNum++;
            }
            //모든 바이러스가 퍼졌는지 확인할 때 사용하기 위한 0의 갯수를 측정한 변수
            if(board[i][j] == 0){
                zeroCnt++;
            }
        }
    }

    //바이러스의 조합을 만드는과저 예제1 기준 00111 ~ 11100 까지의 모든 경우를 탐색
    vector<int> vArr;
    for (int i = 0; i < m; i++) {
        vArr.push_back(1);
    }
    for (int j = 0; j < vNum - m; j++) {
        vArr.push_back(0);
    }
    sort(vArr.begin(), vArr.end());

    int a = 0;
    do {
        memset(visited, false, sizeof visited);
        queue<pair<int, int>> q;
        for (int i = 0; i < vArr.size(); i++) {
            if (vArr[i] == 1) {
                q.push({virus[i].first, virus[i].second});
                visited[virus[i].first][virus[i].second] = true;
            }
        }

        int cnt = 0;
        int checkZc =0;
        while (!q.empty()) {

            //0을 확인한 갯수가 0의 총 갯수와 같다면 탐색 종료
            if(checkZc == zeroCnt){
                break;
            }
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto[y, x] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int ny = y + my[d];
                    int nx = x + mx[d];
                    if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                        if (!visited[ny][nx]){
                            //0이라면 0탐색 갯수를 올려주고 다음 탐색을 위한 q.push
                            if(board[ny][nx] == 0){
                                q.push({ny, nx});
                                visited[ny][nx] = true;
                                checkZc++;
                            }
                            //탐색 경우가 비활성화 바이러스라면 다음 탐색 때 활성화 시켜주기 위한 q.push
                            if(board[ny][nx] == 2){
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
            }
            cnt++;
        }
        //모든 파이러스가 퍼진 경우라면 걸린 시간(cnt)를 최소값으로 갱신
        if(checkZc == zeroCnt){
            ret = min(cnt, ret);
        }
    } while (next_permutation(vArr.begin(), vArr.end()));

    if(ret == INT_MAX)
        cout << "-1" <<"\n";
    else
        cout << ret << "\n";
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
//int board[MAX][MAX];
//int tmpboard[MAX][MAX];
//int n, m, ret = INT_MAX;
//bool flag;
//int moveY[] = { -1, 0, 1, 0 };
//int moveX[] = { 0, -1, 0, 1 };
//vector<pair<int,int>> virus;
//vector<int> tmp;
//
//int main(void)
//{
//	fastio;
//	cin >> n >> m;
//
//	int cnt = 0;
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++){
//		cin >> board[i][j];
//		if (board[i][j] == 0)
//			cnt++;
//		if (board[i][j] == 2)
//			virus.push_back({ i, j });
//	}
//	tmp.resize(virus.size());
//	for (int i = 0; i < tmp.size(); i++) tmp[i] = 0;
//	for (int i = 0; i < m; i++) tmp[i] = 1;
//	sort(tmp.begin(), tmp.end());
//
//	function<void(int)> BFS = [&](int cnt){
//		memcpy(tmpboard, board, sizeof(tmpboard));
//		queue<pair<int, int>> q;
//		for (int i = 0; i < tmp.size(); i++)
//		if (tmp[i]){
//			q.push(virus[i]);
//			tmpboard[virus[i].first][virus[i].second] = 3;
//		}
//		int time = 0;
//		while (!q.empty()){
//			int size = q.size();
//			if (!cnt){
//				flag = true;
//				ret = min(ret, time);
//				break;
//			}
//			time++;
//			for (int i = 0; i < size; i++)
//			{
//				int y = q.front().first;
//				int x = q.front().second;
//				q.pop();
//				for (int j = 0; j < 4; j++)
//				{
//					int nextY = y + moveY[j];
//					int nextX = x + moveX[j];
//					if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
//					if (tmpboard[nextY][nextX] == 0 || tmpboard[nextY][nextX] == 2)
//					{
//						if (tmpboard[nextY][nextX] == 0)
//							cnt--;
//						tmpboard[nextY][nextX] = 3;
//						q.push({ nextY, nextX });
//					}
//				}
//			}
//		}
//	};
//
//	do
//	{
//		BFS(cnt);
//	} while (next_permutation(tmp.begin(), tmp.end()));
//
//	if (!flag)
//		cout << -1 << "\n";
//	else
//		cout << ret << "\n";
//}
/*
#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int N, M;
int ret = INT_MAX;
int flag;
int board[MAX][MAX];
int tmpboard[MAX][MAX];
vector<pair<int, int>> virus;
vector<int> tmp;

int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

void DFS(int cnt)
{
	memcpy(tmpboard, board, sizeof(tmpboard));

	queue<pair<int, int>> q;
	for (int i = 0; i < tmp.size(); i++)
	if (tmp[i])
	{
		q.push(virus[i]);
		tmpboard[virus[i].first][virus[i].second] = 3;
	}
	int time = 0;

	while (!q.empty())
	{
		int size = q.size();
	
		if (!cnt)
		{
			flag = true;
			ret = min(ret, time);
			break;
		}

		time++;
		for (int i = 0; i < size; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int nextY = y + moveY[j];
				int nextX = x + moveX[j];

				if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
				if (tmpboard[nextY][nextX] == 0 || tmpboard[nextY][nextX] == 2)
				{
					if (tmpboard[nextY][nextX] == 0)
						cnt--;
					tmpboard[nextY][nextX] = 3;
					q.push({ nextY, nextX });
				}
			}
		}
	}
	return;
}

int main(void)
{
	cin >> N >> M;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 0)
			cnt++;
		if (board[i][j] == 2)
			virus.push_back({ i, j });
	}

	tmp.resize(virus.size());
	for (int i = 0; i < tmp.size(); i++)
		tmp[i] = 0;
	for (int i = 0; i < M; i++)
		tmp[i] = 1;

	sort(tmp.begin(), tmp.end()); 

	do
	{
		DFS(cnt);
	} while (next_permutation(tmp.begin(), tmp.end()));

	if (!flag)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
	
	return 0;
}
*/
