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

ANode *MinKey(ANode *v) {
    if (!v->left)
        return v;
    else
        return MinKey(v->left);
}

ANode *DeleteNode(ANode *v, int x) {
    if (!v)
        return nullptr;
    if (x < v->key) {
        v->left = DeleteNode(v->left, x);
        return v;
    } else if (x > v->key) {
        v->right = DeleteNode(v->right, x);
        return v;
    }

    if (!v->left) {
        return v->right;
    } else if (!v->right) {
        return v->left;
    } else {
        int min = MinKey(v->right)->key;
        v->key = min;
        v->right = DeleteNode(v->right, min);
    }
    return v;
}

int main() {
    std::ifstream in("input.txt");
    int a;
    int b;
    in >> b;
    in.ignore();
    ATree tree;
    while (in >> a) {
        tree.Insert(a);
    }
    in.close();
    tree.root = DeleteNode(tree.root, b);
    std::ofstream out("output.txt");
    Travel(tree.root, out);
    out.close();
}
