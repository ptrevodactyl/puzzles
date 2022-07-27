/*
Given a list of integers, calculate a list of integers that contains, 
at each item of the list, the count of integers in the original list 
that are greater than the item at the current position of the original list. 
For example, given the input list (10 12 8 17 3 24 19), 
the desired output is (4 3 3 2 2 0 0)

https://programmingpraxis.com/2021/03/09/bigger-to-the-right/
*/

#include <iostream>

#define MAX 100

int main(int argc, char** argv) {
    if(argc < 2) return 1;
    int size = atoi(argv[1]);
    srand(time(NULL));
    int list[size]; // = {10, 12, 8, 17, 3, 24, 19};
    for(int i = 0; i < size; i++) {
        list[i] = rand() % MAX;
        printf("%3d%s", list[i], i == size - 1 ? "\n" : " | ");
    }
    int list2[size]{0};
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(list[i] < list[j]) list2[i]++;
        }
        printf("%3d%s", list2[i], i == size - 1 ? "\n" : " | ");
    }
}