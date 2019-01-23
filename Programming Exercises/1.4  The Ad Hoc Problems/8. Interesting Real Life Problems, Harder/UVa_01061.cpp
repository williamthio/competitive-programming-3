#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void uva_01061() {
    unordered_map<string, string> kCombinations({
        {"A", "AO"}, {"AB", "AB"}, {"B", "BO"}, {"O", "O"} });
    unordered_map<string, string> kBloodTypes({
        {"AA", "A"}, {"AB", "AB"}, {"AO", "A"},
        {"BB", "B"}, {"BO", "B"}, {"OO", "O"} });
    unordered_map<string, int> kBloodTypeOrder({
        {"O", 0}, {"AB", 1}, {"B", 2}, {"A", 3},
        {"O-", 0}, {"AB-", 1}, {"B-", 2}, {"A-", 3} });
    vector<string> kBt({ "O", "AB", "B", "A"});

    auto comparator = [&](string s1, string s2) -> bool {
        return kBloodTypeOrder[s1] < kBloodTypeOrder[s2];
    };

    auto getChildBloodTypes = [&](string p1, string p2) -> vector<string> {
        string rh = p1[p1.size() - 1] == '+' 
            || p2[p2.size() - 1] == '+' ? "-+" : "-";
        int rhn = rh.size();
        p1.pop_back();
        p2.pop_back();

        unordered_set<string> uniqueBloodTypes;
        string combinations = kCombinations[p1] + kCombinations[p2];
        int cn = combinations.size();
        for (int i = 0; i < cn - 1; i++) {
            for (int j = i + 1; j < cn; j++) {
                string combination = "";
                combination += combinations[i];
                combination += combinations[j];
                if (combination[0] > combination[1])
                    swap(combination[0], combination[1]);

                if (combination.compare("AB") == 0
                    && (p1.compare("AB") == 0 && p2.compare("O") == 0
                        || p1.compare("O") == 0 && p2.compare("AB") == 0))
                    continue;

                string bloodType = kBloodTypes[combination];
                if (rhn == 1)
                    bloodType += rh;
                uniqueBloodTypes.insert(bloodType);
            }
        }

        vector<string> childBloodTypes(uniqueBloodTypes.begin(),
            uniqueBloodTypes.end());

        if (rhn == 2) {
            int n = childBloodTypes.size();
            for (int i = 0; i < n; i++)
                childBloodTypes.push_back(childBloodTypes[i]);
        }

        sort(childBloodTypes.begin(), childBloodTypes.end(), comparator);

        if (rhn == 2) {
            int n = childBloodTypes.size();
            for (int i = 0; i < n; i++)
                childBloodTypes[i] += rh[i % 2];
        }

        return childBloodTypes;
    };

    auto getParentBloodTypes = [&](string parent, string child) -> vector<string> {
        char parentRh = parent[parent.size() - 1];
        char childRh = child[child.size() - 1];
        string rh;
        if (childRh == '-')
            rh = "-+";
        else if (parentRh == '-')
            rh = "+";
        else
            rh = "-+";
        int rhn = rh.size();

        vector<string> parentBloodTypes;

        parent.pop_back();
        child.pop_back();
        if (parent.compare("AB") == 0 && child.compare("O") == 0
            || parent.compare("O") == 0 && child.compare("AB") == 0) {
            parentBloodTypes.push_back("IMPOSSIBLE");
            return parentBloodTypes;
        }

        bool valid;
        string parentCombination = kCombinations[parent];
        for (int i = 0, btn = kBt.size(); i < btn; i++) {
            string combination = kCombinations[kBt[i]];
            valid = false;
            for (int j = 0, pcn = parentCombination.size(); j < pcn; j++) {
                for (int k = 0, cn = combination.size(); k < cn; k++) {
                    string bt = "";
                    bt += parentCombination[j];
                    bt += combination[k];
                    if (bt[0] > bt[1])
                        swap(bt[0], bt[1]);
                    if (kBloodTypes[bt].compare(child) == 0) {
                        parentBloodTypes.push_back(kBt[i]);
                        valid = true;
                        break;
                    }
                }
                if (valid)
                    break;
            }
        }

        if (rhn == 2) {
            for (int i = 0, n = parentBloodTypes.size(); i < n; i++)
                parentBloodTypes.push_back(parentBloodTypes[i]);
        }

        sort(parentBloodTypes.begin(), parentBloodTypes.end(), comparator);

        for (int i = 0, n = parentBloodTypes.size(); i < n; i++) {
            parentBloodTypes[i] += rh[rhn == 1 ? 0 : i % 2];
        }

        return parentBloodTypes;
    };

    auto printBloodTypes = [&](vector<string> bloodTypes) {
        int btn = bloodTypes.size();
        if (btn != 1)
            cout << "{";
        for (int i = 0, n = bloodTypes.size(); i < n; i++) {
            if (i > 0)
                cout << ", ";
            cout << bloodTypes[i];
        }
        if (btn != 1)
            cout << "}";
    };

    int tc = 0;
    string parent1, parent2, child;
    while (cin.peek() != EOF) {
        cin >> parent1;
        if (parent1[0] == 'E')
            break;
        cin >> parent2;
        cin >> child;

        cout << "Case " << ++tc << ": ";
        if (child.compare("?") == 0) {
            cout << parent1 << " " << parent2 << " ";
            printBloodTypes(getChildBloodTypes(parent1, parent2));
            cout << "\n";
        }
        else if (parent2.compare("?") == 0) {
            cout << parent1 << " ";
            printBloodTypes(getParentBloodTypes(parent1, child));
            cout << " " << child << "\n";
        }
        else {
            printBloodTypes(getParentBloodTypes(parent2, child));
            cout << " " << parent2 << " " << child << "\n";
        }
    }
}
