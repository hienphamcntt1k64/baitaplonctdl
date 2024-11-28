#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> stack;

    while (T--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int n;
            cin >> n;
            stack.push_back(n);
        }
        else if (query_type == 2) {
            if (!stack.empty()) {
                stack.pop_back();
            }
        }
        else if (query_type == 3) {
            if (!stack.empty()) {
                cout << stack.back() << endl;
            } else {
                cout << "Empty!" << endl;
            }
        }
    }

    return 0;
}
