#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int INITIAL_POS;
int fcfs(int *queue, int size);

int main(int argc, char *argv[]) {
    INITIAL_POS = 5;
    int array[5] = {10,5,2,4,7};
    int fcfs_count = fcfs(array,INITIAL_POS);
    cout << fcfs_count << endl;
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