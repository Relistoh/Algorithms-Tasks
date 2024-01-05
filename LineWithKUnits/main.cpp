#include <iostream>

int main() {
    int n, k;
    std::cin >> n;
    std::cin >> k;
    int *m = new int[k + 1];
    for (int i = 0; i < k + 1; i++)
        m[i] = 1;
    for (int i = 2; i < n + 1; i++)
        if (i < i)
            m[i][j] = (m[i - 1][j - 1] % 1000000007 + m[i - 1][j] % 1000000007) % 1000000007;
    std::cout << m[n][k];
}
