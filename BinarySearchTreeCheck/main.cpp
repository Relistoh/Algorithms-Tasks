#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct Table {
    long long int key;
    long long int father;
    std::string son;
    long long int low = LONG_LONG_MIN;
    long long int high = LONG_LONG_MAX;
};

int main() {
    std::ifstream in("bst.in");
    long long int n;
    in >> n;
    std::vector<Table> table(n);
    in >> table[0].key;
    std::ofstream out("bst.out");
    for (int i = 1; i < n; i++) {
        in >> table[i].key;
        in >> table[i].father;
        in >> table[i].son;
        if (table[i].son == "L") {
            table[i].high = table[table[i].father - 1].key;
            table[i].low = table[table[i].father - 1].low;
        } else {
            table[i].low = table[table[i].father - 1].key;
            table[i].high = table[table[i].father - 1].high;
        }

        if (table[i].key < table[i].low || table[i].key >= table[i].high)
        {
            out << "NO";
            return 0;
        }
    }
    out << "YES";
    in.close();
    out.close();
}
