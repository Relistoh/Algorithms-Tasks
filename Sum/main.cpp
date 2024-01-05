#include <iostream>
#include <vector>
#include <string>

void Build(std::vector<long long int> &a, std::vector<long long int> &t, int v, int l, int r) {
    if (r - l == 1)
        t[v] = a[l];
    else {
        int m = (l + r) / 2;
        Build(a, t, 2 * v, l, m);
        Build(a, t, 2 * v + 1, m, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void Add(std::vector<long long int> &t, int v, int l, int r, int i, long long int x) {
    if (r - l == 1) {
        t[v] += x;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        Add(t, 2 * v, l, m, i, x);
    } else {
        Add(t, 2 * v + 1, m, r, i, x);
    }
    t[v] = t[2 * v] + t[2 * v + 1];
}

long long int FindSum(std::vector<long long int> &t, int v, int l, int r, int newl, int newr) {
    if (l == newl && r == newr)
        return t[v];
    int m = (l + r) / 2;
    if (newr <= m)
        return FindSum(t, 2 * v, l, m, newl, newr);
    if (m <= newl)
        return FindSum(t, 2 * v + 1, m, r, newl, newr);
    return (
            FindSum(t, 2 * v, l, m, newl, m) +
            FindSum(t, 2 * v + 1, m, r, m, newr));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<long long int> a(n);
    std::vector<long long int> t(4 * n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    Build(a, t, 1, 0, n);
    int q;
    std::cin >> q;
    std::cin.ignore();
    for (int i = 0; i < q; i++) {
        std::string str;
        std::cin >> str;
        if (str == "FindSum") {
            int l, r;
            std::cin >> l >> r;
            std::cout << FindSum(t, 1, 0, n, l, r) << '\n';

        } else {
            int index;
            long long int value;
            std::cin >> index >> value;
            Add(t, 1, 0, n, index, value);
        }
    }

    return 0;
}