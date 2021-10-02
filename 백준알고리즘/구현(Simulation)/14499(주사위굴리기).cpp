/*
객체지향형 코드
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 21;

int board[MAX][MAX];
int height, width, y, x, k;
int moveY[] ={0,0,-1,1};
int moveX[] ={1,-1,0,0};

struct dice
{
    int n, m, k;
    vector<int> dice_arr; //0으로 초기화 되있는지 확인
    pair<int,int> dice_pos;
    vector<vector<int>> board;
    vector<int> cmd;
    dice(int n , int m, int k) : n(n), m(m), k(k), board(n, vector<int>(m)), dice_arr(6), dice_pos({y,x}){}

    void init()
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < k; i++){
            int tmp;
            cin >> tmp;
            cmd.push_back(tmp - 1);
        }
    }

    void checkbottom(int bottom)
    {
        if(!board[dice_pos.first][dice_pos.second])
            board[dice_pos.first][dice_pos.second] = dice_arr[bottom];
        else{
            dice_arr[bottom] = board[dice_pos.first][dice_pos.second];
            board[dice_pos.first][dice_pos.second] = 0;
        }
    }

    void move()
    {
        for(int i = 0 ; i < cmd.size(); i++)
        {
            if(cmd[i] == 0) // 동
            {
                dice_pos.first += moveY[cmd[i]];
                dice_pos.second += moveX[cmd[i]];

                if (dice_pos.first < 0 || dice_pos.first >= n || dice_pos.second < 0 || dice_pos.second >= m)
                {
                    dice_pos.first -= moveY[cmd[i]];
                    dice_pos.second -= moveX[cmd[i]];
                    continue;
                }

                int tmp = dice_arr[5];
                dice_arr[5] = dice_arr[1];
                dice_arr[1] = dice_arr[4];
                dice_arr[4] = dice_arr[3];
                dice_arr[3] = tmp;

                checkbottom(3);
            }
            else if(cmd[i] == 1)// 서
            {
                dice_pos.first += moveY[cmd[i]];
                dice_pos.second += moveX[cmd[i]];

                if (dice_pos.first < 0 || dice_pos.first >= n || dice_pos.second < 0 || dice_pos.second >= m)
                {
                    dice_pos.first -= moveY[cmd[i]];
                    dice_pos.second -= moveX[cmd[i]];
                    continue;
                }

                int tmp = dice_arr[3];
                dice_arr[3] = dice_arr[4];
                dice_arr[4] = dice_arr[1];
                dice_arr[1] = dice_arr[5];
                dice_arr[5] = tmp;

                checkbottom(3);
            }
            else if(cmd[i] == 2)// 남
            {
                dice_pos.first += moveY[cmd[i]];
                dice_pos.second += moveX[cmd[i]];

                if (dice_pos.first < 0 || dice_pos.first >= n || dice_pos.second < 0 || dice_pos.second >= m)
                {
                    dice_pos.first -= moveY[cmd[i]];
                    dice_pos.second -= moveX[cmd[i]];
                    continue;
                }

                int tmp = dice_arr[0];
                dice_arr[0] = dice_arr[1];
                dice_arr[1] = dice_arr[2];
                dice_arr[2] = dice_arr[3];
                dice_arr[3] = tmp;

                checkbottom(3);
            }
            else//북
            {
                dice_pos.first += moveY[cmd[i]];
                dice_pos.second += moveX[cmd[i]];

                if (dice_pos.first < 0 || dice_pos.first >= n || dice_pos.second < 0 || dice_pos.second >= m)
                {
                    dice_pos.first -= moveY[cmd[i]];
                    dice_pos.second -= moveX[cmd[i]];
                    continue;
                }

                int tmp = dice_arr[1];
                dice_arr[1] = dice_arr[0];
                dice_arr[0] = dice_arr[3];
                dice_arr[3] = dice_arr[2];
                dice_arr[2] = tmp;

                checkbottom(3);
            }
//            for(int i= 0; i < 6; i++)
//                cout << dice_arr[i] <<" ";
//            cout <<"\n";

            cout << dice_arr[1] <<"\n";
        }
    }
};

int main(void)
{
    fastio;
    cin >> height >> width >> y >> x >> k;

    dice D(height, width, k);
    D.init();
    D.move();

}
*/

#include<bits/stdc++.h>
#define MAX 22
using namespace std;

int n, m;
int x, y, k;
int board[MAX][MAX];
int dice[6];
vector<int> cmd;

bool valid(int y, int  x)
{
	return  0 <= y && y < n && 0 <= x && x < m;
}

bool operate(int num)
{
	if (num == 1) // 동
	{
		x += 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[0] = tmpdice[3];
			dice[2] = tmpdice[0];
			dice[5] = tmpdice[2];
			dice[3] = tmpdice[5];
		}
		else
		{
			x -= 1;
			return false;
		}
	}
	else if (num == 2)// 서
	{
		x -= 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[3] = tmpdice[0];
			dice[5] = tmpdice[3];
			dice[2] = tmpdice[5];
			dice[0] = tmpdice[2];
		}
		else
		{
			x += 1;
			return false;
		}
	}
	else if (num == 3)// 북
	{
		y -= 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[1] = tmpdice[0];
			dice[5] = tmpdice[1];
			dice[4] = tmpdice[5];
			dice[0] = tmpdice[4];
		}
		else
		{
			y += 1;
			return false;
		}
	}
	else if (num == 4)//남
	{
		y += 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[4] = tmpdice[0];
			dice[0] = tmpdice[1];
			dice[1] = tmpdice[5];
			dice[5] = tmpdice[4];
		}
		else
		{
			y -= 1;
			return false;
		}
	}

	if (board[y][x])
	{
		dice[0] = board[y][x];
		board[y][x] = 0;
	}
	else
		board[y][x] = dice[0];
	
	return true;
}
int main(void)
{
	cin >> n >> m >> y >> x >> k;

	cmd.resize(k);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	for (int i = 0; i < k; i++)
		cin >> cmd[i];

	for (int i = 0; i < k; i++)
	{
		bool flag = operate(cmd[i]);
		if (flag)
		cout << dice[5] << "\n";
	}
}
