#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;
const int MAX = 1e9;

unordered_set<long long> invalid;
void prepare() {
    long long a = 1, b = 1;
    while (b <= MAX) {
        long long lst = a;
        a = b;
        b = a + lst;
        invalid.insert(b);
    }
}

int main() {
    prepare();
    int t;
    cin >> t;
    int answer = 0;
    for (int i = 0; i < t; i++) {
        int cur;
        cin >> cur;
        if (!invalid.count(cur)) answer++;
    }
    cout << answer << endl;
    return 0;
}