#include <iostream>
#include <string>

using namespace std;

void uva_00637() {
    int pageNum;
    while (cin >> pageNum, pageNum) {
        cout << "Printing order for " << pageNum << " pages:\n";

        if (pageNum == 1) {
            cout << "Sheet 1, front: Blank, 1\n";
            continue;
        }

        int small = 1;
        int big = pageNum + (pageNum % 4 == 0 ? 0 : 4 - pageNum % 4);
        int count = 0;
        int sheetCount = 1;
        while (small < big) {
            cout << "Sheet " << sheetCount << ", ";
            if (count++ % 2 == 0) {
                cout << "front: "
                    << (big > pageNum ? "Blank" : to_string(big))
                    << ", " << small << "\n";
            }
            else {
                cout << "back : " << small << ", "
                    << (big > pageNum ? "Blank" : to_string(big))
                    << "\n";
                sheetCount++;
            }
            small++;
            big--;
        }
    }
}
