//
// Created by Andrew Teplov on 18.02.2024.
//

#ifndef RATIONAL__RATIONAL_H_
#define RATIONAL__RATIONAL_H_

#include <iostream>
#include <stdexcept>

class Rational {
 private:
  int numerator_ = 0;
  int denominator_ = 0;
  void Socr();

 public:
  Rational();
  Rational(int n); // NOLINT
  Rational(int n, int d);

  int GetNumerator() const;
  int GetDenominator() const;

  void SetNumerator(int n);
  void SetDenominator(int d);

  Rational operator+(const Rational &other) const;
  Rational operator-(const Rational &other) const;
  Rational operator*(const Rational &other) const;
  Rational operator/(const Rational &other) const;
  Rational &operator+=(const Rational &other);
  Rational &operator-=(const Rational &other);
  Rational &operator*=(const Rational &other);
  Rational &operator/=(const Rational &other);

  Rational operator+() const;
  Rational operator-() const;
  Rational &operator++();
  Rational operator++(int);
  Rational &operator--();
  Rational operator--(int);

  bool operator==(const Rational &other) const;
  bool operator!=(const Rational &other) const;

  bool operator<(const Rational &other) const;
  bool operator>(const Rational &other) const;

  friend bool operator<(int value, const Rational &rational);
  friend bool operator>(int value, const Rational &rational);

  bool operator<=(const Rational &other) const;
  bool operator>=(const Rational &other) const;

  friend std::istream &operator>>(std::istream &in, Rational &r);
  friend std::ostream &operator<<(std::ostream &out, const Rational &r);

};

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

#endif //RATIONAL__RATIONAL_H_

