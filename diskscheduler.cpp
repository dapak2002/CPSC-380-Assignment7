#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ARR_SIZE 1000

int INITIAL_POS;
int *queue_arr = new int[ARR_SIZE];
int fcfs(int *queue, int size);

void readFile(string inputFileName){
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
