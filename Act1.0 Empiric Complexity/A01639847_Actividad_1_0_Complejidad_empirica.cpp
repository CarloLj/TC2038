#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std; 

int m[10] = {10, 50, 100, 150, 300, 1000, 5000, 10000, 20000, 50000};

int getIntegerVectorSum(vector<int> vect) {
  int vectorSum = 0;

  for (auto &n : vect) {
    vectorSum += n;
  }

  return vectorSum;
}

void printIntegerVectorSumAndTimeSpent(vector<int> vect) {
    if (vect.size() > 0) {
        auto start = chrono::high_resolution_clock::now();

        int result = getIntegerVectorSum(vect);

        auto end = chrono::high_resolution_clock::now();
        
        // Calculating total time taken to sum the elements in the vector.
        double time_taken = 
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        cout << "-> Array size: " << vect.size() << endl;
        cout << "-> Sum results: " << result << endl;
        cout << "-> Time spent to perform sum: " << time_taken << setprecision(9) << " nanoseconds " << endl;
        cout << "------------------------------" << endl;
    } else {
        cout << "-> Failed to open file / file without valid data"<< endl;
        cout << "------------------------------" << endl;
    }
}

vector<int> getPredefinedSizeRandomIntegersVector(int n) {
  vector<int> vect(n);

  for (int i=0 ; i<n ; i++) {
    vect[i] = rand() % 100;
  }

  return vect;
}

vector<int> getNumberVectorFromFile(string fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Could not open the file - '" 
            << fileName << "'" << endl; 
    }
    int number;
    vector<int> numberVec;
    while (inputFile >> number) {
        numberVec.push_back(number);
    }
    return numberVec;
}

int main(int argc, char *argv[]) 
{ 
    vector<vector<int>> numberVectors;
    
    ios_base::sync_with_stdio(false);
    // En caso de que recibamos un numero de argumentos de inicio de programa
    // mayor a 1 (Es decir que hay algo mas aparte del nombre del programa)
    // nos iremos por la opcion de seleccionar datos al interior de un archivo
    // de texto para poblar vectores para la sumatoria de datos, de lo contrario
    // crearemos vectores de distintos tamanios con valores random.
    if(argc > 1) {
        cout << "Detected command-line arguments passed by the user" << endl;
        cout << "Searching for files with those names..." << endl;
        for (int i = 1; i < argc; i++) {
            cout << '[' << i <<']' << argv[i] << ' ';
            numberVectors.push_back(getNumberVectorFromFile(argv[i]));
        }
        cout << endl << endl;
    } else {
        cout << "Did not detect command-line arguments passed by the user" << endl;
        cout << "Creating random vectors of different sizes..." << endl << endl;
        for (auto &size : m) {
            vector<int> vect = getPredefinedSizeRandomIntegersVector(size);
            numberVectors.push_back(vect);
        }
    }
    int index = 1;
    for (auto &vect : numberVectors) {
        cout << '[' << index << ']' << endl;
        printIntegerVectorSumAndTimeSpent(vect);
        index++;
    }

    return 0; 
} 