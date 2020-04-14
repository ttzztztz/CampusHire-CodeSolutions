#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
 
using namespace std;
 
int K, A, X, B, Y;
const int MOD = 1e9+7;
 
long long fastPow(long long a, long long b) {
    long long answer = 1, base = a;
    while (b) {
        if (b & 1) {
            answer *= base;
            answer %= MOD;
        }
 
        base *= base;
        base %= MOD;
        b >>= 1;
    }
    return answer;
}
 
long long inverse(long long i) {
    return fastPow(i, MOD - 2);
}
 
long long jiecheng(int x) {
    long long answer = 1;
    for (int i = 1; i <= x; i++) {
        answer *= i;
        answer %= MOD;
    }
    return answer;
}
 
long long C(int n, int m) {
    long long answer = jiecheng(n) * inverse(jiecheng(m)) % MOD;
    return (answer * inverse(jiecheng(n - m))) % MOD;
}
 
int main() {
    cin >> K >> A >> X >> B >> Y;
    long long answer = 0;
 
    for (int a = 0; a <= X; a++) {
        const int rest = K - a * A;
        if (rest >= 0 && rest % B == 0) {
            const int b = rest / B;
 
            if (b <= Y) {
                long long tmp = (C(X, a) * C(Y, b)) % MOD;
                answer += tmp;
                answer %= MOD;
            }
        }
    }
 
    cout << answer << endl;
    return 0;
}