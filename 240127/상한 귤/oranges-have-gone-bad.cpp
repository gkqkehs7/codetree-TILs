#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct rots_data {
    int x;
    int y;
    int time;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> map;
    vector<pair<int, int>> rots;
    int answer[100][100] = { -1, };

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            answer[i][j] = -2;
        }
    }

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);

            if(input == 2){
                rots.push_back(make_pair(i, j));
            }

            if(input == 0) {
                answer[i][j] = -1;
            }
        }

        map.push_back(temp);
    }

    queue<rots_data> q;
    int visited[100][100] = { false, };
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1 , 0 };


    for(int i=0; i<rots.size(); i++) {
        answer[rots[i].first][rots[i].second] = 0;
        q.push({ rots[i].first, rots[i].second, 0 });
    }


    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int time = q.front().time;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < n && nx >=0 && ny < n && ny >= 0 && !visited[nx][ny]) {
                if(map[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    answer[nx][ny] = time + 1;
                    q.push({ nx, ny, time + 1});
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

}