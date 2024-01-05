#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, c, n, s = 0;
    ifstream in("input.txt");
    in >> m;
    in >> c;
    in >> n;
    vector <int> a;
    vector <int> b(m, -1);

    for (int i = 0; i < n; i++) {
        int f = 0;
        in >> s;
        for (int j : a) {
            if (j == s) {
                f = 1;
                break;
            }
        }
        if (f == 0)
            a.push_back(s);
    }
    in.close();

    for (int j : a) {
        int x = 0;
        for (int i = 0; i < m; i++) {
            x = (j % m + c * i) % m;
            if (b[x] == -1) {
                b[x] = j;
                break;
            }
        }
    }
    ofstream out("output.txt");
    for (int i : b)
        out << i << " ";
    out.close();
}
