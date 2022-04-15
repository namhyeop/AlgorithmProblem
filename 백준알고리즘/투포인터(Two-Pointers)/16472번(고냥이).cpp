#include <bits/stdc++.h>

using namespace std;
int alpha[26];
int n, kind;
string s;

void input(){
    cin >> n >> s;
}

void add(char x){
    alpha[x -'a']++;
    if(alpha[x - 'a'] == 1) //1이라는것은 새로운 알파벳을 등장했단는것을 의미하므로 kind++
        kind++;
}

void erase(char x){
    alpha[x - 'a']--;
    if(alpha[x - 'a'] == 0) //0이라는것은 알파벳이 사라졌다는것을 의미하르로 kind--;
        kind--;
}

void pro(){
    int len = s.size(), ans = 0;

    for(int l = 0, r =0; r < len; r++){
        add(s[r]);
        while(kind > n){
            erase(s[l++]);
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
}

int main(){
    input();
    pro();
}