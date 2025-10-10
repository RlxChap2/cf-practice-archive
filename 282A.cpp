#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 0;
    
    while (n--) {
        string op;
        cin >> op;
        if (op.find("++") != string::npos) {
            x++;
        } else {
            x--;
        }
    }
    cout << x << "\n";
    return 0;
}
