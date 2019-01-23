#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void uva_11235() {
    struct Node {
        int start;
        int end;
        int value;
        Node *left, *right;
        Node(int start, int end, int value) {
            this->start = start;
            this->end = end;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    int n;
    while (cin >> n, n) {
        int q;
        cin >> q;

        vector<Node *> nodes;
        int currValue = 88888888;
        for (int i = 1; i <= n; i++) {
            int value;
            cin >> value;
            if (currValue != value) {
                currValue = value;
                Node *newNode = new Node(i, i, 1);
                nodes.push_back(newNode);
            }
            else {
                int lastIndex = nodes.size() - 1;
                nodes[lastIndex]->value++;
                nodes[lastIndex]->end = i;
            }
        }

        while (nodes.size() > 1) {
            vector<Node *> parents;
            for (int i = 0, s = nodes.size(); i < s; i += 2) {
                if (i + 1 == s) {
                    parents.push_back(nodes[i]);
                    break;
                }
                Node *parent = new Node(nodes[i]->start,
                    nodes[i + 1]->end,
                    max(nodes[i]->value, nodes[i + 1]->value));
                parent->left = nodes[i];
                parent->right = nodes[i + 1];
                parents.push_back(parent);
            }
            nodes = parents;
        }

        Node *root = nodes[0];

        int i, j;
        while (q--) {
            cin >> i;
            cin >> j;

            function<int(Node *)> read = [&](Node *root) {
                if (root == NULL || j < root->start || i > root->end)
                    return 0;
                if (i <= root->start && root->end <= j)
                    return root->value;
                if (root->left == NULL && root->right == NULL) {
                    if (i <= root->start && root->start <= j)
                        return j - root->start + 1;
                    if (i <= root->end && root->end <= j)
                        return root->end - i + 1;
                    return j - i + 1;
                }
                return max(read(root->left), read(root->right));
            };

            cout << read(root) << "\n";
        }
    }
}
