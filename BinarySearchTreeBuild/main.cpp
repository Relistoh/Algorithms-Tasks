#include <iostream>
#include <fstream>

class ANode {
public:
    explicit ANode(int key) {
        this->key = key;
    }

    int key;
    ANode *left = nullptr;
    ANode *right = nullptr;
};

class ATree {
public:
    explicit ATree() {
        root = nullptr;
    }

    void Insert(int a);

    ANode *root;
};

void ATree::Insert(int a) {
    ANode **c = &root;
    while (*c) {
        ANode &n = **c;
        if (a < n.key) {
            c = &n.left;
        } else if (a > n.key) {
            c = &n.right;
        } else {
            return;
        }
    }
    *c = new ANode(a);
}

void Travel(ANode *v, std::ofstream &out) {
    if (v) {
        out << v->key << '\n';
        Travel(v->left, out);
        Travel(v->right, out);
    }
}

int main() {
    std::ifstream in("input.txt");
    int a;
    ATree tree;
    while (in >> a) {
        tree.Insert(a);
    }
    in.close();
    std::ofstream out("output.txt");
    Travel(tree.root, out);
    out.close();
}
