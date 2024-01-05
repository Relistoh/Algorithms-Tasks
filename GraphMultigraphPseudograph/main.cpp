#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream in("input.txt");
    int n;
    int m;
    in >> n;
    in >> m;
    int a, b;
    auto *l = new std::vector<int>[n];
    std::string g = "Yes", mg = "Yes", pg = "Yes";

    for (int i = 0; i < m; i++) {
        in >> a;
        in >> b;
        if (a == b)
        {
            mg = "No";
            g = "No";
        }
        for (int j : l[a - 1])
            if (j == b)
                g = "No";

        for (int j : l[b - 1])
            if (j == a)
                g = "No";
        l[a - 1].push_back(b);
        l[b - 1].push_back(a);
    }
    in.close();

    std::ofstream out("output.txt");
    out << g << '\n' << mg << '\n' << pg;
    out.close();
}