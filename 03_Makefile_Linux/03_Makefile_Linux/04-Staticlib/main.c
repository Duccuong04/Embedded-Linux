#include "hello.h"
#include "sum.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{ 
    hello();
    printf("%d", sum(1,2));
    return 0;
}
