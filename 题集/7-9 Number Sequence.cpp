#include <iostream>
#include <map>

using namespace std;

int main() {
    int A, B, n;
    while (cin >> A >> B >> n && (A || B || n)) {
        if (n == 1 || n == 2) {
            cout << 1 << endl;
            continue;

        }
        int front = 1, back = 1;
        int fn = 0;
        int i = 3;
        //pair<font,back>->i
        map<pair<int, int>, int> loop;
        loop[{front, back}] = i - 1;
        while (1) {
            fn = (A * back + B * front) % 7;
            front = back;
            back = fn;
            if (loop.find({front, back}) != loop.end()) {
                int cycle_start = loop[{front, back}];
                int cycle_length = i - cycle_start;
                int pos = (n - cycle_start) % cycle_length + cycle_start;
                //重新计算{front,back}到pos
                front = back = 1;
                for (int j = 3; j <= pos; j++) {
                    fn = (A * back + B * front) % 7;
                    front = back;
                    back = fn;
                }
                cout << fn << endl;
                break;
            } else {
                loop[{front, back}] = i;
            }
            i++;
        }
    }

    return 0;
}