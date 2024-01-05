#include <iostream>

int long long posPowMod(int base, int e) {
    if (e == 0) {
        return 1;
    } else if (e > 0) {
        int long long result = posPowMod(base, e / 2);
        if (e % 2 == 0) {
            return (result % 1000000007 * result % 1000000007) % 1000000007;
        } else {
            return (base % 1000000007 * result % 1000000007 * result % 1000000007) % 1000000007;
        }
    }
}

int main() {
    int K, N;
    std::cin >> N;
    std::cin >> K;
    if (K > N - K)
        K = N - K;
    int long long result = 1;
    for (int i = 0; i < K; i++) {
        result = (result * (N - i)) % 1000000007;
        result = (result * posPowMod(i + 1, 1000000005)) % 1000000007;
    }
    std::cout << result;
    return 0;
}