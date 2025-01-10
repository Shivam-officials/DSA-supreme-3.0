#include <iostream>
using namespace std;

/**    // Inline function definition
    // Inline functions are suitable for small functions to eliminate the overhead of function calls.
    // Benefits of inline:
    // 1. Avoids function call overhead (stack setup, argument pushing, stack unwinding, etc.).
    // 2. The compiler replaces the function call with the actual function body where it is invoked.
    // 3. Faster execution since there's no need for runtime stack handling.
    // Drawbacks of inline:
    // 1. Increases the size of the executable file if used excessively (due to code duplication).
    // 2. Should be used only for small, frequently used functions to maintain efficiency and readability.
*/
inline void numberShow(int num) {
    cout << num << endl;
}

int main(int argc, char const *argv[]) {
    // The inline function will replace each call to `numberShow` with its body during compilation.
    // This eliminates function call overhead but may lead to a larger executable file.
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);
    numberShow(5);

    return 0;
}
