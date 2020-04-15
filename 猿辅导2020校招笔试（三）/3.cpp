#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> prefix{0};
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        prefix.push_back(tmp + *prefix.rbegin());
    }
 
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(prefix.begin(), prefix.begin() + i + 1, prefix[i] - s);
        answer = max(answer, int(i - (it - prefix.begin())));
    }
    cout << answer << endl;
    return 0;
}