#include <iostream>

using namespace std;

void uva_01260() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        int arr[1000];
        cin >> arr[0];
        
        int sum = 0;
        for (int i = 1; i < n; i++) {
            cin >> arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] <= arr[i])
                    sum++;
            }
        }

        cout << sum << "\n";
    }
}
