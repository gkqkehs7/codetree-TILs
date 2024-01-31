#include <iostream>
#include <queue>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int m;
        cin >> m;

        // 입력받는 부분
        int arr[100000];
        for(int i=0; i<m; i++) cin >> arr[i];

        int mid = arr[0];
        priority_queue<int> min_pq;
        priority_queue<int> max_pq;

        cout << mid << " ";

        // mid 7
        // min 1 2
        // max 4 5 6
        for(int i=1; i<m; i++) {
            if(min_pq.size() < max_pq.size()) {
                if(mid < arr[i]) {
                    min_pq.push(mid);

                    max_pq.push(-arr[i]);

                    mid = -max_pq.top();
                    max_pq.pop();
                } else if(mid >= arr[i]) {
                    min_pq.push(arr[i]);
                } else if(mid == arr[i]) {
                    min_pq.push(arr[i]);
                }
            } else if(min_pq.size() > max_pq.size()) {
                if(mid < arr[i]) {
                    max_pq.push(-arr[i]);
                } else if(mid > arr[i]) {
                    max_pq.push(-mid);

                    min_pq.push(arr[i]);

                    mid = min_pq.top();

                    min_pq.pop();
                } else if(mid == arr[i]) {
                    max_pq.push(-arr[i]);
                }
            } else if(min_pq.size() == max_pq.size()) {
                if(mid < arr[i]) {
                    max_pq.push(-arr[i]);
                } else if(mid >= arr[i]) {
                    min_pq.push(arr[i]);
                }
            }

            if(i % 2 == 0) {
                cout << mid << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}