#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }

    return result + 1;  // convert to 1-based index
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << "Safe position: " << josephus(n, k);

    return 0;
}