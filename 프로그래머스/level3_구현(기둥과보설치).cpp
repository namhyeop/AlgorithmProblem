#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 101;

bool pilarBoard[MAX][MAX];
bool bowBoard[MAX][MAX];
int N;

//a == (0은 기둥, 1은 보)
//b == (0은 삭제, 1은 설치)
//기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
//보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
//

bool cmp(vector<int> a, vector<int> b) //정렬하는 함수
{
	if (a[0] != b[0])
		return a[0] < b[0];
	else if (a[0] == b[0])
		return a[1] < b[1];
}

vector<int> parsingData(vector<int> &v)
{
	int y = v[1];
	int x = v[0];
	int type = v[2];

	vector<int> tmp;

	tmp = { x, y, type };

	return tmp;
}

bool validPlusPilar(vector<int> build_frame)
{
	int frameY = build_frame[1];
	int frameX = build_frame[0];

	if (frameY == 0)
	{
		pilarBoard[frameY][frameX] = true;
		return true;
	}

	if (bowBoard[frameY][frameX])
	{
		pilarBoard[frameY][frameX] = true;
		return true;
	}

	if (pilarBoard[frameY - 1][frameX])
	{
		pilarBoard[frameY][frameX] = true;
		return true;
	}

	return false;
}

bool validPlusBow(vector<int> build_frame)
{
	int frameY = build_frame[1];
	int frameX = build_frame[0];

	if (pilarBoard[frameY - 1][frameX]) //기둥이 밑에 있는 경우
	{
		bowBoard[frameY][frameX] = true;
		bowBoard[frameY][frameX + 1] = true;
		return true;
	}
	
	if (bowBoard[frameY][frameX - 1] || bowBoard[frameY][frameX + 1])
	{
		bowBoard[frameY][frameX] = true;
		bowBoard[frameY][frameX + 1] = true;
		return true;
	}
	
	return false;
}

bool validSubPilar(vector<int> build_frame)
{
	int frameY = build_frame[1];
	int frameX = build_frame[0];

	if (!bowBoard[frameY + 1][frameX] && !bowBoard[frameY][frameX])
		return true;

	return false;
}
bool validSubBow(vector<int> build_frame)
{
	int frameY = build_frame[1];
	int frameX = build_frame[0];

	bool flag1 = true, flag2 = true;

	int i = 1;
	while (bowBoard[frameY][frameX + i] && frameX + i <= N)
	{
		if (bowBoard[frameY][frameX + i] && pilarBoard[frameY -1][frameX + i])
		{
			flag2 = false;
			break;
		}
		i++;
	}

	i = 1;
	while(bowBoard[frameY][frameX - i] && frameX - i >= 0)
	{
		if (bowBoard[frameY][frameX - i] && pilarBoard[frameY-1][frameX - i])
		{
			flag2 = false;
			break;
		}
		i++;
	}

	if (flag1 && flag2)
		return false;

	return true;
}

void delElement(vector<vector<int>> &answer, vector<int> b) //삭제한거 체크 추가해야함
{
	int infoY = b[1];
	int infoX = b[0];
	int type = b[2];

	vector<vector<int>> ::iterator iter;
	
	for (iter = answer.begin(); iter != answer.end(); iter++)
	{
		vector<int> cur = *iter;

		if (cur[0] == infoX && cur[1] == infoY && cur[2] == type)
		{
			answer.erase(iter);
			if (type == 0)
			{
				pilarBoard[infoY][infoX] = false;
			}
			else if (type == 1)
			{
				bowBoard[infoY][infoX] = false;
				bowBoard[infoY][infoX + 1] = false;
			}
		}
	}
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
	vector<vector<int>> answer;
	N = n;

	int num = build_frame.size();
	for (int i = 0; i < num; i++)
	{
		vector<int> tmp;
		if (build_frame[i][2] == 0) //기둥이 0인경우
		{
			if (build_frame[i][3] == 1)//기둥 추가
			{
				if (validPlusPilar(build_frame[i]))
				{
					tmp = parsingData(build_frame[i]);
					answer.push_back(tmp);
				}
			}
			else if(build_frame[i][3] == 0)//기둥 삭제
			{
				if (validSubPilar(build_frame[i]))
				{
					delElement(answer, build_frame[i]);
				}
			}
		}
		else if (build_frame[i][2] == 1)
		{
			if (build_frame[i][3] == 1) //보 추가
			{
				if (validPlusBow(build_frame[i]))
				{
					tmp = parsingData(build_frame[i]);
					answer.push_back(tmp);
				}
			}
			else if (build_frame[i][3] == 0) // 보 삭제
			{
				if (validSubBow(build_frame[i]))
				{
					delElement(answer, build_frame[i]);
				}
			}
		}
	}

	sort(answer.begin(), answer.end(), cmp);
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 5;
	vector<vector<int>> v = { { 1, 0, 0, 1 }, { 1, 1, 1, 1 }, { 2, 1, 0, 1 }, { 2, 2, 1, 1 }, { 5, 0, 0, 1 }, { 5, 1, 0, 1 }, { 4, 2, 1, 1 }, { 3, 2, 1, 1 } };
	
	vector<vector<int>> ret = solution(n, v);
	
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
}
