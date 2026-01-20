#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int st, int end) {
    int pivot = arr[end];   
    int i = st - 1;         

    for (int j = st; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;           
}


void quickSort(int arr[], int st, int end) {
    if (st < end) {
        int pi = partition(arr, st, end);

        quickSort(arr, st, pi - 1);   
        quickSort(arr, pi + 1, end);  
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    quickSort(arr, 0, n - 1);

    cout<<endl;

    cout << "Sorted array:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
