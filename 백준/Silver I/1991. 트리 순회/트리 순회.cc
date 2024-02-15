#include <iostream>
using namespace std;

struct Tree {
    char data;
    Tree* left;
    Tree* right;
};

Tree nodes[26];

void preorder(Tree* root) {
    if (root == nullptr) return;

    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Tree* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void postorder(Tree* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char parent, left, right;
        cin >> parent >> left >> right;

        nodes[parent - 'A'].data = parent;
        if (left != '.') {
            nodes[parent - 'A'].left = &nodes[left - 'A'];
        }
        if (right != '.') {
            nodes[parent - 'A'].right = &nodes[right - 'A'];
        }
    }

    preorder(&nodes[0]);
    cout << endl;
    inorder(&nodes[0]);
    cout << endl;
    postorder(&nodes[0]);
    cout << endl;

    return 0;
}
