#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
const int MOD = 99997867;
 
long long fastPow(long long x, long long y) {
    long long answer = 1, base = x;
    while (y) {
        if (y & 1) {
            answer *= base;
            answer %= MOD;
        }
 
        base *= base;
        base %= MOD;
        y >>= 1;
    }
    return answer;
}
 
vector<long long> jiecheng;
void init(int N) {
    jiecheng.push_back(1);
    for (int i = 1; i <= N; i++) {
        long long nxt = *jiecheng.rbegin();
        nxt *= i;
        nxt %= MOD;
        jiecheng.push_back(nxt);
    }
}
 
long long inverse(long long number) {
    return fastPow(number, MOD - 2) % MOD;
}
 
long long C(int n, int m) {
    long long answer = jiecheng[n] * inverse(jiecheng[m]) % MOD;
 
    answer *= inverse(jiecheng[n - m]);
    answer %= MOD;
 
    return answer;
}
 
int main() {
    int N, D;
    cin >> N >> D;
    vector<int> all;
 
    init(N + 5);
 
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        all.push_back(tmp);
    }
 
    long long answer = 0;
    for (int left = 0, right = 0; right < N; right++) {
        while (left < N && all[right] - all[left] > D) left++;
        if (right - left + 1 < 3) continue;
 
        answer += C(right - left + 1, 3);
        answer %= MOD;
        if (right - left >= 3) {
            answer -= C(right - left, 3);
            answer += MOD;
            answer %= MOD;
        }
    }
 
    cout << answer << endl;
    return 0;
}