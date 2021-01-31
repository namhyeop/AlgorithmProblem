#include<iostream>
#include<algorithm>
#define MAX 400

using namespace std;

int board[MAX][2 * MAX];
int pSum[MAX][2 * MAX];

int N;

int getPrefixSum(int i, int j1, int j2)
{
	/*cout << "getprefixsum의 i, j1, j2값은 " << i << " " << j1 << " " << j2 << "입니다";
	cout << "psum값은" <<" ";*/
	cout << pSum[i][j2 + 1] << " " << pSum[i][j1] << "\n";
	return pSum[i][j2 + 1] - pSum[i][j1];
}

bool isValid(int r, int c)
{
	return (r >= 0) && (c >= 0) && (r < N) && (c < 2 * r + 1);
}

void calSum(int &ans, int i, int j)
{
	int sum = 0;
	bool odd = j & 1; // 0은 위에서 아래로, 1은 아래에서 위로
	int r = i;
	int c1 = j;
	int c2 = j;
	//cout << "calsum 내부에서 반복합니다. odd r c1 c2는 " << "\n";
	//cout <<odd << " "<< r << " " << c1 << " " << c2 << "입니다.\n";
	for (int s = 0; isValid(r, c1) && isValid(r, c2); ++s)
	{
	/*	cout << r << " " << c1 << " " << c2 << "는 범위내입니다";*/
		sum += getPrefixSum(r, c1, c2);
		r += (odd ? -1 : 1);
		c1 += (odd ? -2 : 0);
		c2 += (odd ? 0 : 2);

	/*	cout << "변화된 r c1 c2는";
		cout << odd << " " <<r<<" "<< c1 << " " << c2 <<"입니다.\n";
		cout << "sum은: " << sum <<"이고 비교대상값 ans는 "<<ans<<"입니다\n";*/
		ans = max(ans, sum);

	}
}

int solve()
{
	int ret = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * i + 1; j++)
		{/*
			cout << "calSum i는" << i <<"이고"<< "j는 " << j <<"입니다.\n";
			cout << "\n";*/
			calSum(ret, i, j);
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int Testcase = 0;
	do
	{
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * i + 1; ++j)
		{
			cin >> board[i][j];
			pSum[i][j + 1] = board[i][j] + pSum[i][j];
		}
		cout << ++Testcase << ". " << solve() << "\n";
	} while (true);
	
	return 0;
}
