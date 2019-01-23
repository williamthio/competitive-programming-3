#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void e_2_3_5() {
    class RedBlackTree {
    private:
        enum Color { RED, BLACK };

        struct Node {
            int value;
            Color color;
            Node *parent, *left, *right;
            Node(Node *parent, int value) {
                this->value = value;
                this->parent = parent;
                this->color = RED;
                this->left = this->right = NULL;
            }
        };

        Node *root;

        void assignRoot() {
            while (root->parent != NULL)
                root = root->parent;
            root->color = BLACK;
        }

        void rotateRight(Node *root) {
            root->left->parent = root->parent;
            if (root->parent != NULL) {
                if (root->parent->left == root)
                    root->parent->left = root->left;
                else
                    root->parent->right = root->left;
            }
            root->parent = root->left;
            root->left = root->left->right;
            if (root->left != NULL)
                root->left->parent = root;
            root->parent->right = root;
        }

        void rotateLeft(Node *root) {
            root->right->parent = root->parent;
            if (root->parent != NULL) {
                if (root->parent->right == root)
                    root->parent->right = root->right;
                else
                    root->parent->left = root->right;
            }
            root->parent = root->right;
            root->right = root->right->left;
            if (root->right != NULL)
                root->right->parent = root;
            root->parent->left = root;
        }

        void insertFix(Node *curr) {
            if (curr == NULL || curr->parent == NULL)
                return;

            if (curr->parent->color != BLACK) {
                Node *grandParent = curr->parent->parent;
                Node *uncle;
                if (curr->parent == grandParent->left)
                    uncle = grandParent->right;
                else
                    uncle = grandParent->left;

                if (uncle != NULL && uncle->color == RED) {
                    curr->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandParent->color = RED;
                    insertFix(grandParent);
                }
                else if (curr->parent == grandParent->left) {
                    if (curr == curr->parent->left) {
                        rotateRight(grandParent);
                        swap(grandParent->color, curr->parent->color);
                    }
                    else {
                        rotateLeft(curr->parent);
                        rotateRight(grandParent);
                        swap(grandParent->color, curr->color);
                    }
                }
                else if (curr->parent == grandParent->right) {
                    if (curr == curr->parent->right) {
                        rotateLeft(grandParent);
                        swap(grandParent->color, curr->parent->color);
                    }
                    else {
                        rotateRight(curr->parent);
                        rotateLeft(grandParent);
                        swap(grandParent->color, curr->color);
                    }
                }
            }
        }

        void printInorder(Node *root) {
            if (root == NULL)
                return;
            printInorder(root->left);
            cout << root->value << " ";
            printInorder(root->right);
        }

    public:
        int value;

        RedBlackTree() {
            this->root = NULL;
        }

        void printInorder() {
            this->printInorder(root);
            cout << "\n";
        }

        void printLevelOrder() {
            if (root == NULL)
                return;

            queue<Node *> q;
            q.push(root);

            while (!q.empty()) {
                Node *temp = q.front();
                cout << temp->value
                    << (temp->color == BLACK ? "b" : "r")
                    << " ";
                q.pop();

                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            cout << "\n";
        }

        bool exists(int value) {
            Node *curr = root;
            while (curr != NULL) {
                if (curr->value > value)
                    curr = curr->left;
                else if (curr->value < value)
                    curr = curr->right;
                else
                    break;
            }
            return curr != NULL && curr->value == value;
        }

        bool insert(int value) {
            if (this->root == NULL) {
                this->root = new Node(NULL, value);
                this->root->color = BLACK;
                return true;
            }

            Node *curr = root;
            while (true) {
                if (curr->value > value) {
                    if (curr->left == NULL) {
                        curr->left = new Node(curr, value);
                        break;
                    }
                    curr = curr->left;
                }
                else if (curr->value < value) {
                    if (curr->right == NULL) {
                        curr->right = new Node(curr, value);
                        break;
                    }
                    curr = curr->right;
                }
                else
                    return false;
            }

            insertFix(curr);
            assignRoot();

            return true;
        }
    };

    int n, m;
    while (cin >> n, cin >> m, n || m) {
        RedBlackTree rbt;
        int cd;
        while (n--) {
            cin >> cd;
            rbt.insert(cd);
        }
        int count = 0;
        while (m--) {
            cin >> cd;
            if (rbt.exists(cd))
                count++;
        }
        cout << count << "\n";
    }
}
