#include<bits/stdc++.h>

using namespace std;
const int MAX = 51;
int n, l, r;
int board[MAX][MAX];
int ret;
int moveY[] = {-1, 1, 0, 0};
int moveX[] = {0, 0, -1, 1};

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    bool visited[MAX][MAX];
    while (1) {
        memset(visited, false, sizeof visited);
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(visited[i][j])
                    continue;

                vector<pair<int,int>> v;
                v.push_back({i, j});
                int pSum = board[i][j];
                int pCnt = 1;

                auto BFS = [&](){
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        auto [y,x] = q.front();
                        q.pop();

                        for(int d = 0; d < 4; d++){
                            int ny = y + moveY[d];
                            int nx = x + moveX[d];

                            if(ny < 0 || ny >= n || nx < 0 || nx >= n){
                                continue;
                            }
                            int diff = abs(board[y][x] - board[ny][nx]);
                            if(diff >= l && diff <= r && !visited[ny][nx]){
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                                v.push_back({ny, nx});
                                pSum += board[ny][nx];
                                pCnt++;
                            }
                        }
                    }
                };
                BFS();

                if(pCnt >= 2){
                    flag = true;
                    for(int i = 0; i <v.size(); i++){
                        board[v[i].first][v[i].second] = pSum/pCnt;
                    }
                }
            }
        }
        if(flag)
            ret++;
        else
            break;
    }

    cout << ret << "\n";
}

//#include<bits/stdc++.h>
//#define MAX 51
//using namespace std;
//
//int n, l, r;
//int sum;
//int cnt;
//int ans;
//
//int board[MAX][MAX];
//bool visited[MAX][MAX];
//
//vector<pair<int, int>> v;
//
//bool pplFlag;
//int moveY[4] = { 0, 1, 0, -1 };
//int moveX[4] = { 1, 0, -1, 0 };
//
//void changePPL()
//{
//	int avg = sum / cnt;
//	for (int i = 0; i < v.size(); i++)
//	{
//		int y = v[i].first;
//		int x = v[i].second;
//		board[y][x] = avg;
//	}
//}
//void BFS(int y, int x)
//{
//	queue<pair<int, int>> q;
//	q.push({ y, x });
//	v.push_back({ y, x });
//	visited[y][x] = true;
//	sum += board[y][x];
//	cnt++;
//
//	while (!q.empty())
//	{
//		int cury = q.front().first;
//		int curx = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextY = cury + moveY[i];
//			int nextX = curx + moveX[i];
//
//			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
//				continue;
//			if (visited[nextY][nextX])
//				continue;
//
//			int sub = abs(board[cury][curx] - board[nextY][nextX]);
//
//			if (l <= sub && sub <= r)
//			{
//				visited[nextY][nextX] = true;
//				sum += board[nextY][nextX];
//				cnt++;
//				q.push({ nextY, nextX });
//				v.push_back({ nextY, nextX });
//			}
//		}
//	}
//
//	if (v.size() > 1)
//	{
//		changePPL();
//		pplFlag = true;
//	}
//
//	v.clear();
//	sum = 0;
//	cnt = 0;
//}
//int main(void)
//{
//	cin >> n >> l >> r;
//
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//		cin >> board[i][j];
//
//	while (1)
//	{
//		memset(visited, false, sizeof(visited));
//		pplFlag = false;
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			if (!visited[i][j])
//				BFS(i, j);
//		}
//
//		if (pplFlag)
//			ans++;
//		else
//			break;
//
//	}
//	cout << ans << "\n";
//	return 0;
//}
