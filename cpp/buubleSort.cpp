#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    bool swapped;
    size_t n = arr.size();
    
    for (size_t i = 0; i < n - 1; i++) {
        swapped = false;
        
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    bubbleSort(arr);

    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
