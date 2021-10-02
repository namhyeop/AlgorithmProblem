#include<bits/stdc++.h>

using namespace std;

int n, m;
int board[10][10];
int A[4][21];

bool sol()
{
	int win[4] = {};
	int cnt[4] = {};
	int p1 = 1;
	int p2 = 2;
	int p3 = 3;

	while (1)
	{
		if (cnt[1] > n) //승부 횟수 초과시 실패
			return 0;
		if (win[1] == m) //승리 횟수 달성시 성공
			return 1;
		if (win[2] == m || win[3] == m) //패배일 경우는 실패
			return 0;
		if (p1 > p2) //순서대로 승부 해줘야 하므로
			swap(p1, p2);
		cnt[p1]++;
		cnt[p2]++;
		
		if (board[A[p1][cnt[p1]]][A[p2][cnt[p2]]] == 2) //해석하면 각 의자마다 앉은 사람의, 카운트는 내가 무엇을 내야 할 차례인가? 근데 그게 만약 2라면
		{
			win[p1]++; //p1이 이긴경우
			swap(p2,p3);//다음 상대 데려오기
		}
		else//p1이 지거나 비긴경우. 비긴경우는 뒤에 있는에가 우선이다.
		{
			win[p2]++;
			swap(p1, p3); 
		}
	}
}
int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n ; i++)
	for (int j = 1; j <= n; j++)
		cin >> board[i][j];
	
	for (int i = 1; i <= 20; i++)
		A[1][i] = i;
	for (int i = 1; i <= 20; i++)
		cin >> A[2][i];
	for (int i = 1; i <= 20; i++)
		cin >> A[3][i];

	do
	{
		if (sol())
		{
			cout << 1 << "\n";
			return 0;
		}
	} while (next_permutation(A[1] + 1, A[1] + n + 1));

	cout << 0 << "\n";
}
