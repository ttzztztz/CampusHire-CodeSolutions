#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int N;
    long long M;
    cin >> N >> M;
    vector<int> allPeople;
    for (int i = 1; i <= N; i++) allPeople.push_back(i);
 
    long long ptr = 0, current = M;
    for (int i = 0; i < N - 1; i++) {
        const long long out = (ptr + current - 1) % allPeople.size();
        allPeople.erase(allPeople.begin() + out);
        ptr = out;
        current *= M;
    }
 
    cout << allPeople.front() << endl;
    return 0;
}