#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    vector<bool> isPrime(N + 5, true);
    isPrime[0] = isPrime[1] = false;
 
    for (int i = 2; i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2; i * j <= N; j++) {
            isPrime[i * j] = false;
        }
    }
 
    int answer = 0;
    for (int i = 2; i <= N / 2; i++) {
        if (isPrime[i] && isPrime[N - i]) {
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}