#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
 
using namespace std;
 
int main() {
    unsigned int a, b;
    cin >> a >> b;
    if (b <= 0 || b > 1024) {
        cout << -1 << endl;
        exit(0);
    }
     
    if (a == b) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}