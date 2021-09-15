#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0). cout.tie(0);

using namespace std;
const int MAX = 101;
int board[MAX][MAX];
int R, C, K;

int main() {
    cin >> R >> C >> K;
    //board에서 조회값을 해야하므로 1씩 감축
    R--, C--;
    bool flag = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            cin >> num;
            board[i][j] = num;
            //이미 탐색이 가능하며 K값일 경우 flag = true;
            if (i == R && j == C && num == K)
                flag = true;
        }
    }
    //기본 row, col 값
    int row = 3;
    int col = 3;
    int cnt = 0;
    while (!flag){
        cnt++;
        //100이상일 경우 -1을 출력하고 탐색 종료
        if (cnt > 100) {
            cout << -1 << "\n";
            return 0;
        }
        vector<pair<int, int>> v[MAX];
        //R정렬
        if (row >= col) {
            for (int i = 0; i < row; i++) {
                int cnt[MAX] = {0,};
                //나온 숫자들의 갯수를 확인해주는 과정
                for (int j = 0; j < col; j++)
                    cnt[board[i][j]]++;

                //나온 숫자들이 있는 경우 나온 횟수와 숫자의 쌍을 대입한다.
                for (int j = 1; j < MAX; j++) {
                    if (cnt[j])
                        v[i].push_back({cnt[j], j});
                }
            }
            //board의 값을 정렬한 이후의 board로 갱신해주기 위한 board 초기화
            memset(board, 0, sizeof(board));

            //나온 횟수가 적은 순서를 위한 정렬
            for (int i = 0; i < row; i++)
                sort(v[i].begin(), v[i].end());

            //board에 값을 최신화 하는 과정
            for (int i = 0; i < row; i++) {
                int idx = 0;
                for (int j = 0; j < v[i].size(); j++) {
                    board[i][idx++] = v[i][j].second;
                    if (idx == MAX)
                        break;
                    board[i][idx++] = v[i][j].first;
                    if (idx == MAX)
                        break;
                }
                //row의 값이 길어지면 col도 늘어나므로 크기를 갱신해준다.
                col = max(col, idx);
            }
        }
        //C정렬(위와 동일함)
        else{
            for(int i = 0; i <col; i++){
                int cnt[MAX] = {0};
                for(int j  = 0; j < row; j++)
                    cnt[board[j][i]]++;
                for(int j = 1; j < MAX; j++){
                    if(cnt[j]){
                        v[i].push_back({cnt[j], j});
                    }
                }
            }

            memset(board, 0, sizeof(board));

            for(int i = 0; i < col; i++){
                sort(v[i].begin(), v[i].end());
            }

            for(int i = 0; i < col; i++){
                int idx = 0;
                for(int j = 0; j < v[i].size(); j++){
                    board[idx++][i] = v[i][j].second;
                    if(idx == MAX)
                        break;
                    board[idx++][i] = v[i][j].first;
                    if (idx == MAX)
                        break;
                }
                row = max(row, idx);
            }
        }
        if(board[R][C] == K){
            flag = true;
            break;
        }
    }
    cout << cnt <<"\n";
}

//#include<bits/stdc++.h>
//#define MAX 100
//using namespace std;
//
//int r, c, k;
//int board[MAX][MAX];
//
//int main(void)
//{
//	cin >> r >> c >> k;
//	r -= 1;
//	c -= 1;
//
//	int time = 0;
//	bool flag = false;
//	for (int i = 0; i < 3; i++)
//	for (int j = 0; j < 3; j++)
//	{
//		int num;
//		cin >> num;
//
//		board[i][j] = num;
//
//		//이미 찾을 수 있는 경우
//		if (i == r && j == c && num == k)
//			flag = true;
//	}
//
//	int row = 3;
//	int col = 3;
//
//	while (!flag)
//	{
//		time++;
//
//		if (time > MAX)
//		{
//			cout << -1 << "\n";
//			return 0;
//		}
//		vector<pair<int, int>> v[MAX];
//		if (row >= col)
//		{
//			for (int i = 0; i < row; i++)
//			{
//				int cnt[MAX + 1] = { 0, };
//				for (int j = 0; j < col; j++)
//					cnt[board[i][j]]++;
//
//				for (int j = 1; j <= MAX; j++)
//				if (cnt[j])
//					v[i].push_back({ cnt[j], j });
//			}
//
//			for (int i = 0; i < row; i++)
//			for (int j = 0; j < col; j++)
//				board[i][j] = 0;
//
//			for (int i = 0; i < row; i++)
//				sort(v[i].begin(), v[i].end());
//
//			for (int i = 0; i < row; i++)
//			{
//				int idx = 0;
//				for (int j = 0; j < v[i].size(); j++)
//				{
//					board[i][idx++] = v[i][j].second;
//					if (idx == MAX)
//						break;
//					board[i][idx++] = v[i][j].first;
//					if (idx == MAX)
//						break;
//				}
//				col = max(col, idx);
//			}
//		}
//		else
//		{
//			for (int i = 0; i < col; i++)
//			{
//				int cnt[MAX + 1] = { 0, };
//				for (int j = 0; j < row; j++)
//					cnt[board[j][i]]++;
//
//				for (int j = 1; j <= MAX; j++)
//				if (cnt[j])
//					v[i].push_back({ cnt[j], j });
//			}
//
//			for (int i = 0; i < row; i++)
//			for (int j = 0; j < col; j++)
//				board[i][j] = 0;
//
//			for (int i = 0; i < col; i++)
//				sort(v[i].begin(), v[i].end());
//
//			for (int i = 0; i < col; i++)
//			{
//				int idx = 0;
//				for (int j = 0; j < v[i].size(); j++)
//				{
//					board[idx++][i] = v[i][j].second;
//					if (idx == MAX)
//						break;
//					board[idx++][i] = v[i][j].first;
//					if (idx == MAX)
//						break;
//				}
//				row = max(row, idx);
//			}
//		}
//
//		if (board[r][c] == k)
//		{
//			flag = true;
//			break;
//		}
//	}
//	cout << time << "\n";
//	return 0;
//}
