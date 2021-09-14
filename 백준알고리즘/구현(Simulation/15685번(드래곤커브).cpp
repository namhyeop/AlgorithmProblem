#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 101;
int n;
int board[MAX][MAX];
int moveY[] = {0, -1, 0, 1};
int moveX[] = {1, 0, -1, 0};

int main(void)
{
    fastio;
    cin >> n;
    for(int i = 0; i< n; i++){
        int x ,y , d, g;
        cin >> x >> y >> d >> g;

        vector<int> dir;
        dir.push_back(d);
        //드래곤 커브의 모든 위치 변환값을 담아준다.
        for(int i = 1; i <= g; i++){
            int len = (int)dir.size() - 1;
            //세대만큼 회전해야 할 방향을 미리 정해준다.
            for(int j  = len; j >= 0; j--)
                dir.push_back((dir[j] + 1) % 4);
        }
        //초기 드래곤 커브 좌표 체크
        board[y][x] = true;
        //드래곤 커브 위치를
        for(int i = 0; i < dir.size(); i++){
            y = y + moveY[dir[i]];
            x = x + moveX[dir[i]];
            board[y][x] = true;
        }
    }

    //1*1 정삭각형을 확인해준다.
    int ret = 0;
    for(int y = 0; y < 100; y++){
        for(int x = 0; x < 100; x++){
            if(board[y][x] && board[y][x + 1] && board[y + 1][x] && board[y + 1][x + 1])
                ret++;
        }
    }
    cout << ret << "\n";
}
/*
#include<bits/stdc++.h>
#define MAX 101
using namespace std;

int n,x,y,d,g;
int moveY[] = { 0, -1, 0, 1 };
int moveX[] = { 1, 0, -1, 0 };

bool board[MAX][MAX];
int main(void)
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;

		vector<int> dir;
		dir.push_back(d);
		for (int i = 1; i <= g; i++)
		{
			int len = (int)dir.size() - 1;
			for (int j = len; j >= 0; j--)
				dir.push_back((dir[j] + 1) % 4);
		}

		board[y][x] = true;

		for (int i = 0; i < dir.size(); i++)
		{
			y = y + moveY[dir[i]];
			x = x + moveX[dir[i]];
			board[y][x] = true;
		}
	}

	int ret = 0;
	for (int i = 0; i < 100; i++)
	for (int j = 0; j < 100; j++)
	{
		if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
			ret++;
	}

	cout << ret << "\n";
}
*/
