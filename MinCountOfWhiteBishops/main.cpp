#include <fstream>
#include <stack>

int f(int **&a, int n, int m, int i, int j) {
    std::stack<std::pair<int, int>> s;
    s.push(std::make_pair(i, j));

    while (!s.empty()) {
        std::pair<int, int> current = s.top();
        s.pop();
        int ci = current.first;
        int cj = current.second;

        if (ci < n - 1 && cj < m - 1 && a[ci + 1][cj + 1] == 0) {
            a[ci + 1][cj + 1] = 1;
            s.push(std::make_pair(ci + 1, cj + 1));
        }
        if (cj < m - 1 && ci > 0 && a[ci - 1][cj + 1] == 0) {
            a[ci - 1][cj + 1] = 1;
            s.push(std::make_pair(ci - 1, cj + 1));
        }
        if (ci < n - 1 && cj > 0 && a[ci + 1][cj - 1] == 0) {
            a[ci + 1][cj - 1] = 1;
            s.push(std::make_pair(ci + 1, cj - 1));
        }
        if (ci > 0 && cj > 0 && a[ci - 1][cj - 1] == 0) {
            a[ci - 1][cj - 1] = 1;
            s.push(std::make_pair(ci - 1, cj - 1));
        }
    }

    return 0;
}

int main() {
    std::ifstream in("in.txt");
    int n, m;
    in >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            in >> a[i][j];
        }

    in.close();

    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                a[i][j] = 1;
                f(a, n, m, i, j);
                count++;
            }
        }

    std::ofstream out("out.txt");
    out << count;
    out.close();
}
