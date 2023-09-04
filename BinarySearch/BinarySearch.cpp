

#include <iostream>
#include <vector>
using namespace std;


int binarySearch(int x, vector<int> elements, int l, int r) {
    int mid = l + (r - l) / 2;
    if (elements[mid] == x) {
        return mid;
    }
    if (elements[mid] < x) {
        binarySearch(x, elements, mid + 1, r);
    }
    else {
        binarySearch(x, elements, l, mid - 1);
    }
    return -1;
}

int main()
{
    std::cout << "Hello World!\n";
}

