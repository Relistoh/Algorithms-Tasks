#include <fstream>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    int n;
    in >> n;
    int a, b;
    std::vector<int> c(n, 0);
    for (int i = 0; i < n - 1; i++) {
        in >> a;
        in >> b;
        b--;
        c[b] = a;
    }
    in.close();

    std::ofstream out("output.txt");
    for (int i = 0; i < n; i++) {
        out << c[i] << " ";
    }
    out.close();
}
