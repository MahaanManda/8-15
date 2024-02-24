
/*
    Write a program that prompts the user to enter 50 integers and stores them in an array.
    The program then determines and outputs which numbers in the array are the sum of two other array elements.
    If an array element is the sum of two other array elements, then for this array element,
    the program should output all such pairs.
 */

#include <iostream>

using namespace std;

//functions
void selectionSort(int arr[], int n) {
    int i, j, minIndex, tmp;    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

void findSumPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) { // Start from j + 1
                if (arr[i] + arr[j] == arr[k]) {
                    cout << "Array element " << arr[k] << " is the sum of " << arr[i] << " and " << arr[j] << endl;
                }
            }
        }
    }
}

int main() {
    int array_size = 50;
    int user_input[array_size];
    cout << "Please enter 50 integers: ";

    for (int i = 0; i < array_size; i++) {
        cin >> user_input[i];
    }
    /*first sorting the array before determining the array elements that 
    are sum of two other elements. Use selection sort algorithm*/
    
    selectionSort(user_input, array_size);
    findSumPairs(user_input, array_size);




    return 0;
}
