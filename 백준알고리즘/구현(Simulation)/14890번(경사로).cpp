#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 100;
int n, l;
int board[MAX][MAX];
bool visited[MAX];
int ret;


int main(void)
{
    fastio;
    cin >> n >> l;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    auto checkRow = [&](int y) -> void{
        int cur = board[y][0];
        for(int i = 0; i < n; i++){
            //값이 다른 경우라면
            if(board[y][i] != cur){
                //경사로의 높이가 1이 아니라면
                if(!(abs(board[y][i] - cur) <= 1))
                    return ;
                //내리막길일 경우
                if(board[y][i] < cur){
                    int height = -1;
                    //아직 방문하지 않은 곳이고 내리막길을 만들려는 범위가 n을 초과하지 않는다면
                    for(int j = i; j < i + l; j++){
                        if(!visited[j] && j < n){
                            visited[j] = true;
                            //L길이만큼 같은 높이기가 아니라면 조건 충족 X
                            if (height == -1){
                                height = board[y][j];
                                continue;
                            }
                            if(height != -1 && board[y][j] != height)
                                return;
                        }
                        else
                            return;
                    }
                    //내리막길을 설치한 경로만큼 탐색 인덱스 증가
                    i += l - 1;
                    //초과할 경우 탐색 종료
                    if(i >= n)
                        break;
                }
                else{
                    int height = -1;
                    for (int j = i - 1; j > i - 1 - l; j--){
                        if(!visited[j] && j >= 0)
                        {
                            visited[j] = true;
                            if(height == - 1)
                            {
                                height = board[y][j];
                                continue;
                            }
                            if (height != -1 && board[y][j] != height)
                                return;
                        }
                        else
                            return;
                    }
                }
                cur = board[y][i];
            }
        }
        ret++;
    };

    auto checkCol = [&](int x) -> void {
        int cur = board[0][x];
        for(int i = 0; i < n; i++){
            if(board[i][x] != cur){
                if(!(abs(board[i][x] - cur) <= 1))
                    return;
                if(board[i][x] < cur){
                    int height = -1;
                    for(int j = i; j < i + l; j++){
                        if(!visited[j] && j < n){
                            visited[j] = true;
                            if(height == - 1){
                                height = board[j][x];
                                continue;
                            }
                            if(height != -1 && board[j][x] != height){
                                return;
                            }
                        }
                        else
                            return;
                    }
                    i += l - 1;
                    if(i >= n)
                        break;
                }
                else{
                    int height = -1;
                    for(int j = i - 1; j > i - 1 - l; j--){
                        if(!visited[j] && j >= 0){
                            visited[j] = true;
                            if(height == -1){
                                height = board[j][x];
                                continue;
                            }
                            if(height != - 1 && board[j][x] != height)
                                return;
                        }
                        else
                            return;
                    }
                }
                cur = board[i][x];
            }
        }
        ret++;
    };

    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof visited);
        checkRow(i);
    }
    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof visited);
        checkCol(i);
    }
    cout << ret << "\n";
}

/*
#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;
int N, L;
int result;
int arr[MAX][MAX];
bool visited[MAX];

void checkRow(int y)
{
	int cur = arr[y][0];
	for (int i = 0; i < N; i++)
	{
		if (arr[y][i] != cur)
		{
			if (!(abs(arr[y][i] - cur) <= 1))
				return;

			if (arr[y][i] < cur)
			{
				int height = -1;
				for (int j = i; j < i + L; j++)
				{
					if (!visited[j] && j < N)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[y][j];
							continue;
						}
						//L 길이만큼 같은 높이가 아니라면 조건 충족 X
						if (height != -1 && arr[y][j] != height)
							return;
					}
					else
						return;
				}
				i += L - 1;
				if (i >= N)
					break;
			}
			//오르막길
			else
			{
				int height = -1;
				for (int j = i - 1; j > i - 1 - L; j--)
				{
					if (!visited[j] && j >= 0)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[y][j];
							continue;
						}
						if (height != -1 && arr[y][j] != height)
							return;
					}
					else
						return;
				}
			}

			cur = arr[y][i];
		}
	}
	result++;
}

void checkCol(int x)
{
	int cur = arr[0][x];
	for (int i = 0; i < N; i++)
	{
		if (arr[i][x] != cur)
		{
			if (!(abs(arr[i][x] - cur) <= 1))
				return;

			if (arr[i][x] < cur)
			{
				int height = -1;
				for (int j = i; j < i + L; j++)
				{
					if (!visited[j] && j < N)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[j][x];
							continue;
						}

						if (height != -1 && arr[j][x] != height)
							return;
					}
					else
						return;
				}
				i += L - 1;
				if (i >= N)
					break;
			}
			else
			{
				int height = -1;
				for (int j = i - 1; j > i - 1 - L; j--)
				{
					if (!visited[j] && j >= 0)
					{
						visited[j] = true;
						if (height == -1)
						{
							height = arr[j][x];
							continue;
						}
						if (height != -1 && arr[j][x] != height)
							return;
					}
					else
						return;
				}
			}
			cur = arr[i][x];
		}
	}
	result++;
}
int main(void)
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> arr[i][j];

	for (int i = 0; i < N; i++)
	{
		memset(visited, false, sizeof(visited));
		checkRow(i);
	}

	for (int i = 0; i < N; i++)
	{
		memset(visited, false, sizeof(visited));
		checkCol(i);
	}

	cout << result << "\n";
	return 0;
}
*/
