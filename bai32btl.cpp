#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> openBrackets;
    vector<pair<int, int>> result;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            openBrackets.push(i + 1);
        } else if (s[i] == ')') {
            if (!openBrackets.empty()) {
                int openIndex = openBrackets.top();
                openBrackets.pop();
                result.emplace_back(openIndex, i + 1);
            }
        }
    }

    for (const auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
