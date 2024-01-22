#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int start(vector<vector<int>> v, int x, int y, int direction) {

    int depth = 1;

    while(x < n && y < n && x >= 0 && y >= 0) {
        // direction 0 1 2 3 우 하 좌 상
        if(v[x][y] == 1) {
            // 1일떄 0 -> 3 1 -> 2 2 -> 1 3 -> 0
            if(direction == 0) {
                direction = 3;
            } else if(direction == 1) {
                direction = 2;
            } else if(direction == 2) {
                direction = 1;
            } else if(direction == 3) {
                direction = 0;
            }
        } else if(v[x][y] == 2) {
            if(direction == 0) {
                direction = 1;
            } else if(direction == 1) {
                direction = 0;
            } else if(direction == 2) {
                direction = 3;
            } else if(direction == 3) {
                direction = 2;
            }
        }

        x = x + dx[direction];
        y = y + dy[direction];
        depth++;
    }

    return depth;
}

int main() {
    cin >> n;

    vector<vector<int>> map;
    int answer = 0;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        map.push_back(temp);
    }

    for(int i=0; i<n; i++) {
        answer = max(answer, start(map, 0, i, 1)); // 위에서 진입
        answer = max(answer, start(map, i, n - 1, 2)); // 오른쪽에서 진입
        answer = max(answer, start(map, n - 1, i, 3)); // 아래에서 진입
        answer = max(answer, start(map, i, 0, 0)); // 왼쪽에서 진입
    }

    cout << answer;
    return 0;
}