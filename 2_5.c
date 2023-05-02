#include "asserts.h"

int main()
{
    assert(1 + 1 == 2);
    assert(1 + 1 == 3);
    assert(1 + 1 == 10);
    fatal_error(10 < 1 + 2, 2);
    return 0;
}