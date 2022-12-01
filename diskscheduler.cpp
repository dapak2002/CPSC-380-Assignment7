#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int INITIAL_POS;
int fcfs(int *queue, int size);
int* sort(int *queue, int size);

int main(int argc, char *argv[]) {
    INITIAL_POS = 53;
    int arrSize = 8;
    int req[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int* req2;
    req2 = sort(req,arrSize);
    for (int i = 0; i < arrSize; i++) {
        cout << req[i] << endl;
    }
}

int fcfs(int *queue, int size) {
    int result = 0;
    int position = INITIAL_POS;
    for(int i = 0; i < size; i++) {
        result += abs((position - queue[i]));
        position = queue[i];
    }
    return result;
}

int* sort(int *queue, int size) {
    for (int i = 0; i < (size - 1); i++) {
        if (queue[i] > queue[i + 1]) {
            int hold = queue[i];
            queue[i] = queue[i+1];
            queue[i+1] = hold;
            i = 0;
        }
    }
    return queue;
}