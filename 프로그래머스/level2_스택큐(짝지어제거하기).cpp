#include<bits/stdc++.h>

using namespace std;

int solution(string s) {
    stack<char> stack1;

    stack1.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (stack1.empty())
            stack1.push(s[i]);
        else if (stack1.top() == s[i])
            stack1.pop();
        else
            stack1.push(s[i]);
    }
    if (stack1.size())
        return 0;
    else
        return 1;
}

int main() {
    cout << solution("baabaa") << "\n";
    cout << solution("cdcd") << "\n";
}