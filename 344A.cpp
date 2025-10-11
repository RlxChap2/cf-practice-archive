#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string prev, cur;
    int groups = 0;

    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (i == 0) {
            groups = 1;
        } else {
            if (cur != prev) {
                groups++;
            }
        }
        prev = cur;
    }

    cout << groups << endl;
    return 0;
}