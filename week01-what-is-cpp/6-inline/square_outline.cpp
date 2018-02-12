/**
 * A demo of inline functions.
 * Compile with --assemble.
 */

int square(int x) {
    return x*x;
}

int main() {
    int* sum = new int;
    long x = long(sum);
    int y = square(x);
    return y;
}
