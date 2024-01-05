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

    bool IsOneUnion() {
        bool foundA = false, foundB = false;
        for (int i : parent) {
            if (i < 0) {
                if (!foundA) {
                    foundA = true;
                    continue;
                } else {
                    foundB = true;
                    break;
                }
            }
        }
        return !(foundA && foundB);
    }
};

struct Road {
    int a;
    int b;
};

int main() {
    std::ifstream in("input.txt");
    int n, m, q;
    in >> n;
    in >> m;
    in >> q;
    std::vector<Road> roads;
    Road buf{};
    for (int i = 0; i < m; i++) {
        in >> buf.a;
        buf.a--;
        in >> buf.b;
        buf.b--;
        roads.push_back(buf);
    }
    std::vector<int> earthquakesSort;
    std::vector<int> earthquakes(q);

    for (int i = q - 1; i >= 0; i--) {
        in >> earthquakes[i];
        earthquakes[i]--;
        earthquakesSort.push_back(earthquakes[i]);
    }
    in.close();

    DisjointSetUnion country(n);
    std::sort(earthquakesSort.begin(), earthquakesSort.end());

    for (int i = 0; i < m; i++) {
        if (std::binary_search(earthquakesSort.begin(), earthquakesSort.end(), i)) {
            continue;
        } else {
            country.Union(roads[i].a, roads[i].b);
        }
    }

    std::ofstream out("output.txt");
    std::vector<bool> reverse;
    bool t = country.IsOneUnion();
    reverse.push_back(t);
    for (int i = 0; i < q - 1; i++) {
        int a = roads[earthquakes[i]].a;
        int b = roads[earthquakes[i]].b;
        if (country.FindSet(a) == country.FindSet(b))
            reverse.push_back(t);
        else {
            country.Union(a, b);
            t = country.IsOneUnion();
            reverse.push_back(t);
        }
    }
    for (int i = q - 1; i >= 0; i--)
        out << reverse[i];
    out.close();
}
