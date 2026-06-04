////////////////////////////////////////////////////////////////////////
//
//                      BUBBLE SORT ALGORITHM
//   ---------------------------------------------------------------      
//   Description: Sorts a collection of elements in ascending order
//   Time Complexity: O(n^2)
//   How can this be improved: Implement a check to see if a value
//                             is swapped. When there are no more 
//                             swaps needed, the sorting is complete 
//
////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <array>
#include <algorithm>

template <typename T, std::size_t N>
void bubble_sort(std::array<T, N> &some_array)
{
    for(size_t i = 0; i < N; ++i)
    {
        for(size_t j = 0; j < N - 1; ++j)
            if (some_array[j] > some_array[j + 1])
                std::swap(some_array[j], some_array[j + 1]);
    }
}

template <typename T, std::size_t N>
void print_array(const std::array<T, N> some_array) 
{
    for (size_t i = 0; i < N; ++i)
        std::cout << some_array[i] << (i == (N - 1) ? "" : ", ");
}

int main() 
{
    std::array<int, 10> nums = {4,3,1,7,5,6,7,9,8,9};

    std::cout << "array before bubble_sort():\n";
    print_array(nums);

    bubble_sort(nums);

    std::cout << "\n\narray after buuble_sort():\n";
    print_array(nums);
}