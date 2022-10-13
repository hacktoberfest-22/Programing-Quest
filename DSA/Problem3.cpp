// Find the index of 0 to be replaced to get the maximum length sequence of continuous ones

//We can efficiently solve this problem in linear time and constant space. The idea is to traverse the given array and maintain an index of the previous zero encountered. We can then easily find out the total number of 1’s between the current zero and the last zero for each subsequent zeroes. For each element, check if the maximum sequence of continuous 1’s ending at that element (including the last zero, which is now replaced by 1) exceeds the maximum sequence found so far. If yes, update the maximum sequence to the current sequence length and index of optimal zero and index the last zero encountered.

// The algorithm can be implemented as follows in C, Java, and Python:

#include <stdio.h>
 
// Find the index of 0 to replace with 1 to get the maximum sequence
// of continuous 1's
int findIndexofZero(int arr[], int n)
{
    int max_count = 0;          // stores maximum number of 1's (including zero)
    int max_index = -1;         // stores index of 0 to be replaced
 
    int prev_zero_index = -1;   // stores index of previous zero
    int count = 0;              // stores current count of zeros
 
    // consider each index `i` in the array
    for (int i = 0; i < n; i++)
    {
        // if the current element is 1
        if (arr[i] == 1) {
            count++;
        }
        // if the current element is 0
        else {
            // reset count to 1 + number of ones to the left of current 0
            count = i - prev_zero_index;
 
            // update `prev_zero_index` to the current index
            prev_zero_index = i;
        }
 
        // update maximum count and index of 0 to be replaced if required
        if (count > max_count)
        {
            max_count = count;
            max_index = prev_zero_index;
        }
    }
 
    // return index of 0 to be replaced or -1 if the array contains all 1's
    return max_index;
}
 
int main(void)
{
    int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int index = findIndexofZero(arr, n);
 
    if (index != -1) {
        printf("Index to be replaced is %d", index);
    }
    else {
        printf("Invalid input");
    }
 
    return 0;
}
