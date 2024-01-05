#include <fstream>
#include <vector>

using namespace std;

struct MatrixSize
{
    int n;
    int m;
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    int b;
    in >> n;
    auto *a = new MatrixSize[n];
    auto **matrix = new long long int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new long long int[n];
    }
    int r = 0;
    while (in >> b) {
        a[r].n = b;
        in>>b;
        a[r].m = b;
        r++;
    }
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        matrix[i][i + 1] = a[i].n * a[i].m * a[i + 1].m;
    }
    for (int j = 0; j <= n - 1; j++) {
        for (int i = n - 1; i >= 0; i--) {
            long long int l = 9223372036854775807;
            if (j > i) {
                for (int k = i; k < j; k++) {
                    long long int t;
                    t = matrix[i][k] + matrix[k + 1][j] + a[i].n * a[k].m * a[j].m;
                    if (l > t)
                        l = t;
                }
                matrix[i][j] = l;
            }
        }
    }
    out << matrix[0][n - 1];
}
