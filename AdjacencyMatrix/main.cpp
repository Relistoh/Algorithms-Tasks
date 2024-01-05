#include <fstream>

int main() {
    std::ifstream in("input.txt");
    int n, m;
    in >> n;
    in >> m;
    int l, r;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        in >> l;
        in >> r;
        a[l - 1][r - 1] = 1;
        a[r - 1][l - 1] = 1;
    }
    in.close();

    std::ofstream out("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << a[i][j] << " ";
        }
        out << '\n';
    }
    out.close();
}
