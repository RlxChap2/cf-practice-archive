#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<char> numbers;

    for (char c : s) {
        if (c != '+')
            numbers.push_back(c);
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i != numbers.size() - 1)
            cout << "+";
    }

    return 0;
}
