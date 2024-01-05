#include <fstream>
#include <iostream>
#include <queue>

int main() {
    std::ifstream in("input.txt");
    int n = 0;
    in >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> a[i][j];
    in.close();
    bool *b = new bool[n];
    int *c = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        b[i] = false;
    }
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            q.push(i + 1);
            while (!q.empty()) {
                count++;
                int v = q.front();
                c[v - 1] = count;
                q.pop();
                b[v - 1] = true;
                for (int j = 0; j < n; j++)
                    if (a[v - 1][j] == 1) {
                        if (!b[j]) {
                            b[j] = true;
                            q.push(j + 1);
                        }
                    }
            }
        }
    }
    std::ofstream out("output.txt");
    for (int i = 0; i < n; i++)
        out << c[i] << " ";
    out.close();
}
