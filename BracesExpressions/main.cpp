#include <iostream>

void f(std::string s, int a, int b) {
    if (b == 0)
        std::cout << s << std::endl;
    else {
        if (a > 0)
            f(s + "(", a - 1, b);
        if (b > a)
            f(s + ")", a, b - 1);
    }
}

int main() {
    f("", 2, 2);
    return 0;
}
