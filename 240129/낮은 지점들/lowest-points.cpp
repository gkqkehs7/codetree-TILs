#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> hash;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        if(hash.find(x) != hash.end()) {
            int origin_y = hash.find(x)->second;

            cout << "find!\n";

            if(y < origin_y) {
                hash.erase(x);
                hash.insert(make_pair(x, y));
            }
        } else {
            hash.insert(make_pair(x, y));
        }
    }

    long long answer = 0;

    for(auto elem : hash){
       //  cout<<"key : "<<elem.first<<" value : "<<elem.second<<endl;
        answer += elem.second;
    }

    cout << answer;
}