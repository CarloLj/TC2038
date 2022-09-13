#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<double> &lista, int start, int middle, int end){
    int leftIndex = start;
    int rightIndex = middle+1;
    int temporalIndex = 0;
    vector<double> auxiliarList;
    
    while(leftIndex <= middle && rightIndex <= end){
        if(lista[leftIndex] > lista[rightIndex]){
            auxiliarList.push_back(lista[leftIndex]);
            leftIndex++;
            temporalIndex++;
        }else{
            auxiliarList.push_back(lista[rightIndex]);
            rightIndex++;
            temporalIndex++;
        }
    }

    for (int i = leftIndex; i <= middle ; i++) {
        auxiliarList.push_back(lista[i]);
        temporalIndex++;
    } 

    for (int i = rightIndex; i <= end ; i++) {
        auxiliarList.push_back(lista[i]);
        temporalIndex++;
    }

    for (int i = 0; i <= temporalIndex-1; i++) {
        lista[start+i] = auxiliarList[i];
    }
}

void mergeSort(vector<double> &lista, int start, int end) {
    if(start < end) {
        int middle = (start+end) / 2;
        mergeSort(lista, start, middle);
        mergeSort(lista, middle+1, end);
        merge(lista, start, middle, end);
    }
    return;
}

int main(){
    int n;
    cout << "Enter the number of values to order" << endl;
    cin >> n;
    vector<double> numbers;

    if (n <=0) {
        cout << "Please enter a value greater than 0" << endl;
        return 0;
    }

    for(int i = 0 ; i < n ; i++) {
        double number;
        cout << "Enter number: " << i+1 << endl;
        cin >> number;
        numbers.push_back(number);
    }

    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Numbers before ordering" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0 ; i < n ; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;

    mergeSort(numbers, 0 , n-1);

    cout << "-----------------------------------------" << endl;
    cout << "Numbers after ordering (descending order)" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0 ; i < n ; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
}