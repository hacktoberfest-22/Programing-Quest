// Sort an array in one swap whose two elements are swapped

// The idea is to start from the second array element and compare every element with its previous element. We take two pointers, x and y, to store the conflict’s location. If the previous element is greater than the current element, update x to the previous element index and y to the current element index. If we find that the previous element is greater than the current element, update y to the current element index. Finally, after we are done processing each adjacent pair of elements, swap the elements at index x and y.

#include <iostream>
#include <algorithm>
using namespace std;
 
void sortArray(int arr[], int n)
{
    // base case
    if (n <= 1) {
        return;
    }
 
    int x = -1, y = -1;
    int prev = arr[0];
 
    // process each pair of adjacent elements
    for (int i = 1; i < n; i++)
    {
        // if the previous element is greater than the current element
        if (prev > arr[i])
        {
            // first occurrence of conflict
            if (x == -1) {
                x = i - 1, y = i;
            }
            else {
                // second occurrence of conflict
                y = i;
            }
        }
        prev = arr[i];
    }
 
    // swap the elements at index `x` and `y`
    swap(arr[x], arr[y]);
}
 
int main()
{
    // int arr[] = { 3, 8, 6, 7, 5, 9 };
    int arr[] = { 3, 5, 6, 9, 8, 7 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sortArray(arr, n);
 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}
