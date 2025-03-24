#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int sides[3] = {A, B, C};
    sort(sides, sides + 3);
    A = sides[0];
    B = sides[1];
    C = sides[2];

    int operations = 0;
    while (A + B <= C) {
        A++;
        operations++;
    }

    cout << operations << endl;
    return 0;
}
