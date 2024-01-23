#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int encoding(string s) {
    char prev = s[0];
    int len = 0;
    int same = 1;

    for(int i = 1; i < s.length(); i++) {
        char now = s[i];

        if(prev == now) {
            same += 1;
        } else {
            prev = now;
            len += 2;
            same = 1;
        }
    }

    if(same == 10) {
        return len + 1;
    }

    return len;
}

int main() {
    string s;
    cin >> s;

    int answer = 99999;
    string temp = s;


    for(int i=0; i<s.length(); i++)  {
        temp += s[i];
        temp[i] = ' ';

        answer = min(answer, encoding(temp));
    }


    cout << answer;

}