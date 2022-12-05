#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ARR_SIZE 1000       //added by Adrian
#define MAX_POS 4999
int INITIAL_POS;



int fcfs(int *queue, int size);
int sstf(int *queue, int size);
int scan(int *queue, int size);
int cscan(int *queue, int size);
int* sort(int *queue, int size);
void readFile(string inputFileName);
int *queue_arr = new int[ARR_SIZE];     //added by Adrian
int *queue_arr2 = new int[ARR_SIZE]; 
int *queue_arr3 = new int[ARR_SIZE]; 
int *queue_arr4 = new int[ARR_SIZE]; 


int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Please use the proper command line arguments: ./diskscheduler <inital position (0 - 4999)> <file name>" << endl;
        return 0;
    }
    INITIAL_POS = stoi(argv[1]);
    if ((INITIAL_POS > 4999) || (INITIAL_POS < 0)) {
        cout << "Please use the proper command line arguments: ./diskscheduler <inital position (0 - 4999)> <file name>" << endl;
        return 0;
    }
    readFile(argv[2]);
    
    int* req = sort(queue_arr2,ARR_SIZE);
    int* req2 = sort(queue_arr3,ARR_SIZE);
    int* req3 = sort(queue_arr4,ARR_SIZE);
    
    int fcfs_num = fcfs(queue_arr,ARR_SIZE);
    int scan_num = scan(req,ARR_SIZE);
    int cscan_num = cscan(req2,ARR_SIZE);
    int sstf_num = sstf(req3,ARR_SIZE);

    cout << "FCFS:   " << fcfs_num << endl;
    cout << "SSTF:   " << sstf_num << endl;
    cout << "SCAN:   " << scan_num << endl;
    cout << "C-SCAN: " << cscan_num << endl;
}

// First come first serve
int fcfs(int *queue, int size) {
    int result = 0;
    int position = INITIAL_POS;
    for(int i = 0; i < size; i++) {
        result += abs((position - queue[i]));
        position = queue[i];
    }
    return result;
}

// Shortest seek time first
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
        count++;
        position = queue[index];
        queue[index] = -1;
        diff = 5001;
        index = 0;
    }
    return result;
}

// SCAN
int scan(int *queue, int size) {
    int result = 0;
    int position = INITIAL_POS;
    int mid;
    int count = 1;
    
    // Find index of request towards 0
    for (int i = 0; i < size; i++) {
        if (queue[i] < position) {
            mid = i;
        }
    }

    // Move arm towards 0 fulfilling requests along the way
    for (int i = mid; i >= 0; i--) {
        result += abs(position - queue[i]);
        position = queue[i];
        count++;
    }
    if (count == ARR_SIZE) {
        return result;
    }

    // Move all the way to 0 position
    result += position;
    position = 0;

    // Move arm towards max fulfilling requests along the way
    for (int i = mid + 1; i < size; i++) {
        result += abs(position - queue[i]);
        position = queue[i];
    }

    return result;

}

// C-SCAN
int cscan(int *queue, int size) {
    int result = 0;
    int position = INITIAL_POS;
    int mid = 0;
    int count = 1;
    
    // Find first request towards the max
    for (int i = 0; i < (size); i++) {
        if (queue[i] < position) {
            mid = i;
        }
    }

    // If the arm is past the last request, move to 0
    if (position > queue[size - 1]) {
        result += (MAX_POS - position);
        position = MAX_POS;
        result += position;
        position = 0;
        mid = 0;
    }
    
    // Move arm towards max fulfilling requests along the way
    for (int i = mid + 1; i < size; i++) {
        result += abs(position - queue[i]);
        position = queue[i];
        queue[i] = -1;
        count++;
    }

    // If all of the requests have been fulfilled return
    if (count == ARR_SIZE) {
        return result;
    }

    // Mover arm back to 0
    result += abs(MAX_POS - position);
    position = MAX_POS;
    result += position;
    position = 0;

    // Move arm towards max fulfilling requests along the way
    for (int i = 0; i < size; i++) {
        if (queue[i] != -1) {
            result += abs(position - queue[i]);
            position = queue[i];
        }
    }
    return result;
}

// Sorts from least to greatest using bubble sort
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
        exit(0);
    }
    string lineContent;
    int lineContentConverted;
    int i = 0;
    while (!inputFile.fail()){
        getline(inputFile, lineContent);
        if (lineContent == "") {
            break;
        }
        lineContentConverted = stoi(lineContent);
        queue_arr[i] = lineContentConverted;
        queue_arr2[i] = lineContentConverted;
        queue_arr3[i] = lineContentConverted;
        queue_arr4[i] = lineContentConverted;
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
