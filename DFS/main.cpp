#include <fstream>

void dfs(int v, int **a, int *count, bool *b, int n, int &num) {
    b[v] = true;
    num++;
    count[v] = num;
    for (int i = 0; i < n; i++) {
        if (!b[i] && a[v][i] == 1) {
            dfs(i, a, count, b, n, num);
        }
    }
}

int main() {
    std::ifstream in("input.txt");
    int n;
    int num = 0;
    in >> n;
    int *count = new int[n];
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> a[i][j];
        }
    }
    in.close();
    bool *b = new bool[n];
    for (int i = 0; i < n; i++) {
        b[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            dfs(i, a, count, b, n, num);
        }
    }

    std::ofstream out("output.txt");
    for (int i = 0; i < n; i++) {
        out << count[i] << " ";
    }
    out.close();
}
