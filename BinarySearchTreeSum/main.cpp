#include <fstream>
#include <set>

int main() {
    std::set<int> numbs;
    int buf = 0;
    std::ifstream in("input.txt");
    while (in >> buf)
        numbs.insert(buf);
    in.close();
    long long int sum = 0;
    for(std::set<int> :: iterator it = numbs.begin(); it != numbs.end(); ++it)
        sum += *it;
    std::ofstream out("output.txt");
    out << sum;
    out.close();
    return 0;
}