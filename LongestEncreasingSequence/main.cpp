#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    int n;
    in >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        in >> a[i];
    in.close();
    int *b = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(b, b + j, a[i]) - b;
        if (k == j) {
            b[j] = a[i];
            j++;
        } else
            b[k] = a[i];
    }

    ofstream out("output.txt");
    out << j << '\n';
    out.close();
}