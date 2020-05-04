#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    unordered_set<int> fib = {
            1,2,3,5,8,13,21,34,55,89
    };

    string s;
    cin >> s;

    set<string> answer;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            const int len = j - i + 1;
            const string substr = s.substr(i, len);

            unordered_set<char> appear;
            for (const auto& p : substr) appear.insert(p);

            if (fib.count(appear.size())) answer.insert(substr);
        }
    }
    for (const auto& str : answer) cout << str << endl;
    return 0;
}