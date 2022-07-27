/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roses-for-valentine-4a795f72/
*/

#include <iostream>
#include <vector>

#define NUM_FLOWERS 5
#define SMELL_RANGE (NUM_FLOWERS * 10)

std::vector<int> longestSequence(int start, int end, std::vector<int> smell) {
    std::vector<int> subSeq, longestSeq;

    for(int i = 0; i < smell.size();) {
        subSeq = {smell[i++]};
        while(i < smell.size() && smell[i] > smell[i - 1]) subSeq.push_back(smell[i++]); 
        if(subSeq.size() > longestSeq.size()) longestSeq = subSeq;
    }

    return longestSeq;
}

int main(int argc, char **argv) {
    std::vector<int> smell = {1, 2, 5, 3, 4};
    srand(time(NULL));

    for(int i = 0; i < NUM_FLOWERS; i++) {
        //smell.push_back(rand() % SMELL_RANGE);
        printf("%d%s", smell[i], i == NUM_FLOWERS - 1 ? "\n" : ", ");
    }

    std::vector<int> ls = longestSequence(0, NUM_FLOWERS, smell);
    for(int i = 0; i < ls.size(); i++) printf("%d%s", ls[i], i == ls.size() - 1 ? "\n" : ", ");

    return 0;
}