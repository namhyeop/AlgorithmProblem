#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int ay = arr1.size();
    int ax = arr1[0].size();
    int by = arr2.size();
    int bx = arr2[0].size();


    for(int i = 0; i < ay; i++){
        vector<int> arr;
        for(int j = 0; j < bx; j++){
            int value = 0;
            for(int k = 0; k < ax; k++){
                value += arr1[i][k] * arr2[k][j];
            }
            arr.push_back(value);
        }
        answer.push_back(arr);
    }

    return answer;
}