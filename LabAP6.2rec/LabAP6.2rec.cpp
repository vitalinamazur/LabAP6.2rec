#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

void CreateArray(int* arr, int size, int Low, int High, int i = 0) {
    if (i < size) {
        arr[i] = Low + rand() % (High - Low + 1);
        CreateArray(arr, size, Low, High, i + 1); 
    }
}

void PrintArray(const int* arr, int size, int i = 0) {
    if (i < size) {
        cout << setw(4) << arr[i];
        PrintArray(arr, size, i + 1); 
    }
    else {
        cout << endl; 
    }
}

int FindMaxOddElement(const int* arr, int size, int i = 0, int maxOdd = INT_MIN, bool found = false) {
    if (i >= size) {
        return found ? maxOdd : -1; 
    }

    if (arr[i] % 2 != 0 && arr[i] > maxOdd) {  
        maxOdd = arr[i];
        found = true;
    }

    return FindMaxOddElement(arr, size, i + 1, maxOdd, found);
}

int main() {
    srand((unsigned)time(0));

    const int n = 10;
    int arr[n];

    int Low = 1, High = 50;

    CreateArray(arr, n, Low, High);
    cout << "Initial array: ";
    PrintArray(arr, n);

    int maxOdd = FindMaxOddElement(arr, n);

    if (maxOdd != -1) {
        cout << "The largest odd element: " << maxOdd << endl;
    }
    else {
        cout << "There are no odd elements in the array." << endl;
    }

    return 0;
}
