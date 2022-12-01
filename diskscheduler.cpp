#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ARR_SIZE 1000       //added by Adrian

int INITIAL_POS;
int MAX_POS;
int fcfs(int *queue, int size);
int sstf(int *queue, int size);
int scan(int *queue, int size);
int cscan(int *queue, int size);
int* sort(int *queue, int size);
int *queue_arr = new int[ARR_SIZE];     //added by Adrian


int main(int argc, char *argv[]) {
    INITIAL_POS = 53;
    MAX_POS = 199;
    int arrSize = 8;
    int req[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int* req2 = sort(req,8);
    int test = cscan(req2,8);
    cout << test << endl;
    /*
    int* req2;
    req2 = sort(req,arrSize);
    for (int i = 0; i < arrSize; i++) {
        cout << req[i] << endl;
    }
    */
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
    int position = INITIAL_POS;
    int count = 0;
    int index = 0;
    int diff = abs(INITIAL_POS - (queue[0]));

    while (count < size) {
        for (int i = 0; i < (size); i++) {
            if (queue[i] != -1) {
                if ((abs(queue[i] - position)) < diff) {
                    index = i;
                    diff = abs(queue[i] - position);
                }
            }
        }
        result += diff;
        cout << diff << endl;
        count++;
        position = queue[index];
        queue[index] = -1;
        diff = 5001;
        index = 0;
    }
    return result;
}

int scan(int *queue, int size) {
    int result = 0;
    int position = INITIAL_POS;
    int mid;
    int diff = 5001;
    
    for (int i = 0; i < size; i++) {
        if (queue[i] < position) {
            mid = i;
        }
    }

    for (int i = mid; i >= 0; i--) {
        result += abs(position - queue[i]);
        position = queue[i];
    }
    result += position;
    position = 0;
    for (int i = mid + 1; i < size; i++) {
        result += abs(position - queue[i]);
        position = queue[i];
    }

    return result;

}

int cscan(int *queue, int size) {
    int result = 0;
    int position = INITIAL_POS;
    int diff = 5001;
    int mid = 0;
    
    for (int i = 0; i < (size); i++) {
        if (queue[i] < position) {
            mid = i;
        }
    }

    if (position > queue[size - 1]) {
        result += position;
        position = 0;
        mid = 0;
    }
    
    for (int i = mid + 1; i < size; i++) {
        result += abs(position - queue[i]);
        position = queue[i];
        cout << position << endl;
        queue[i] = -1;
    }
    result += abs(MAX_POS - position);
    position = MAX_POS;
    result += position;
    position = 0;
    for (int i = 0; i < size; i++) {
        if (queue[i] != -1) {
            result += abs(position - queue[i]);
            position = queue[i];
        }
    }
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

void selectionSort(int anArray[], int size){
  int i;
  int j;
  int imin;
  for(i = 0; i < size - 1; i++){
    imin = i;
    for(j = i + 1; j < size; j++){
      if(anArray[j] < anArray[imin]){
        imin = j;
      }
    }
    if(imin != i){
      double temp = anArray[i];
      anArray[i] = anArray[imin];
      anArray[imin] = temp;
    }
  }
}
