#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;

    for(int i=0; i<n; i++) {
        string input;
        cin >> input;

        if(m.find(input) != m.end()) {
            m.find(input)->second += 1;
        } else {
            m.insert(make_pair(input, 1));
        }
    }

    for(auto elem: m) {

        cout.precision(4);
        cout << elem.first << " " << ((double) elem.second / (double) n) * 100<< "\n";
    }
}