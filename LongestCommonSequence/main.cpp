#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        b.push_back(t);
    }

    int **matrix = new int *[n + 1];
    for (int i = 0; i < n + 1; i++) {
        matrix[i] = new int[n + 1];
    }

    for (int i = 0; i < n + 1; i++) {
        matrix[0][i] = 0;
        matrix[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (a[i - 1] != b[j - 1])
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            else
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
        }
    }
    int l = matrix[n][n];
    cout << l << '\n';
    int *x = new int[l];
    int *y = new int[l];
    int i = n;
    int j = n;
    int k = l - 1;
    while (i != 0 && j != 0) {
        if (a[i - 1] != b[j - 1]) {
            if (matrix[i][j] == matrix[i][j - 1])
                j--;
            else
                i--;
        } else {
            x[k] = i - 1;
            y[k] = j - 1;
            i--;
            j--;
            k--;
        }
    }
    for (int r = 0; r < matrix[n][n]; r++) {
        cout << x[r] << " ";
    }
    cout << '\n';
    for (int r = 0; r < matrix[n][n]; r++) {
        cout << y[r] << " ";
    }

    return 0;
}