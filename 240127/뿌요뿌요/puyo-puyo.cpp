#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visited[101][101] = { false, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, -0 };

int exploded_block = 0;
void dfs(vector<vector<int>> v, int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < n && nx >=0 && ny < n && ny >= 0) {
            if(v[x][y] == v[nx][ny] && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                dfs(v, nx, ny);
                exploded_block++;
            }
        }
    }
}


int main() {

    cin >> n;

    vector<vector<int>> map;

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
    int max_exploded_block = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j] == false) {
                dfs(map, i , j);
                max_exploded_block = max(max_exploded_block, exploded_block);

                if(exploded_block >= 4) {
                    answer++;
                }
                exploded_block = 0;
            }
        }
    }

    cout << answer << " " << max_exploded_block;
}