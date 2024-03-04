#include <iostream>
#include <array>
#include <cassert>

#include "reverse.h"
//#include "solution.h"

template<class T, int N>
void Equal(const T (&actual)[N], std::array<T, N> expected) {
  for (int i = 0; i < N; ++i) {
    assert(actual[i] == expected[i]);
  }
}

void TestReverse() {
  int a[]{1, 2, 3, 4, 5};
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Reverse(a, a);
  Equal(a, {1, 2, 3, 4, 5});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Reverse(a + 5, a + 5);
  Equal(a, {1, 2, 3, 4, 5});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Reverse(a, a + 5);
  Equal(a, {5, 4, 3, 2, 1});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Reverse(a + 1, a + 4);
  Equal(a, {5, 2, 3, 4, 1});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";
  std::cout << "\n";
}

void TestRotate() {
  int a[]{1, 2, 3, 4, 5};
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Rotate(a, a, a);
  Equal(a, {1, 2, 3, 4, 5});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Rotate(a, a, a + 5);
  Equal(a, {1, 2, 3, 4, 5});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Rotate(a, a + 5, a + 5);
  Equal(a, {1, 2, 3, 4, 5});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  Rotate(a, a + 3, a + 5);
  Equal(a, {4, 5, 1, 2, 3});
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  {
    const auto size = 1'000'000;
    auto large = new int[size];

    for (int i = 0; i < size; ++i) {
      large[i] = i;
    }
    const auto mid = size / 10;
    Rotate(large, large + mid, large + size);
    for (int i = mid; i < size; ++i) {
      assert(large[i - mid] == i);
    }
    for (int i = 0; i < mid; ++i) {
      assert(large[size - mid + i] == i);
    }

    delete[] large;
  }
  for (auto el : a) {
    std::cout << el << " ";
  }
  std::cout << "\n";
}

int main() {
  TestReverse();
  TestRotate();
}

