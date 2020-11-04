#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int cityweight[10001];
vector<int> villageinfo[10001];
vector<int> villageTree[10001];
int cache[10001][2];
bool Entrance[10001];

int operate(int idx, bool YESorNO)
{
	int &result = cache[idx][YESorNO];

	if (result != -1)
		return result;
	
	result = 0;

	for (int i = 0; i < villageTree[idx].size(); i++)
	{
		int nextidx = villageTree[idx][i];
		int caseFalse = operate(nextidx, false); //선택하지 않았을 경우
		int caseTrue = -1;//밑에 내려가서 선택하지 않을 경우 caseFalse값이 무조건 최대값이 기에 -1설정을 해준다.
		
		if (YESorNO == false)//선택했을 경우
			caseTrue = operate(nextidx, true);

		result += max(caseFalse, caseTrue); // 둘 중 가장 큰 값을 고르겠다.
	}

	if (YESorNO)//이 재귀에서 YESorNO가 참이라면 관련된 노드의 가중치 값을 더한다.
		result += cityweight[idx];

	return result;
}
void createTree(int node)
{
	for (int i = 0; i < villageinfo[node].size(); i++)
	{
		int nextNode = villageinfo[node][i];

		if (Entrance[nextNode] == false) //아직 생성된 경로가 아니라면 트리 생성
		{
			villageTree[node].push_back(nextNode);
			Entrance[nextNode] = true;

			createTree(nextNode);
		}
	}
}
int main(int argc, char * argv[])
{
	int TestNum;
	cin >> TestNum;

	for (int i = 1; i <= TestNum; i++) //사람수 값 받기
	{
		cin >> cityweight[i]; 
	}

	for (int j = 0; j < TestNum - 1; j++) //트리 정보 받기
	{
		int tmp1;
		int tmp2;
		cin >> tmp1 >> tmp2;

		villageinfo[tmp1].push_back(tmp2);
		villageinfo[tmp2].push_back(tmp1);
	}

	Entrance[1] = true; //1번마을부터 시작이므로 1번 루트 체크
	createTree(1);

	memset(cache, -1, sizeof(cache));

	int result = max(operate(1, false), operate(1, true));

	cout << result << '\n';
	
	return 0;
}
