#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& Array, int target) {
    int left = 0;               
    int right = Array.size() - 1;  

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        int midValue = Array[mid]; 
 
        if (midValue == target) {
            return mid; 
        }
        
        else if (midValue > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> Array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    
    int result = binarySearch(Array, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
