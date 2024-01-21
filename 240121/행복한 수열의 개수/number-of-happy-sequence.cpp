#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int map[101][101];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;

    // 행마다 탐색
    for(int i=0; i<n; i++) {
        int prev = map[i][0];
        int duplicate = 1;
        int max_duplicate = 0;

        for(int j=1; j<n; j++) {
           int now = map[i][j];

           if(prev == now) {
            duplicate++;
           } else {
            prev = now;
            max_duplicate = max(duplicate, max_duplicate);
            duplicate = 1;
           }
        }

        max_duplicate = max(duplicate, max_duplicate);
    
        if(max_duplicate >= m) answer++;
    }

    // 열마다 탐색
    for(int i=0; i<n; i++) {
        int prev = map[0][i];
        int duplicate = 1;
        int max_duplicate = 0;

        for(int j=1; j<n; j++) {
           int now = map[j][i];

           if(prev == now) {
            duplicate++;
           } else {
            prev = now;
            max_duplicate = max(duplicate, max_duplicate);
            duplicate = 1;
           }
        }

        max_duplicate = max(duplicate, max_duplicate);

        if(max_duplicate >= m) answer++;
    }

    cout << answer;
    return 0;
}