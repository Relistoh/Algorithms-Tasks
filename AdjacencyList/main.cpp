#include <fstream>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    int n;
    int m;
    in >> n;
    in >> m;
    int a, b;
    auto *l = new std::vector<int>[n];

    for (int i = 0; i < m; i++) {
        in >> a;
        in >> b;
        l[a - 1].push_back(b);
        l[b - 1].push_back(a);
    }
    in.close();

    std::ofstream out("output.txt");
    for (int i = 0; i < n; i++) {
        out << l[i].size() << " ";
        for (int j = l[i].size() - 1; j >= 0; j--) {
            out << l[i][j] << " ";
        }
        out << '\n';
    }
    out.close();
}
