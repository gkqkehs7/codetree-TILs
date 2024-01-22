#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check(vector<vector<int>> v, int x, int y, int x_end, int y_end) {
    for(int i=x; i<=x_end ; i++) {
        for(int j=y; j<=y_end; j++) {
            if(v[i][j] < 0) {
                return -1;
            }
        }
    }

    return (x_end - x + 1) * (y_end - y + 1);
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        map.push_back(temp);
    }

    int answer = -1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=i; k<n; k++) {
                for(int p=j; p<m; p++) {
                    int now = check(map, i, j, k, p);
                    answer = max(answer, now);
                }
            }
        }
    }

    cout << answer;


    return 0;
}