#include <iostream>
#include <unordered_map>
#include <vector>
#define MAX_N 5000

using namespace std;

int n;
int arr[4][MAX_N];
unordered_map<int,int> freq_first;  // A+B의 수열에서 두 원소의 합
unordered_map<int,int> freq_second; // C+D의 수열에서 두 원소의 합

int main() {

    cin >> n;
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            freq_first[arr[0][i]+arr[1][j]]++;

            freq_second[arr[2][i]+arr[3][j]]++;
        }
    }

    int answer = 0;
    for(auto elem: freq_first){
        int diff = -(elem.first);
        if(freq_second.find(diff) != freq_second.end())
            answer += freq_second[diff]*(elem.second);
    }
    // 출력
    cout << answer << '\n';
    return 0;
}