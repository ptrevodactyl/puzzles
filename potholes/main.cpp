/*
There is a machine that can fix all potholes along a road 3 units in length.
A unit of road will be represented by a period in a string.
For example, “…” is one section of road 3 units in length.
Potholes are marked with an “X” in the road, and also count as 1 unit of length.
The task is to take a road of length N and fix all potholes with the fewest
possible sections repaired by the machine.

The city where I live needs one of those machines.

Here are some examples:

.X.          1
.X...X       2
XXX.XXXX     3
.X.XX.XX.X   3

Your task is to write a program that takes a string representing a road and
returns the smallest number of fixes that will remove all the potholes.

https://programmingpraxis.com/2021/05/11/potholes/
*/

#include <iostream>
#include <string.h>

int main(int argc, char** argv) {
    if(argc < 2) return 1;
    char *road = argv[1];

    int len = strlen(road), count = 0;
    for(int i = 0; i < len; i++) {
        if(road[i] == 'X') {
            i += 2;
            count++;
        }
    }

    printf("Road: %s\nFixed in %d fixes.\n", argv[1], count);
    return 0;
}