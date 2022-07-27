/*
Nim is a game played with heaps of stones, where two players take it in turn to
remove any number of stones from any heap until no stones remain.

https://projecteuler.net/problem=301
*/

#include <iostream>

#define HEAP_SIZE 3
#define DEFAULT_STONES 3

void printHeap(int *heap) {
    printf("[");
    for(int i = 0; i < HEAP_SIZE; i++) printf("%d%s", heap[i], i == HEAP_SIZE - 1 ? "]\n": ", ");
}

bool gameOver(int *heap) {
    int sum = 0;
    for(int i = 0; i < HEAP_SIZE; i++) sum += heap[i];
    return (bool) !sum;
}

int main(int argc, char **argv) {
    int heap[HEAP_SIZE]{};
    if(argc < HEAP_SIZE + 1) for(int &i : heap) i = DEFAULT_STONES;
    else {
        for(int i = 0; i < HEAP_SIZE; i++) heap[i] = atoi(argv[i + 1]);
    }

    char input[256];
    int index, numSticks, player = 0;
    while(true) {
        printHeap(heap);
        printf("P%d: enter index to remove from: ", player + 1);
        std::cin >> input;
        index = atoi(input);
        if(index >= HEAP_SIZE) index = HEAP_SIZE - 1;
        else if(index < 0) index = 0;
        if(heap[index] < 1) {
            printf("Index is empty, try a different one.\n");
            continue;
        }

        printf("P%d: enter number of sticks to remove: ", player + 1);
        std::cin >> input;
        numSticks = atoi(input);

        if(numSticks > heap[index]) numSticks = heap[index];
        else if(numSticks < 1) numSticks = 1;

        heap[index] -= numSticks;
        if(gameOver(heap)) {
            printf("P%d wins!\n", player + 1);
            break;
        }
        player = !player;
    }

    return 0;
}