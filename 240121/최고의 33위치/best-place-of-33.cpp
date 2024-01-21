#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int map[20][20];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
        }
    }

    int answer = 0;

    for(int i=0; i < n - 2; i++) {
        for(int j=0; j < n - 2; j++) {

            int sum = 0;

            for(int k=i; k < i + 3; k++) {
                for(int p=j; p < j + 3; p++) {
                    sum += map[k][p];
                }
            }

            if(answer < sum) {
                answer = sum;
            }
        }
    }

    cout << answer;
}