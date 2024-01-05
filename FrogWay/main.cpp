#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    if (n == 1) {
        std::cout << a[0] << '\n' << 1;
        return 0;
    }
    if (n == 2) {
        std::cout << -1;
        return 0;
    }
    int *b = new int[n];
    b[0] = a[0];
    b[1] = -1;
    b[2] = b[0] + a[2];
    int *c = new int[n];
    c[2] = 1;
    for (int i = 3; i < n; i++) {
        if (b[i - 2] > b[i - 3]) {
            b[i] = a[i] + b[i - 2];
            c[i] = i - 1;
        } else {
            b[i] = a[i] + b[i - 3];
            c[i] = i - 2;
        }
    }
    std::cout << b[n - 1] << '\n';
    a[0] = n;
    int k = 1;
    int j = n - 1;
    while (j > 1){
        a[k] = c[j];
        j = c[j] - 1;
        k++;
    }
    std::cout << a[k - 1];
    for (int i = k - 2; i > -1; i--)
        std::cout << " " << a[i];
    return 0;
}