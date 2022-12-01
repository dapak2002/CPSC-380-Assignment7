#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ARR_SIZE 1000       //added by Adrian

int INITIAL_POS;
int fcfs(int *queue, int size);
int sstf(int *queue, int size);
int scan(int *queue, int size);
int cscan(int *queue, int size);
int* sort(int *queue, int size);
int *queue_arr = new int[ARR_SIZE];     //added by Adrian


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

int sstf(int *queue, int size) {
    int result = 0;
    return result;

}

int scan(int *queue, int size) {
    int result = 0;
    return result;

}

int cscan(int *queue, int size) {
    int result = 0;
    return result;

}

int* sort(int *queue, int size) {
    for (int i = 0; i < (size - 1); i++) {
        if (queue[i] > queue[i + 1]) {
            int hold = queue[i];
            queue[i] = queue[i+1];
            queue[i+1] = hold;
            i = -1;
        }
    }
    return queue;
}

void readFile(string inputFileName){        //added by Adrian
    ifstream inputFile;
    inputFile.open(inputFileName);
    if(!inputFile.is_open()){
        cout << "Could not open input file." << endl;
    }
    string lineContent;
    int lineContentConverted;
    int i = 0;
    while (!inputFile.fail()){
        getline(inputFile, lineContent);
        lineContentConverted = stoi(lineContent);
        queue_arr[i] = lineContentConverted;
        i++;
    }
    inputFile.close();
}
