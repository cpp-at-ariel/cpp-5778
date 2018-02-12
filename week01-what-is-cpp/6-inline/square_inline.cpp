/**
 * A demo of inline functions.
 * Compile with --assemble.
 */

inline int square(int x) {
    return x*x;
}

int main() {
    int* sum = new int;
    long x = long(sum);
    int y = square(x);
    return y;
}
