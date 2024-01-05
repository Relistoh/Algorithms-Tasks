#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class ANode {
public:
    explicit ANode(int key) {
        this->key = key;
    }

    int key;
    int height = -1;
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

void TravelCheck(ANode *v, std::vector<int> &keysToDelete) {
    if (v) {
        TravelCheck(v->left, keysToDelete);
        TravelCheck(v->right, keysToDelete);
        if (v->right && v->left){
            v->height = std::max(v->right->height, v->left->height) + 1;
            if (abs(v->right->height - v->left->height) == 2)
                keysToDelete.push_back(v->key);
        }
        else if (!v->right && v->left) {
            v->height = v->left->height + 1;
            if (v->left->height + 1 == 2)
                keysToDelete.push_back(v->key);
        }
        else if (v->right && !v->left) {
            v->height = v->right->height + 1;
            if (v->right->height + 1 == 2)
                keysToDelete.push_back(v->key);
        }
        else
            v->height = 0;
    }
}

void Travel(ANode *v, std::ofstream &out) {
    if (v) {
        out << v->key << '\n';
        Travel(v->left, out);
        Travel(v->right, out);
    }
}

ANode *MaxKey(ANode *v) {
    if (!v->right)
        return v;
    else
        return MaxKey(v->right);
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
        int max = MaxKey(v->left)->key;
        v->key = max;
        v->left = DeleteNode(v->left, max);
    }
    return v;
}

int main() {
    std::ifstream in("tst.in");
    int a;
    ATree tree;
    while (in >> a) {
        tree.Insert(a);
    }
    in.close();
    std::vector<int> keysToDelete;
    TravelCheck(tree.root, keysToDelete);
    std::sort(keysToDelete.begin(), keysToDelete.end());
    if (keysToDelete.size() % 2 == 1)
    {
        int keyToDelete = keysToDelete[keysToDelete.size() / 2];
        if (tree.root->key == keyToDelete && (!tree.root->left || !tree.root->right))
            tree.root = DeleteNode(tree.root, keyToDelete);
        else
            DeleteNode(tree.root, keyToDelete);
    }
    std::ofstream out("tst.out");
    Travel(tree.root, out);
    out.close();
}