#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int MERGESORT(int arr[], int temp[], int l, int r);
int merge(int arr[], int temp[], int l, int mid, int r);

int mergeSort(int arr[], int array_size) {
    int temp[array_size];
    return MERGESORT(arr, temp, 0, array_size - 1);
}

int MERGESORT(int arr[], int temp[], int l, int r) {
    int mid, inv_count = 0;
    if (r > l) {
        mid = (r + l) / 2;
        inv_count = MERGESORT(arr, temp, l, mid);
        inv_count += MERGESORT(arr, temp, mid + 1, r);

        inv_count += merge(arr, temp, l, mid + 1, r);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int l, int mid, int r) {



    int i = l, j = mid, k = l, inv_count = 0;

    while ((i <= mid - 1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i);
        }
    }


    while (i <= mid - 1)
        temp[k++] = arr[i++];


    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    return inv_count;
}
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0 ;i<n ;i++)
        cin>>arr[i];
    cout << mergeSort(arr,n) << endl ;
}

