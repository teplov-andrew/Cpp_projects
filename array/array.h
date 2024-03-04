#ifndef ARRAY__ARRAY_H_
#define ARRAY__ARRAY_H_

#include <stdexcept>

template<typename T>
void MySwap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template<typename T, size_t N>
class Array {
 public:
  T numbers[N];

  T &operator[](size_t idx) {
    return numbers[idx];
  };

  const T &operator[](size_t idx) const {
    return numbers[idx];
  }

  T &At(size_t idx) {
    if (idx >= N) {
      throw ArrayOutOfRange();
    }
    return numbers[idx];
  }

  const T &At(size_t idx) const {
    if (idx >= N) {
      throw ArrayOutOfRange();
    }
    return numbers[idx];
  }

  T &Front() {
    return numbers[0];
  }

  const T &Front() const {
    return numbers[0];
  }

  T &Back() {
    return numbers[N - 1];
  }

  const T &Back() const {
    return numbers[N - 1];
  }

  T *Data() {
    return numbers;
  }

  const T *Data() const {
    return numbers;
  }

  [[nodiscard]] constexpr size_t Size() const {
    return N;
  }

  [[nodiscard]] constexpr bool Empty() const {
    return N == 1;
  }

  void Fill(const T &value) {
    for (size_t i = 0; i < N; ++i) {
      numbers[i] = value;
    }
  }

  void Swap(Array<T, N> &other) {
    for (size_t i = 0; i < N; ++i) {
      MySwap(numbers[i], other.numbers[i]);
    }
  }

};

#endif //ARRAY__ARRAY_H_
