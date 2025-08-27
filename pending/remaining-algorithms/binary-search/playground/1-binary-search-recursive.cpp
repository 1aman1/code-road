#include <iostream>
#include <algorithm>
#include <vector>
/*
RECURSIVE IMPLEMENTATION
*/

int binarySearch(const std::vector<int> &arr, int left, int right, const int &searchElement)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == searchElement)
      return mid;

    if (arr[mid] > searchElement)
      return binarySearch(arr, left, mid - 1, searchElement);

    return binarySearch(arr, mid + 1, right, searchElement);
  }

  return -1;
}

int main()
{
  std::vector<int> array{10, 20, 30, 40, 60, 70};

  int search_item = 20;

  binarySearch(array, 0, array.size(), search_item) != -1 ? std::cout << "found\n" : std::cout << "cant find\n";

  return 0;
}
