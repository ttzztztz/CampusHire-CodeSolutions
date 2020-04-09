#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int main() {
    vector<string> stk;
    string tmp;
    while (cin >> tmp) {
        if (tmp == "true" || tmp == "false") {
            if (!stk.empty() && (stk.back() == "false" || stk.back() == "true")) {
                cout << "error" << endl;
                exit(0);
            }
 
            if (!stk.empty() && stk.back() == "and") {
                stk.pop_back();
                bool b1 = stk.back() == "true";
                stk.pop_back();
                bool b2 = tmp == "true";
 
                stk.push_back(b1 && b2 ? "true" : "false");
            } else {
                stk.push_back(tmp);
            }
        } else if (tmp == "and") {
            if (stk.empty()) {
                cout << "error" << endl;
                exit(0);
            }
            if (stk.back() == "and" || stk.back() == "or") {
                cout << "error" << endl;
                exit(0);
            }
 
            stk.push_back(tmp);
        } else if (tmp == "or") {
            if (stk.empty()) {
                cout << "error" << endl;
                exit(0);
            }
            if (stk.back() == "and" || stk.back() == "or") {
                cout << "error" << endl;
                exit(0);
            }
 
            stk.push_back(tmp);
        }
    }
 
    if (stk.back() == "and" || stk.back() == "or") {
        cout << "error" << endl;
        exit(0);
    }
     
    for (const string& str : stk) {
        if (str == "true") {
            cout << "true" << endl;
            exit(0);
        }
    }
    cout << "false" << endl;
    return 0;
}