#include <iostream>
#include <bitset>
#include <functional>

using namespace std;

void uva_11926() {
    int n, m;
    while (cin >> n, cin >> m, n || m) {
        bitset<1000001> calendar, twoDaysTasks, checker, range, boundary;

        auto setRange = [&](int start, int end) {
            bitset<1000001> trim;

            range.set();
            trim.set();
            range >>= 1000001 - end - 1;
            trim <<= start;
            range &= trim;

            boundary.reset();
            boundary[start] = 1;
            boundary[end] = 1;
        };

        int start, end, interval;
        bool conflict = false;
        while (n--) {
            cin >> start;
            cin >> end;

            if (conflict)
                continue;

            setRange(start, end);

            if (end - start == 1) {
                if (twoDaysTasks[start] == 1) {
                    conflict = true;
                    continue;
                }
                else {
                    twoDaysTasks[start] = 1;
                }
            }

            bitset<1000001> result = (calendar & range);
            //cout << "Cal: " << calendar.to_string() << "\n";
            //cout << "Chk: " << checker.to_string() << "\n";
            //cout << "Rng: " << range.to_string() << "\n";
            //cout << "Res: " << result.to_string() << "\n";
            if ((checker & range) != 0 || (result & ~boundary) != 0) {
                conflict = true;
                continue;
            }

            calendar |= range;

            range[start] = 0;
            range[end] = 0;
            range |= result;

            checker |= range;
            //cout << "Cal: " << calendar.to_string() << "\n";
            //cout << "Chk: " << checker.to_string() << "\n\n";
        }
        while (m--) {
            cin >> start;
            cin >> end;
            cin >> interval;

            if (conflict)
                continue;

            if (end - start > interval) {
                conflict = true;
                continue;
            }

            setRange(start, end);

            if (end - start == 1) {
                int multiplier = 1;
                bitset<1000001> id;
                id[start] = 1;
                while (interval * multiplier < 1000001) {
                    id |= id << interval * multiplier;
                    multiplier <<= 1;
                }
                if ((twoDaysTasks & id) != 0) {
                    conflict = true;
                    continue;
                }
                else {
                    twoDaysTasks |= id;
                }
            }

            int multiplier = 1;
            bitset<1000001> check = range;
            check[start] = 0;
            check[end] = 0;
            check |= range & (range << interval);
            while (interval * multiplier < 1000001) {
                range |= range << interval * multiplier;
                check |= check << interval * multiplier;
                boundary |= boundary << interval * multiplier;
                multiplier <<= 1;
            }

            bitset<1000001> result = (calendar & range);
            //cout << "Cal: " << calendar.to_string() << "\n";
            //cout << "Chk: " << checker.to_string() << "\n";
            //cout << "Rng: " << range.to_string() << "\n";
            //cout << "Res: " << result.to_string() << "\n";
            if ((checker & range) != 0 || (result & ~boundary) != 0) {
                conflict = true;
                continue;
            }

            calendar |= range;

            check |= result;
            checker |= check;
            //cout << "Cal: " << calendar.to_string() << "\n";
            //cout << "Chk: " << checker.to_string() << "\n\n";
        }
        cout << (!conflict ? "NO " : "") << "CONFLICT\n";
    }
}
