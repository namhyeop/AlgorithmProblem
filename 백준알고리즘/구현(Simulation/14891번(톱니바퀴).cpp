#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()
using namespace std;
int board[4][8];
int way[2] = {-1, 1};
int main(void)
{
    fastio;
    string str;
    for(int i = 0; i < 4; i++)
    {
        cin >> str;
        for(int j = 0; j < 8; j++)
            board[i][j] = str[j] - '0';
    }
    auto tobin_rotate = [&](int rotateWay[4]) -> void {
        //시계 방향일 경우의 회전
        for(int k = 0; k < 4; k++){
            if(rotateWay[k] == 1){
                int tmp = board[k][7];
                for(int i = 7; i >= 1; i--)
                    board[k][i] = board[k][i - 1];
                board[k][0] = tmp;
            }
            //반 시계 방향일 경우 회전
            else if(rotateWay[k] == -1)
            {
                int tmp = board[k][0];
                for(int i = 0; i < 7; i++)
                    board[k][i] = board[k][i + 1];
                board[k][7] = tmp;
            }
        }
    };
    auto operate = [&](int tobin, int dir){
        //전환할 톱니바퀴의 방향을 기억하는 배열
        int rotateWay[4] = {0,0,0,0};
        rotateWay[tobin] = dir;
        queue<pair<int,int>> q;
        int cur = tobin;
        for (int i = 0; i < 2; i++){
            if(tobin + way[i] >= 0 && tobin + way[i] < 4)
                q.push({cur, tobin + way[i]});
        }
        //BFS탐색을 통한 이동되는 톱니바퀴 탐색과 방향 지정
        while(!q.empty())
        {
            int start = q.front().first;
            int end = q.front().second;
            q.pop();

            int small = start < end ? start : end;
            int big = start < end ? end : start;

            //현재 톱니바퀴와 인접하는 톱니바퀴의 방향이 같을 경우 움직이지 않으므로 continue
            if(board[small][2] == board[big][6])
                continue;
            //인접해 있는 톱니바퀴는 현재 회전되는 톱니바퀴의 반대방향으로 회전
            rotateWay[end] = -(rotateWay[start]);
            for(int i = 0; i< 2; i++){
                int next = end + way[i];
                if(next >= 0 && next < 4 && rotateWay[next] == 0)
                    q.push({end, next});
            }
        }
        //회전하는 방향이 저장된 rotateWay 배열을 이용해 톱니바퀴를 회전시킨다.
        tobin_rotate(rotateWay);
    };
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int tobin, dir;
        cin >> tobin >> dir;
        operate(tobin - 1, dir);
    }
    int ret = 0;
    for(int i = 0; i < 4; i++)
        ret += (board[i][0] == 1) ? pow(2, i) : 0;
    cout << ret<< "\n";
}

/*#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int arr[4][8];
int way[2] = { -1, 1 };

int main(void)
{
	fastio;
	string str;
	for (int i = 0; i < 4; i++)
	{
		cin >> str;
		for (int j = 0; j < 8; j++)
			arr[i][j] = str[j] - '0';
	}

	auto tobin_rotate = [&](int rotateWay[4])
	{
		for (int k = 0; k < 4; k++)
		{
			if (rotateWay[k] == 1)
			{
				int tmp = arr[k][7];
				for (int i = 7; i > 0; i--)
					arr[k][i] = arr[k][i - 1];
				arr[k][0] = tmp;
			}
			else if (rotateWay[k] == -1)
			{
				int tmp = arr[k][0];
				for (int i = 0; i < 7; i++)
					arr[k][i] = arr[k][i + 1];
				arr[k][7] = tmp;
			}
		}
	};

	auto operate = [&](int tobin, int dir)
	{
		int rotateWay[4] = { 0, 0, 0, 0 };
		rotateWay[tobin] = dir;

		queue<pair<int, int>> q;
		int cur = tobin;
		for (int i = 0; i < 2; i++)
		{
			if (tobin + way[i] >= 0 && tobin + way[i] < 4)
				q.push({ cur, tobin + way[i] });
		}

		while (!q.empty())
		{
			int start = q.front().first;
			int end = q.front().second;
			q.pop();

			int small = start < end ? start : end;
			int big = start < end ? end : start;

			if (arr[small][2] == arr[big][6])
				continue;

			rotateWay[end] = -(rotateWay[start]);

			for (int i = 0; i < 2; i++)
			{
				int next = end + way[i];
				if (next >= 0 && next < 4 && rotateWay[next] == 0)
					q.push({ end, next });
			}
		}
		tobin_rotate(rotateWay);
	};

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int tobin, dir;
		cin >> tobin >> dir;
		operate(tobin - 1, dir);
	}

	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		ret += (arr[i][0] == 1) ? pow(2, i) : 0;
	}
	cout << ret << "\n";
}*/
/*
#include<bits/stdc++.h>

using namespace std;
#define TOBIN_NUM 4
#define TIME 8

int tobni[TOBIN_NUM][TIME] = { 0 };
int way[2] = { -1, 1 };
int k;

int print_answer()
{
	int answer = 0;
	for (int i = 0; i < TOBIN_NUM; i++)
		answer += (tobni[i][0] == 1 ? pow(2, i) : 0);
	return answer;
}
void change_tobni_num(int rotate_tobni, int rotate_way)
{
	if (rotate_way == 1)
	{
		int sub = tobni[rotate_tobni][TIME - 1];
		for (int i = TIME - 1; i > 0; i--)
			tobni[rotate_tobni][i] = tobni[rotate_tobni][i - 1];
		tobni[rotate_tobni][0] = sub;
	}
	else if (rotate_way == -1)
	{
		int sub = tobni[rotate_tobni][0];
		for (int i = 1; i < TIME; i++)
		{
			tobni[rotate_tobni][i - 1] = tobni[rotate_tobni][i];
		}
		tobni[rotate_tobni][TIME - 1] = sub;
	}
}

void rotate_tobni(int rotate_tobni, int rotate_way)
{
	int rotateWay[TOBIN_NUM] = { 0, 0, 0, 0 };
	rotateWay[rotate_tobni] = rotate_way;

	queue<pair<int, int>> search_queue;

	int start = rotate_tobni;
	for (int i = 0; i < 2; i++)
	{
		int next = start + way[i];
		if (next >= 0 && next < TOBIN_NUM ) //
			search_queue.push({ start, next });
	}

	while (search_queue.size())
	{
		pair<int, int> move_pair = search_queue.front();
		search_queue.pop();

		int small = (move_pair.first < move_pair.second ? move_pair.first : move_pair.second);
		int big = (move_pair.first < move_pair.second ? move_pair.second : move_pair.first);

		if (tobni[small][2] == tobni[big][6])
			continue;

		rotateWay[move_pair.second] = -(rotateWay[move_pair.first]);

		int start = move_pair.second;
		for (int i = 0; i < 2; i++)
		{
			int next = start + way[i];
			if ((next >= 0) && (next < TOBIN_NUM) && (rotateWay[next] == 0))
				search_queue.push({ start, next });
		}
	}
	for (int i = 0; i < TOBIN_NUM; i++)
		change_tobni_num(i, rotateWay[i]);
}
int main(void)
{
	for (int i = 0; i < TOBIN_NUM; i++)
	for (int j = 0; j < TIME; j++)
		scanf("%1d", &tobni[i][j]);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int tobni_num, rotate_way;
		cin >> tobni_num >> rotate_way;
		 
		rotate_tobni(tobni_num - 1, rotate_way);
	}
	cout << print_answer();

	return 0;
}*/
