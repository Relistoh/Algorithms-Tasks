#include <fstream>
#include <vector>
#include <algorithm>

class DisjointSetUnion {
private:
    std::vector<int> parent;

public:
    explicit DisjointSetUnion(int n) : parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = -1;
        }
    }

    int FindSet(int x) {
        std::vector<int> buf;
        while (parent[x] >= 0) {
            buf.push_back(x);
            x = parent[x];
        }
        for (int i: buf) {
            parent[i] = x;
        }
        return x;
    }

    void Union(int x, int y) {
        x = FindSet(x);
        y = FindSet(y);

        if (x != y) {
            if (parent[x] > parent[y]) {
                std::swap(x, y);
            }

            parent[x] += parent[y];
            parent[y] = x;
        }
    }

    int UnitsCount() {
        int r = 0;
        for (int i: parent)
            if (i < 0) {
                r++;
            }
        return r;
    }
};

struct Road {
    int a;
    int b;
};

int main() {
    std::ifstream in("input.txt");
    int n, q;
    in >> n;
    in >> q;
    std::vector<Road> roads;
    Road buf{};
    for (int i = 0; i < q; i++) {
        in >> buf.a;
        buf.a--;
        in >> buf.b;
        buf.b--;
        roads.push_back(buf);
    }
    in.close();

    DisjointSetUnion country(n);

    std::ofstream out("output.txt");

    int t = country.UnitsCount();

    for (int i = 0; i < q; i++) {
        int a = roads[i].a;
        int b = roads[i].b;
        if (country.FindSet(a) == country.FindSet(b))
            out << t << '\n';
        else {
            country.Union(a, b);
            t--;
            out << t << '\n';
        }
    }
    out.close();
}