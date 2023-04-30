#include <iostream>
#include <limits>
#include <vector>

void Print(std::vector<int> arr) {
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
}

std::vector<int> Kadane(std::vector<int> arr) {
    if (!arr.size())
        return { 0 };
    std::vector<int> result;
    int maxSoFar = std::numeric_limits<int>::min();
    int maxEndingHere = 0;
    int start = 0, end = 0;
    int beg = 0;
    for (int i = 0; i < arr.size();++i) {
        maxEndingHere += arr[i];
        if (maxEndingHere < arr[i]) {
            maxEndingHere = arr[i];
            beg = i;
        }
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = beg;
            end = i;
        }
    }
    for (int i = start; i <= end; ++i)
        result.push_back(arr[i]);
    return result;
}

int main()
{
    Print(Kadane({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
}

