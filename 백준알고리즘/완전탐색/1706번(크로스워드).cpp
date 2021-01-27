#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 20
using namespace std;

int height;
int width;
int visited[MAX][MAX];
string board[MAX];
vector<string> word;

/*
1.입력값을 입력한 board배열의 행을 전부 탐색한다.(cnt >= 2 이상인 경우에만)
2.입력값을 입력한 board배열의 열을 전부 탐색한다.(cnt >= 2 이상인 경우에만)
3.탐색한 값들이 들어있는 word를 정렬시켜준뒤 첫 번째 값을 반환해준다.
*/

void search_width()
{
	for (int i = 0; i < height; i++)
	{
		int cnt = 0;
		string tmp = "";
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == '#')
			{
				if (cnt >= 2)
				{
					word.push_back(tmp);
					tmp = "";
					cnt = 0;
					continue;
				}
				else
				{
					tmp = "";
					cnt = 0;
					continue;
				}
			}
			tmp += board[i][j];
			cnt++;
		}
		if (cnt >= 2)
			word.push_back(tmp);
	}
}

void search_height()
{
	for (int i = 0; i < width; i++)
	{
		int cnt = 0;
		string tmp = "";
		for (int j = 0; j < height; j++)
		{
			if (board[j][i] == '#')
			{
				if (cnt >= 2)
				{
					word.push_back(tmp);
					tmp = "";
					cnt = 0;
					continue;
				}
				else
				{
					tmp = "";
					cnt = 0;
					continue;
				}
			}
			tmp += board[j][i];
			cnt++;
		}
		if (cnt >= 2)
			word.push_back(tmp);
	}
}

int main(int argc, char *argv[])
{
	cin >> height >> width;

	//입력값 보드 배열 작성
	for (int i = 0; i < height; i++)
		cin >> board[i];
	
	//행 탐색
	search_width();
	//열 탐색
	search_height();

	sort(word.begin(), word.end());

	cout << word[0] << "\n";

	return 0;
}
