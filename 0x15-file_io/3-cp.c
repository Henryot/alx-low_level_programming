#include <stdio.h>
#include <stdlib.h>
#include "3-cp.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
        print_usage_error(argv[0]);

    copy_file(argv[1], argv[2]);

    return (0);
}
