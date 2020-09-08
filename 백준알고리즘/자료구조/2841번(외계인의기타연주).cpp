#include<iostream>
#include<stack>
using namespace std;
/*
문제를 이해하기 너무 어려운거 같다 기타를 치는 법을 미리 알았더라면 이해하기 더 쉬웠을텐데...
7 15 15는 pret의 최대값을 의미하는데 사실상 문제에서 예외처리 안해도 정답 조건이 되서 구지 신경안써도 괜찮다.
문제는 요놈들의 규칙이다
1번부터 6번줄이 있는데 각 스택(줄안에)안에 있는 pret 값보다 높을 경우 손가락을 움직여 줘야 한다는 것이다.
상상해보면 내가 손으로 기타를 c코드를 잡고 있는데 엄지 손가락이 위로 올라와야 할 때 카운트 해줘야 한다 생각하면 이해하기 더 쉽다.
더 쉽게 말하자면 각 줄안에 있는 값보다 내가 넣을려는 줄의 pret값이 더 높으면 그걸 뽑고 count하고 넣고 count한다 생각하면 된다.
오름차순이 되어야 한다는 말.

1 5 //1번째 줄에 5를 넣는다. 비어 있으므로 넣으면 된다. ret = 1;
2 3 //2번째 줄에 3을 넣는다. 비어 있으므로 넣으면 된다. ret = 2
2 5 //2번째 줄에 5를 넣는다. 비어 있지 않지만 안에 있는 st.top()값보다 내가 넣으려는 pret값이 더 높으므로 넣는다. ret = 3
2 7// 2번째 줄에 7를 넣는다. 비어 있지 않지만 안에 있는 st.top()값보다 내가 넣으려는 pret값이 더 높으므로 넣는다. ret = 4
2 4// 2번째 줄에 4를 넣는다. 비어 있지 않지만 안에 있는 st.top()값보다 내가 넣으려는 pret값이 더 작으므로 7,5를 뽑고 4를 넣는다. ret = 7 
1 5// 1번째 줄에 5를 넣는다. 같으므로 넘어간다, 이미 코드를 잡고 있다는 소리임 ret = 5 
1 3// 1번째 줄에 3을 넣는다. 비어 있지 않지만 안에 있는 st.top()값보다 내가 넣으려는 pret값이 더 작으므로 5를 빼고 3을 넣는다. ret = 9
*/

int main(int argc, char * argv[])
{
	int N;
	int maxpret;
	int ret = 0;
	stack<int> st[7];
	
	//멜로디 줄, pret의 최대값
	cin >> N >> maxpret;
	
	for (int i = 0; i < N; i++)
	{
		int line;
		int pret;
		cin >> line >> pret;
		//비어 있으면 그냥 넣는다.
		if (st[line].empty())
		{
			st[line].push(pret);
			ret++;
		}
		//pret값이 넣으려는 줄 값보다 크면 넣는다.
		else if (pret > st[line].top())
		{
			st[line].push(pret);
			ret++;
		}
		//pret값이 안에 있는 값보다 작다면
		else if (pret < st[line].top())
		{
			//안에 있는 값보다 클 때까지 빼준다
			while (st[line].top() > pret)
			{
				st[line].pop();
				ret++;
				if (st[line].empty())
					break;
			}
			//빼주고나서 값을 넣어준다.
			if (st[line].empty())
			{
				ret++;
				st[line].push(pret);
				continue;
			}
			//같으면 넘어간다.
			if(st[line].top() == pret)
				continue;
			ret++;
			st[line].push(pret);
		}
	}
	cout << ret;

	return 0;
}

