#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;
 
int N;
int main() {
    cin >> N;
 
    vector<int> all;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        all.push_back(tmp);
    }
 
    long long answer = 0;
    for (int i = N - 1; i >= 0; i--) {
        answer = ceil((answer + all[i]) / 2.0);
    }
    cout << answer << endl;
    return 0;
}