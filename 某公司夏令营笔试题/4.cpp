#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    TreeNode *left, *right, *memo;
    int id = -1;
    char val;
    TreeNode() : left(nullptr), right(nullptr), val(0), memo(nullptr) {};
};

bool isSymbol(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

unordered_map<string, TreeNode*> memo;
int id = 1, stridx = 0;

pair<TreeNode*, string> build(const string& str) {
    if (stridx == str.size()) {
        return {nullptr, ""};
    }

    if (str[stridx] == '(' || str[stridx] == ')' || str[stridx] == ',') {
        TreeNode* u;
        string x = string{str[stridx]};
        string buffer;

        stridx++;
        tie(u, buffer) = build(str);
        return {u, x + buffer};
    }

    TreeNode* u = new TreeNode();
    u->id = id++;
    u->val = str[stridx];
    string expr = {str[stridx]};
    const bool iss = isSymbol(str[stridx]);
    stridx++;

    if (iss) {
        string exprl, exprr;
        tie(u->left, exprl) = build(str);
        tie(u->right, exprr) = build(str);
        expr += "(" + exprl + "," + exprr + ")";
    }

    if (memo.count(expr)) {
        u->memo = memo[expr];
    } else {
        memo[expr] = u;
    }
    return {u, expr};
}

void reid(TreeNode* u) {
    if (u == nullptr) return;

    if (!u->memo) u->id = id++;
    if (u->left) reid(u->left);
    if (u->right) reid(u->right);
}

string traverse(TreeNode* u) {
    if (u == nullptr) return "";
    if (u->memo != nullptr) {
        return to_string(u->memo->id);
    }

    string answer = {u->val};
    if (isSymbol(u->val)) {
        answer += "(" + traverse(u->left) + "," + traverse(u->right) + ")";
    }
    return move(answer);
}

int main() {
//    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string exp;
        cin >> exp;

        id = 1;
        stridx = 0;
        memo.clear();

        TreeNode* root = build(exp).first;

        id = 1;
        reid(root);
        cout << traverse(root) << endl;
    }
    return 0;
}