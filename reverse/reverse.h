#ifndef REVERSE__REVERSE_H_
#define REVERSE__REVERSE_H_

template<typename T>
void MySwap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template<typename Posled>
void Reverse(Posled start, Posled end) {
  while ((start != end) && (start != --end)) {
    MySwap(*start, *end);
    ++start;
  }
}

template<typename Posled>
void Rotate(Posled start, Posled mid, Posled end) {
  Reverse(start, mid);
  Reverse(mid, end);
  Reverse(start, end);
}
#endif //REVERSE__REVERSE_H_
