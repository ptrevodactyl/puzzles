/*
A binary chop (sometimes called the more prosaic binary search) finds the position
of value in a sorted array of values. It achieves some efficiency by halving the
number of items under consideration each time it probes the values: in the first
pass it determines whether the required value is in the top or the bottom half of
the list of values. In the second pass in considers only this half, again dividing
it in to two. It stops when it finds the value it is looking for, or when it runs
out of array to search. Binary searches are a favorite of CS lecturers.
*/

#include <iostream>
#include <algorithm>

#define SIZE 10000
#define MAX 100000

/**
 * @brief Searches the given array of integers for a given value using a binary
 * search technique. Assumes the given array is sorted.
 * 
 * @param val 
 * @param nums 
 * @param size the size of the array
 * @return the index of the value if found or -1 if the value isn't found 
 */
int search(int val, int *nums, int size) {
    int curr = size >> 1, min = 0, max = size;
    while(min < max) {
        if(val < nums[curr]) max = curr;
        else if(val > nums[curr]) min = curr + 1;
        else return curr;
        curr = (min + max) >> 1;
    }
    return -1;
}

int main(int argc, char **argv) {
    if(argc < 2) return 1;
    int val = atoi(argv[1]);

    srand(time(NULL));
    int list[SIZE];
    for(int i = 0; i < SIZE; i++) list[i] = rand() % MAX;
    std::sort(list, list + SIZE);
    //printf("[");
    //for(int i = 0; i < SIZE; i++) printf("%d%s", list[i], i == SIZE - 1 ? "]\n" : ", ");

    int index = search(val, list, SIZE);

    if(index == -1) printf("%d not found.\n", val);
    else printf("Found %d at index %d.\n", val, index);

    return 0;
}