#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void merge(double lista[], int start, int middle, int end){
    int leftIndex = start;
    int rightIndex = middle+1;
    int temporalIndex = 0;
    double auxiliarList[5];
    
    while(leftIndex <= middle && rightIndex <= end){
        if(lista[leftIndex] < lista[rightIndex]){
            auxiliarList[temporalIndex] = lista[leftIndex];
            leftIndex++;
            temporalIndex++;
        }else{
            auxiliarList[temporalIndex] = lista[rightIndex];
            rightIndex++;
            temporalIndex++;
        }
    }

    for (int i = leftIndex; i <= middle ; i++) {
        auxiliarList[temporalIndex] = lista[i];
        temporalIndex++;
    } 

    for (int j = rightIndex; j <= end ; j++) {
        auxiliarList[temporalIndex] = lista[j];
        temporalIndex++;
    }

    for (int i = 0; i <= temporalIndex-1; i++) {
        lista[start+i] = auxiliarList[i];
    }
}

void mergeSort(double lista[], int start, int end) {
    if(start < end) {
        int middle = (start+end) / 2;
        mergeSort(lista, start, middle);
        mergeSort(lista, middle+1, end);
        merge(lista, start, middle, end);
    }
    return;
}

int main(){
    double testData[] = {5,4,3,2,1};
    int arraySize = sizeof(testData)/sizeof(testData[0]);
    mergeSort(testData, 0 , arraySize);
    for (int i = 0 ; i < arraySize ; i++){
        cout << testData[i] << " ";
    }
}

// #1
// [4 3 7 2 1]
//  0 1 2 3 4

// izquierda
// #2
// [4 3 7]
//  0 1 2

// izquierda izquierda
// [4 3]
//  0 1

// izquierda izquierda izquierda
// [4]
//  0

// izquierda izquierda derecha
// [3]
//  0

// mezclar
// [3 4]
//  0 1

// izquierda derecha
// [7]
//  0

// Mezclar
// [3 4 7]
//  0 1 2 

// derecha
// [2 1]
//  0 1

// derecha izquierda
// [2]
//  0

// derecha derecha
// [1]
//  0

// mezclar 
// [1 2]
//  0 1

// #1 end mezclar
// [1 2 3 4 7]
//  0 1 2 3 4

