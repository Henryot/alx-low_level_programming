#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int n;
    srand(time(0));
    n = rand() - RAND_MAX/2;
    
    if (n > 0){
        printf("the number is positive %d\n", n);
    }
    else if (n == 0){
        printf("the number is zero %d\n", n);
    }
    else {
        printf("the number is negative %d\n", n);
    }
    return 0;
}
