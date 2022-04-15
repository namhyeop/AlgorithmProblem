#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        if(st.empty())
            st.push(s[i]);
        else{
            if(st.top() =='(' && s[i] ==')')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    if(st.size())
        answer = false;
    return answer;
}

int main(){
    cout << solution("()()");
    cout << solution("(())()");
    cout << solution(")()(");
    cout << solution("(()(");
}

