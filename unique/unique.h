#ifndef UNIQUE__UNIQUE_H_
#define UNIQUE__UNIQUE_H_

template<typename Posled>
Posled Unique(Posled start, Posled end) {
  if (start == end) {
    return start;
  }

  Posled cur = start;
  while (++start != end) {
    if (*cur != *start) {
      ++cur;
      *cur = *start;
    }
  }
  ++cur;
  return cur;
}

#endif //UNIQUE__UNIQUE_H_
