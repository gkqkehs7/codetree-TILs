#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#define INT_MAX 999999999
#define MAX_N 100000
using namespace std;

int main() {
    int n;
    cin >> n;

    tuple<int, int, int> people[MAX_N + 1];
    priority_queue<tuple<int, int, int>> pq;


    for(int i=0; i<n; i++) {
        int a, t;
        cin >> a >> t;
        people[i] = make_tuple(a, i + 1, t); 
    }

    people[n] = make_tuple(INT_MAX, n + 1, 0);

    // 정렬을 진행합니다.
    sort(people, people + n + 1);

    // 첫번째 시작하는 사람의 끝나느 시각
    int prev_end = 0;
    int answer = 0;

    for(int i=0; i<=n; i++) {
        int start_time, index, time;

        tie(start_time, index, time) = people[i];

        // 기다려야 되진 않지만 대기큐에 사람들이 있는 경우 (자기보다 앞선 index의 사람들이 있는 경우)
        while(start_time > prev_end && !pq.empty()) {
            int next_start_time, next_time;
            tie(ignore, next_start_time, next_time) = pq.top();
            pq.pop();

            answer = max(answer, prev_end - next_start_time);
            prev_end += next_time;
        }

        // 기다리지 않아도 되는 경우에는 종료 시간을 바로 늘려준다.
        if(start_time > prev_end) {
            prev_end = start_time + time;
        } else { // 기다려야 한다면 대기큐에 넣어준다.
            pq.push(make_tuple(-index, start_time, time));
        }
    }

    cout << answer;

    return 0;
}