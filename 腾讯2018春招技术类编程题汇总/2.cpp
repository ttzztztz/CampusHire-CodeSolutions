#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    multiset<long long> all;
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        all.insert(tmp);
    }
 
    long long first = 0;
    int current = 0;
    while (!all.empty()) {
        long long number = *all.rbegin();
        all.erase(--all.end());
        if (current == 0) first += number;
        else first -= number;
 
        current ^= 1;
    }
    cout << first << endl;
    return 0;
}