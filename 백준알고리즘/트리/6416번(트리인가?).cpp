#include<bits/stdc++.h>

using namespace std;

set<int> s;
int ret;
int node1, node2;

int main(void)
{
	bool flag = true; //테스트 케이스의 종료 구분 flag
	int cnt = 0;

	while (1)
	{
		cnt++;
		s.clear();
		
		ret = 0;
		flag = true;

		bool firstExceptFlag = true; //트리가 비어있는 경우의 예외처리 flag
		while (1)
		{
			cin >> node1 >> node2;
			
			if (firstExceptFlag == true)
			{
				if (node1 == -1 && node2 == -1)
					return 0;
				else if (node1 == 0 && node2 == 0)
				{
					cout << "Case " << cnt << " is a tree." << "\n";
					flag = false;
					break;
				}
			}
			firstExceptFlag = false;

			if (node1 == 0 && node2 == 0)
				break;
			s.insert(node1);
			s.insert(node2);
			ret++;
		}
		//edge + 1 == node의 수, 경로가 유일하지 않고 사이클이 생기는 등의 경우는 트리가 아니다  
		if (flag == true) 
		{
			if (ret + 1 == s.size())
				cout << "Case " << cnt << " is a tree." << "\n";
			else
				cout << "Case " << cnt << " is not a tree." << "\n";
		}
	}
	return 0;
}
