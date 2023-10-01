#include <iostream>
#include <vector>

using namespace std;


int linearSearch(vector<int>& array, int target) {
    int arraySize = array.size();

    for (int currentIndex = 0; currentIndex < arraySize; ++currentIndex) {
        int currentValue = array[currentIndex];

        if (currentValue == target) {
            return currentIndex; 
        }
    }
    return -1;
}

int main() {
    vector<int> array = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;

    int result = linearSearch(array, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
