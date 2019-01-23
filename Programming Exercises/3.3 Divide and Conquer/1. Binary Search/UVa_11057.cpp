#include <iostream>
#include <algorithm>

using namespace std;

void uva_11057() {
    int n;
    while (cin >> n, !cin.fail()) {
        int books[10000];
        for (int i = 0; i < n; i++)
            cin >> books[i];

        sort(books, books + n);

        int money;
        cin >> money;

        int i, j;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int sum = books[left] + books[right];
            if (sum == money) {
                i = left;
                j = right;
                left++;
            }

            if (sum < money)
                left++;
            else
                right--;
        }

        cout << "Peter should buy books whose prices are " << books[i] << " and " << books[j] << ".\n\n";
    }
}
