#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;

    int arr1[100000];
    int arr2[100000];

    for(int i=0; i<n; i++) cin >> arr1[i];

    for(int i=0; i<m; i++) cin >> arr2[i];

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    // 1 2 3 5 6 7
    // 1 2 3 4

    priority_queue<tuple<int, int, int>> pq;

    for(int i = 0; i < n; i++) {
        pq.push(make_tuple(-(arr1[i] + arr2[0]), i, 0));
    }

    for(int i = 0; i < k - 1; i++) {
        int idx1, idx2;
        tie(ignore, idx1, idx2) = pq.top();
        pq.pop();

        // 만약 첫 번째 수열의 idx1번째 원소와 더 매칭할 두 번째 수열의 원소가 남아있다면
        // 우선순위 큐에 넣어줍니다.
        idx2++;
        if(idx2 < m)
            pq.push(make_tuple(-(arr1[idx1] + arr2[idx2]), idx1, idx2));
    }

    int pair_sum;
    tie(pair_sum, ignore, ignore) = pq.top();

    cout << -pair_sum;
    return 0;
}