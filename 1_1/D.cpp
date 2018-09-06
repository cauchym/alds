#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 200000;

int main() {
    int R[MAX], n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }

    int maxdiff = -1000000000;
	int mini = R[0];

	for (int i = 1; i < n; i++) {
        maxdiff = max(maxdiff, R[i] - mini);
        mini = min(mini, R[i]);
    }

    cout << maxdiff << endl;

    return 0;
}
