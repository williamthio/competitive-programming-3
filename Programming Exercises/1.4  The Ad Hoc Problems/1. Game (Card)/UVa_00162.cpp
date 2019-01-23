#include <iostream>
#include <vector>
#include <string>

using namespace std;

void uva_00162() {
    vector<char> one, two, heap, temp;
    int count, n, i;
    string s;
    bool toggle, isFace;
    while (cin >> s, s[0] != '#') {
        toggle = false;
        isFace = false;
        one.clear();
        two.clear();
        heap.clear();
        two.push_back(s[1]);
        for (i = 0; i < 51; i++) {
            cin >> s;
            if (toggle)
                two.push_back(s[1]);
            else
                one.push_back(s[1]);
            toggle = !toggle;
        }
        while (toggle && two.size() > 0 || !toggle && one.size() > 0) {
            //printf("Heap: ");
            //for (auto it = heap.begin(); it != heap.end(); it++)
            //    printf("%c ", *it);
            //printf("\nOne: ");
            //for (auto it = one.begin(); it != one.end(); it++)
            //    printf("%c ", *it);
            //printf("\nTwo: ");
            //for (auto it = two.begin(); it != two.end(); it++)
            //    printf("%c ", *it);
            //printf("\n\n");
            if (toggle) {
                heap.push_back(two.back());
                two.pop_back();
            }
            else {
                heap.push_back(one.back());
                one.pop_back();
            }

            switch (heap.back())
            {
            case 'J':
                isFace = true;
                n = 1;
                count = 0;
                toggle = !toggle;
                break;
            case 'Q':
                isFace = true;
                n = 2;
                count = 0;
                toggle = !toggle;
                break;
            case 'K':
                isFace = true;
                n = 3;
                count = 0;
                toggle = !toggle;
                break;
            case 'A':
                isFace = true;
                n = 4;
                count = 0;
                toggle = !toggle;
                break;
            default:
                if (!isFace)
                    toggle = !toggle;
                else {
                    count++;
                    if (count == n) {
                        temp.clear();
                        for (auto it = heap.rbegin(); it != heap.rend(); it++) {
                            temp.push_back(*it);
                        }
                        heap.clear();
                        if (toggle) {
                            for (auto it = one.begin(); it != one.end(); it++) {
                                temp.push_back(*it);
                            }
                            one = temp;
                        }
                        else {
                            for (auto it = two.begin(); it != two.end(); it++) {
                                temp.push_back(*it);
                            }
                            two = temp;
                        }
                        isFace = false;
                        toggle = !toggle;
                    }
                }
                break;
            }
        }
        int os = one.size();
        int ts = two.size();
        if (os >= ts) {
            printf("1%3d\n", os);
        }
        else {
            printf("2%3d\n", ts);
        }
    }
}
