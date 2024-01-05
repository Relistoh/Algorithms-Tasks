#include <fstream>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    int n;
    in >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        in >> h[i];
    }
    in.close();
    std::ofstream out("output.txt");
    if (n == 2 && h[0] <= h[1]){
        out << "Yes" << '\n';
        out.close();
        return 0;
    }
    if (h[(n - 2) / 2] > h[n - 1])
    {
        out << "No" << '\n';
        out.close();
        return 0;
    }
    for (int i = (n - 3) / 2; i >= 0; i--) {
        if (h[i] > h[2 * i + 1] || h[i] > h[2 * i + 2])
        {
            out << "No" << '\n';
            out.close();
            return 0;
        }
    }
    out << "Yes" << '\n';
    out.close();
    return 0;
}
