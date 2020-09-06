#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(int argc, char *argv[])
{
	string input;
	cin >> input;

	string result;
	stack<char> s;

	for (int i = 0; i < input.length(); i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z')
			result += input[i];
		else
			switch (input[i])
			{
			case '(':
				s.push(input[i]);
				break;
			case '*':
			case '/':
				//*,/가 오면 우선순위가 제일 높으므로 같은 기호들이 있으면 결과값에 더해주고 pop를 실행하고 아니면 push한다.
				while (!s.empty() && (s.top() == '*' || s.top() == '/'))
				{
					result += s.top();
					s.pop();
				}
				s.push(input[i]);
				break;
				//+,-가 오면 우선 순위가 같거나 높은 기호들 전부 결과값에 더해주고 pop시킨다
			case'+':
			case'-':
				while (!s.empty() && (s.top() != '('))
				{
					result += s.top();
					s.pop();
				}
				s.push(input[i]);
				break;
				//괄호를 닫기 대문에 지금까지 쌓아온 s에 들어있는 연산자를 더해주고
			case')':
				while (!s.empty() && s.top() != '(')
				{
					result += s.top();
					s.pop();
				}
				//마지막에 있는 괄호(를 뽑아준다.
				s.pop();
				break;
			}
		}

	//남은 경우 다 출력
	while (!s.empty())
	{
		result += s.top();
		s.pop();
	}

	cout << result << endl;
	return 0;

}


/*실패 코드. 4시간째 수정하다가 그냥 포기함 효율성이 떨어지는거 같다. 진짜 존나 화나고 짜증나는데 병신같은 개강 때문에 시간이 없다.
//하 씨발 진짜 존나  화나나네 병신같은 진짜 이 씨발 진자 너무 화가나 씨발 풀수 있을거 같고 거의 다온거 같은데 씨발 진짜
#include<iostream>
#include<string>
#include<stack>

using namespace std;

void search(string input)
{
	stack<int> ist;
	stack<char> cst;
	stack<char> mathst;

	const string opening = "(";
	const string closing = ")";
	const string math1 = "+*";
	const string math2 = "-/";

	for (int i = 0; i < input.size(); i++)
	{
		if (opening.find(input[i]) != -1)
			cst.push(input[i]);

		else if (closing.find(input[i]) != -1)
		{
			if (!cst.empty())
				cst.pop();
		}
		else if (math1.find(input[i]) != -1 || math2.find(input[i]) != -1)
		{
			if (!cst.empty())
			{
				if (math1.find(input[i]) != -1)
				{
					if ((math1.find(input[i]) > math1.find(mathst.top())) && (math1.find(input[i]) > math2.find(mathst.top())))
						mathst.push(input[i]);
					if ((math1.find(input[i]) < math1.find(mathst.top())) || (math1.find(input[i]) < math2.find(mathst.top())))
					{
						cout << mathst.top();
						mathst.pop();
						mathst.push(input[i]);
					}
					else
						cout << input[i];
				}

				else//math2에 있는 연산자인경우
				{
					if ((math2.find(input[i]) > math1.find(mathst.top())) && (math2.find(input[i]) > math2.find(mathst.top())))
						mathst.push(input[i]);
					if ((math2.find(input[i]) < math1.find(mathst.top())) || (math2.find(input[i]) < math2.find(mathst.top())))
					{
						cout << mathst.top();
						mathst.pop();
						mathst.push(input[i]);
					}
					else
						cout << input[i];
				}
			}
			else
			{
				while (!mathst.empty())
				{
					cout << mathst.top();
					mathst.pop();
				}
				mathst.push(input[i]);
			}
		}
		else
		{
			//if (!cst.empty())
				cout << input[i];
		}
	}
	while (!mathst.empty())
	{
		cout << mathst.top();
		mathst.pop();
	}
}

int main(int argc, char *argv[])
{
	string input;
	cin >> input;
	
	search(input);

	return 0;
}
*/
