/**
 * A demo of inline functions.
 * Compile with --assemble.
 */

int square(int x) {
    return x*x;
}

// double square(double x) {
//     return x*x;
// }

int main() {
    int y1 = square(1234);
    return y1;
}
