#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end(), greater());
    sort(B.begin(), B.end(), less());
    for(int i = 0; i < A.size(); i++)
        answer += A[i] * B[i];
    return answer;
}

int main() {
//    cout << solution({1,4,2}, {5,4,4}) <<"\n";
    cout << solution({1,2}, {3,4}) <<"\n";

}

/*
 * 시간 복잡도 계산이 틀린 DFS 문제 풀이
 */

//#include<bits/stdc++.h>
//
//using namespace std;
//bool visited[2][1001];
//
//int col;
//int minValue = INT_MAX;
//vector<int> a, b;
//void DFS(int level, int sum, int count){
//
//    if(count == col){
//        minValue = min(minValue, sum);
//        return ;
//    }
//
//    for(int i = 0; i < col; i++){
//        for(int j = 0; j < col; j++){
//            if(!visited[0][i] && !visited[1][j]){
//                visited[0][i] = true;
//                visited[1][j] = true;
//                DFS(level + 1, sum + (a[i] * b[j]), count + 1);
//                visited[0][i] =false;
//                visited[1][j] = false;
//            }
//        }
//    }
//}
//int solution(vector<int> A, vector<int> B)
//{
//    int answer = INT_MAX;
//    col = A.size();
//    a = A, b = B;
//    string Arr = "";
//
//    DFS(0, 0,0);
//    answer = minValue;
//    return answer;
//}