#include<bits/stdc++.h>

using namespace std;
const int MAX = 21;

int my[] = {-1, 0, 1, 0};
int mx[] = {0, 1, 0, -1};

struct game{
    int n;
    int ret;
    int board[MAX][MAX];
    game(int n) : n(n), ret(0) {}

    bool isValid(int y, int x){
        return y >= 0 && y < n && x >= 0 && x < n;
    }

    void init(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
    }

    void move(int tmpboard[MAX][MAX], int dir){
        int tmptmpboard[MAX][MAX];
        memset(tmptmpboard, 0 ,sizeof tmptmpboard);
        if(dir == 0){ //북
            for(int i = 0; i < n; i++){
                int posIdx = 0;
                for(int j = 0; j < n; j++)
                    if(tmpboard[j][i]){
                        if(tmptmpboard[posIdx][i] == 0){
                            tmptmpboard[posIdx][i] = tmpboard[j][i];
                        }
                        else if(tmptmpboard[posIdx][i] == tmpboard[j][i]){
                            tmptmpboard[posIdx++][i] *= 2;
                        }
                        else{
                            tmptmpboard[++posIdx][i] = tmpboard[j][i];
                        }
                    }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    tmpboard[i][j] = tmptmpboard[i][j];
                }
            }
        }
        else if(dir == 1){ //동
            for(int i = 0; i < n; i++){
                int posIdx = n - 1;
                for(int j = n - 1; j >= 0; j--)
                    if(tmpboard[i][j]){
                        if(tmptmpboard[i][posIdx] == 0){
                            tmptmpboard[i][posIdx] = tmpboard[i][j];
                        }
                        else if(tmptmpboard[i][posIdx] == tmpboard[i][j]){
                            tmptmpboard[i][posIdx--] *= 2;
                        }
                        else{
                            tmptmpboard[i][--posIdx] = tmpboard[i][j];
                        }
                    }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    tmpboard[i][j] = tmptmpboard[i][j];
                }
            }
        }
        else if(dir == 2){//남
            for(int i = 0; i < n; i++){
                int posIdx = n - 1;
                for(int j = n - 1; j >= 0; j--)
                    if(tmpboard[j][i]){
                        if(tmptmpboard[posIdx][i] == 0){
                            tmptmpboard[posIdx][i] = tmpboard[j][i];
                        }
                        else if(tmptmpboard[posIdx][i] == tmpboard[j][i]){
                            tmptmpboard[posIdx--][i] *= 2;
                        }
                        else{
                            tmptmpboard[--posIdx][i] = tmpboard[j][i];
                        }
                    }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    tmpboard[i][j] = tmptmpboard[i][j];
                }
            }
        }
        else if(dir == 3){//서
            for(int i = 0; i < n; i++){
                int posIdx = 0;
                for(int j = 0; j < n; j++)
                    if(tmpboard[i][j]){
                        if(tmptmpboard[i][posIdx] == 0){
                            tmptmpboard[i][posIdx] = tmpboard[i][j];
                        }
                        else if(tmptmpboard[i][posIdx] == tmpboard[i][j]){
                            tmptmpboard[i][posIdx++] *= 2;
                        }
                        else{
                            tmptmpboard[i][++posIdx] = tmpboard[i][j];
                        }
                    }
            }

            //memcpy(tmpboard, tmptmpboard, sizeof tmpboard); , 사용하면 오류 발생 왜냐하면 매개변수를 포인터로 배열로 넘겨서 tmpboard의 자료형은 4이다
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    tmpboard[i][j] = tmptmpboard[i][j];
                }
            }
        }
    }

    void DFS(int board[MAX][MAX], int level){
        if(level == 5){
            ret = max(getMaxValue(board), ret);
            return ;
        }
        int tmpboard[MAX][MAX];
        memcpy(tmpboard, board, sizeof tmpboard);

        for(int d = 0; d < 4; d++){
            move(tmpboard, d);
            DFS(tmpboard, level + 1);
            memcpy(tmpboard, board, sizeof tmpboard);
        }
    }

    int getMaxValue(int board[MAX][MAX]){
        int ret = INT_MIN;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                ret = max(ret, board[i][j]);
            }
        return ret;
    }

    void printBoard(int board[MAX][MAX]){
        for(int i = 0; i < n; i++){
            for(int j =0 ; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout <<"\n";
        }
        cout << "=================" <<"\n";
    }
};
int main(){
    int n;
    cin >> n;
    game op(n);
    op.init();
    op.DFS(op.board, 0);
    cout << op.ret <<"\n";
}

////20210605 두 번째
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
//const int MAX = 21;
//int board[MAX][MAX];
//int maxValue;
//int n;
//
//void dfs(int cnt)
//{
//	auto shift = [&](int type)
//	{
//		queue<int> q;
//
//		switch (type)
//		{
//		case 0: //좌
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = 0; j < n; j++)
//				{
//					if (board[i][j])
//						q.push(board[i][j]);
//					board[i][j] = 0;
//				}
//				int idx = 0;
//
//				while (!q.empty())
//				{
//					int data = q.front();
//					q.pop();
//
//					if (board[i][idx] == 0)
//						board[i][idx] = data;
//					else if (board[i][idx] == data)
//					{
//						board[i][idx] *= 2;
//						idx++;
//					}
//					else
//					{
//						idx++;
//						board[i][idx] = data;
//					}
//				}
//			}
//			break;
//		case 1://우
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = n - 1; j >= 0; j--)
//				{
//					if (board[i][j])
//						q.push(board[i][j]);
//					board[i][j] = 0;
//				}
//				int idx = n - 1;
//
//				while (!q.empty())
//				{
//					int data = q.front();
//					q.pop();
//
//					if (board[i][idx] == 0)
//						board[i][idx] = data;
//					else if (board[i][idx] == data)
//					{
//						board[i][idx] *= 2;
//						idx--;
//					}
//					else
//					{
//						idx--;
//						board[i][idx] = data;
//					}
//				}
//			}
//			break;
//		case 2://상
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = 0; j < n; j++)
//				{
//					if (board[j][i])
//						q.push(board[j][i]);
//
//					board[j][i] = 0;
//
//				}
//
//				int idx = 0;
//				while (!q.empty())
//				{
//					int data = q.front();
//					q.pop();
//
//					if (board[idx][i] == 0)
//						board[idx][i] = data;
//					else if (board[idx][i] == data)
//					{
//						board[idx][i] *= 2;
//						idx++;
//					}
//					else
//					{
//						idx++;
//						board[idx][i] = data;
//					}
//				}
//			}
//			break;
//		case 3://하
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = n - 1; j >= 0; j--)
//				{
//					if (board[j][i])
//						q.push(board[j][i]);
//					board[j][i] = 0;
//				}
//				int idx = n - 1;
//				while (!q.empty())
//				{
//					int data = q.front();
//					q.pop();
//
//					if (board[idx][i] == 0)
//						board[idx][i] = data;
//					else if (board[idx][i] == data)
//					{
//						board[idx][i] *= 2;
//						idx--;
//					}
//					else
//					{
//						idx--;
//						board[idx][i] = data;
//
//					}
//				}
//			}
//			break;
//		}
//	};
//
//	if (cnt == 5)
//	{
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			maxValue = max(maxValue, board[i][j]);
//		}
//		return;
//	}
//
//	int tmpboard[MAX][MAX];
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//		tmpboard[i][j] = board[i][j];
//
//	for (int i = 0; i < 4; i++)
//	{
//		shift(i);
//		dfs(cnt + 1);
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			board[i][j] = tmpboard[i][j];
//	}
//};
//
//int main(void)
//{
//	fastio;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//		cin >> board[i][j];
//
//	dfs(0);
//	cout << maxValue << "\n";
//
//}

// auto shift = [&](int type)
//{
//	queue<int> q;

//	switch (type)
//	{
//	case 0: //좌
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (board[i][j])
//					q.push(board[i][j]);
//				board[i][j] = 0;
//			}
//			int idx = 0;

//			while (!q.empty())
//			{
//				int data = q.front();
//				q.pop();

//				if (board[i][idx] == 0)
//					board[i][idx] = data;
//				else if (board[i][idx] == data)
//				{
//					board[i][idx] *= 2;
//					idx++;
//				}
//				else
//				{
//					idx++;
//					board[i][idx] = data;
//				}
//			}
//		}
//		break;
//	case 1://우
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = n - 1; j >= 0; j--)
//			{
//				if (board[i][j])
//					q.push(board[i][j]);
//				board[i][j] = 0;
//			}
//			int idx = n - 1;

//			while (!q.empty())
//			{
//				int data = q.front();
//				q.pop();

//				if (board[i][idx] == 0)
//					board[i][idx] = data;
//				else if (board[i][idx] == data)
//				{
//					board[i][idx] *= 2;
//					idx--;
//				}
//				else
//				{
//					idx--;
//					board[i][idx] = data;
//				}
//			}
//		}
//		break;
//	case 2://상
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (board[j][i])
//				{
//					q.push(board[j][i]);
//					board[j][i] = 0;
//				}
//			}

//			int idx = 0;
//			while (!q.empty())
//			{
//				int data = q.front();
//				q.pop();

//				if (board[idx][i] == 0)
//					board[idx][i] = data;
//				else if (board[idx][i] == data)
//				{
//					board[idx][i] *= 2;
//					idx++;
//				}
//				else
//				{
//					idx++;
//					board[idx][i] = data;
//				}
//			}
//		}
//		break;
//	case 3://하
//		for (int i = 0; i < n; i++)
//		for (int j = n - 1; j >= 0; j--)
//		{
//			if (board[j][i])
//			{
//				q.push(board[j][i]);
//				board[j][i] = 0;
//			}
//			int idx = n - 1;
//			while (!q.empty())
//			{
//				int data = q.front();
//				q.pop();

//				if (board[idx][i] == 0)
//					board[idx][i] = data;
//				else if (board[idx][i] == data)
//				{
//					board[idx][i] *= 2;
//					idx--;
//				}
//				else
//				{
//					idx--;
//					board[idx][i] = data;
//				}
//			}
//		}
//		break;
//	}
//};

//function<int(int)> dfs = [&](int cnt)
//{
//if (cnt == 5)
//{
//for (int i = 0; i < n; i++)
//for (int j = 0; j < n; j++)
//{
//maxValue = max(maxValue, board[i][j]);
//}
//}
//int tmpboard[MAX][MAX];
//for (int i = 0; i < n; i++)
//for (int j = 0; j < n; j++)
//tmpboard[i][j] = board[i][j];
//for (int i = 0; i < 4; i++)
//{
//shift(i);
//dfs(cnt + 1);
//for (int i = 0; i < n; i++)
//for (int j = 0; j < n; j++)
//tmpboard[i][j] = board[i][j];
//}
//};


#include<bits/stdc++.h>

using namespace std;

int board1[21][21];
int board2[21][21];
int n;

void rotate()
{
	int tmp[21][21];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		tmp[i][j] = board2[i][j];

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		board2[i][j] = tmp[n - 1 - j][i];

	//cout << "돌린값" << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		cout << board2[i][j] << " ";
	//	cout << "\n";
	//}
}

void tilt(int dir)
{
	/*cout << "첫 번째 dir" << dir << "\n";
	cout << "\n";*/

	while (dir--)
	{
	/*	cout << "감소 후 dir" << dir << "\n";*/
		rotate();
	}
		for (int i = 0; i < n; i++)
	{
		int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
		int idx = 0; // tilted 배열에서 어디에 삽입해야 하는지를 가리키는 변수
		for (int j = 0; j < n; j++)
		{
			if (board2[i][j] == 0)
				continue;
			if (tilted[idx] == 0) //삽입할 위치가 비어있을 경우
				tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j])//같은 값의 블록을 만날 경우
				tilted[idx++] *= 2;
			else
				tilted[++idx] = board2[i][j];
		}
		for (int j = 0; j < n; j++)
			board2[i][j] = tilted[j];

		/*for (int j = 0; j < n; j++)
			cout << board2[i][j] << " ";
		cout << "\n";
		cout << "\n";*/
	}
}
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board1[i][j];

	int mx = 0;
	for (int tmp = 0; tmp < 1024; tmp++) //5번의 방향을 이동하기에 4^5개의 경우의 수 발생
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board2[i][j] = board1[i][j];
		int brute = tmp;
		/*cout << "brute는  " << brute << '\n';
		cout << "\n";*/
		for (int i = 0; i < 5; i++)
		{
			int dir = brute % 4;
			/*cout << "들어가기전 dir " << dir << '\n';
			cout << "\n";*/
			brute /= 4;
			tilt(dir);
		}
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mx = max(mx, board2[i][j]);
	}
	cout << mx;
}
*/
