#include <iostream>
 
using namespace std;
 
// Define the dimensions of the matrix
const int N = 3;
const int M = 3;
 
// Recursive function to traverse the matrix
void traverse(int arr[][M], int i, int j)
{
    // If the current position is the bottom-right corner of
    // the matrix
    if (i == N - 1 && j == M - 1) {
        // Print the value at that position
        printf("%d ",arr[i][j]);
        // End the recursion
        return;
    }
 
    // Print the value at the current position
    cout << arr[i][j] << ", ";
 
    // If the end of the current row has not been reached
    if (j < M - 1) {
        // Move right
        traverse(arr, i, j + 1);
    }
    // If the end of the current column has been reached
    else if (i < N - 1) {
        // Move down to the next row
        traverse(arr, i + 1, 0);
    }
}
 
int main()
{
    // Define the matrix
    int arr[N][M]
        = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
 
    // Start the traversal from the top-left corner of the
    // matrix
    traverse(arr, 0, 0);
 
    return 0;
}
