#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    int k;
    std::cin >> k;
    int *c = new int[k];
    for (int i = 0; i < k; i++)
        std::cin >> c[i];


    for (int i = 0; i < k; i++) {
        int s = 0, f = n, b = 0, m, r;
        while (s < f) {
            m = (s + f) / 2;
            if (a[m] == c[i]) {
                b = 1;
                break;
            } else if (c[i] < a[m])
                f = m;
            else
                s = m + 1;
        }
        int l;
        s = 0;
        f = n;
        while (s < f) {
            m = (s + f) / 2;
            if (c[i] <= a[m])
                f = m;
            else
                s = m + 1;
        }
        l = s;
        s = 0, f = n;
        while (s < f) {
            m = (s + f) / 2;
            if (c[i] < a[m])
                f = m;
            else
                s = m + 1;
        }
        r = s;
        std::cout << b << ' ' << l << ' ' << r << '\n';
    }
    return 0;
}
