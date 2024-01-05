#include <fstream>
#include <queue>
#include <climits>

int main() {
    std::ifstream in("huffman.in");
    long long int n;
    in >> n;
    std::queue<long long int> a;
    long long int buf;
    for (int i = 0; i < n; i++) {
        in >> buf;
        a.push(buf);
    }
    in.close();
    std::queue<long long int> b;
    buf = a.front();
    const long long int inf = LLONG_MAX;
    a.pop();
    buf += a.front();
    a.pop();
    b.push(buf);
    long long int k = n;
    long long int s = buf;
    long long int t = 0;
    long long int ha, hb;
    while (!a.empty() || b.size() != 1) {
        hb = b.front();
        if (a.empty())
            ha = hb + 1;
        else
            ha = a.front();
        if (ha <= hb) {
            a.pop();
            t += ha;
            k--;
        } else {
            b.pop();
            t += hb;
        }
        if (b.empty())
            hb = inf;
        else
            hb = b.front();
        if (a.empty())
            ha = hb + 1;
        else
            ha = a.front();
        if (ha <= hb) {
            a.pop();
            t += ha;
            k--;
        } else {
            b.pop();
            t += hb;
        }
        s += t;
        b.push(t);
        t = 0;
    }
    std::ofstream out("huffman.out");

    out << s;

    out.close();

}