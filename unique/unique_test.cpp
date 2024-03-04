#include <array>
#include <cassert>

#include "unique.h"


template <class T, size_t M>
void Equal(const T* actual, std::array<T, M> expected) {
  for (size_t i = 0; i < M; ++i) {
    assert(actual[i] == expected[i]);
  }
}

void TestUnique() {
  int a[]{1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 6, 7};

  assert(Unique(a, a) == a);
  Equal(a, std::array{1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 6, 7});

  assert(Unique(a, a + 12) == a + 7);
  Equal(a, std::array{1, 2, 3, 4, 5, 6, 7});

  {
    const auto size = 1'000'000;
    auto large = new int[size];
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < size / 10; ++j) {
        large[i * size / 10 + j] = i;
      }
    }
    assert(Unique(large, large + size) == large + 10);
    Equal(large, std::array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    delete[] large;
  }
}

int main() {
  TestUnique();
}

