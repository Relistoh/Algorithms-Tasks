#include <fstream>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    int n;
    in >> n;
    int ** matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> matrix[i][j];
        }
    }
    in.close();
    std::vector<int> c(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                c[j] = i + 1;
            }
        }
    }
    std::ofstream out("output.txt");
    for (int i = 0; i < n; i++) {
        out << c[i] << " ";
    }
    out.close();
}
