#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, k, u, d;
vector<vector<int>> map;
bool visited_city[10][10] = { false, };
int dx[4] = { 0, 1, 0 ,- 1};
int dy[4] = { 1, 0 , -1, 0 };
int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    int temp = 0;
    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x < n && next_x >= 0 && next_y < n && next_y >= 0 && !visited_city[next_x][next_y]) {
                int hei_diff = abs(map[now_x][now_y] - map[next_x][next_y]);
                if(hei_diff >= u && hei_diff <= d) {
                    q.push(make_pair(next_x, next_y));
                    visited_city[next_x][next_y] = true;
                    temp++;
                }
            }
        }
    }

    return temp;
}

bool visited[10][10] = { false, };
vector<vector<pair<int, int>>> combinations;
void get_combinations(vector<pair<int, int>> v, int k) {
    if(v.size() == k) {
        combinations.push_back(v);
        return;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                v.push_back(make_pair(i , j));
                visited[i][j] = true;

                get_combinations(v, k);

                v.pop_back();
                visited[i][j] = false;
            }
        }
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;

            temp.push_back(input);
        }
        map.push_back(temp);
    }

   
    int answer = 0;
    // 조합 구하기
    vector<pair<int, int>> temp;
    get_combinations(temp, k);

    for(int i=0; i<combinations.size(); i++) {

        int temp = 0;
        for(int j=0; j<combinations[i].size(); j++) {
            int x = combinations[i][j].first;
            int y = combinations[i][j].second;
            temp += bfs(x, y);
        }

        answer = max(answer, temp);

        // 초기화
        for(int p=0; p<10; p++) {
            for(int k=0; k<10; k++) {
                visited_city[p][k] = false;
            }
        }
    }

    cout << answer;

}