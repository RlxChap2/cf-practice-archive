#include <iostream>
using namespace std;

int main() {

    int watermelon;
    cin >> watermelon;

    if (watermelon > 2 && watermelon % 2 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
