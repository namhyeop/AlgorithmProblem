#include<bits/stdc++.h>

using namespace std;


int solution(int n, int a, int b) {
    int answer = 0;
    int levelCount = 1;
    vector<int> arr(n + 1);

    /**
     *  문제 조건중 A가 B보다 항상 작다라는 조건이 없습니다.
     *  그러므로 조건을 따로 설정해주어야 합니다.
     */

    if(a > b){
        swap(a, b);
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    while (n != 0) {
        int pos = 1;
        int arg1, arg2;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1)
                arg1 = arr[i];
            else if (i % 2 == 0)
                arg2 = arr[i];

            if(i % 2 == 0){
                if(arg1 == a && arg2 == b){
                    return levelCount;
                }
                else if(arg1 == a){
                    arr[pos++] = arg1;
                }
                else if(arg1 == b){
                    arr[pos++] = arg1;
                }
                else
                    arr[pos++] = arg2;
            }
        }
        n /= 2;
        levelCount++;
    }
    return answer;
}

int main() {
    cout << solution(8, 4, 7) << "\n";
}