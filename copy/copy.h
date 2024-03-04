#ifndef COPY__COPY_H_
#define COPY__COPY_H_

template<typename FirstPosl, typename SecondPosl>
SecondPosl Copy(FirstPosl scr_begin, FirstPosl scr_end, SecondPosl dest) {
  while (scr_begin != scr_end) {
    *dest = *scr_begin;
    ++scr_begin;
    ++dest;
  }
  return dest;
}

template<typename BackwardFirstPosl, typename BackwardSecondPosl>
BackwardSecondPosl CopyBackward(BackwardFirstPosl scr_begin, BackwardFirstPosl scr_end, BackwardSecondPosl dest) {
  while (scr_end != scr_begin) {
    --scr_end;
    --dest;
    *dest = *scr_end;
  }
  return dest;
}

#endif //COPY__COPY_H_
