//
// Created by Andrew Teplov on 18.02.2024.
//
#include "rational.h"
#include <numeric>
#include <sstream>
#include <string>

Rational::Rational() : numerator_(0), denominator_(1) {}
Rational::Rational(int n) : numerator_(n), denominator_(1) {} // NOLINT
Rational::Rational(int n, int d) : numerator_(n), denominator_(d) {
  if (denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  Socr();
}

int Rational::GetNumerator() const {
  return numerator_;
}
int Rational::GetDenominator() const {
  return denominator_;
}
void Rational::SetNumerator(int n) {
  numerator_ = n;
  Socr();
}
void Rational::SetDenominator(int d) {
  if (d == 0) {
    throw RationalDivisionByZero{};
  }
  denominator_ = d;
  Socr();
}
Rational Rational::operator+(const Rational &other) const {
  return {numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_};
}
Rational Rational::operator-(const Rational &other) const {
  return {numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_};
}
Rational Rational::operator*(const Rational &other) const {
  return {numerator_ * other.numerator_, denominator_ * other.denominator_};
}
Rational Rational::operator/(const Rational &other) const {
  if (other.numerator_ == 0) {
    throw RationalDivisionByZero{};
  }
  return {numerator_ * other.denominator_, denominator_ * other.numerator_};
}
Rational &Rational::operator+=(const Rational &other) {
  *this = *this + other;
  return *this;
}
Rational &Rational::operator-=(const Rational &other) {
  *this = *this - other;
  return *this;
}
Rational &Rational::operator*=(const Rational &other) {
  *this = *this * other;
  return *this;
}
Rational &Rational::operator/=(const Rational &other) {
  *this = *this / other;
  return *this;
}
Rational Rational::operator+() const {
  return *this;
}
Rational Rational::operator-() const {
  return {-numerator_, denominator_};
}
Rational &Rational::operator++() {
  numerator_ += denominator_;
  return *this;

}
Rational Rational::operator++(int) {
  Rational temporary = *this;
  ++(*this);
  return temporary;
}
Rational &Rational::operator--() {
  numerator_ -= denominator_;
  return *this;
}
Rational Rational::operator--(int) {
  Rational temporary = *this;
  --(*this);
  return temporary;
}
bool Rational::operator==(const Rational &other) const {
  return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}
bool Rational::operator!=(const Rational &other) const {
  return !(*this == other);
}
bool Rational::operator<(const Rational &other) const {
  return numerator_ * other.denominator_ < other.numerator_ * denominator_;
}
bool Rational::operator>(const Rational &other) const {
  return other < *this;
}
bool operator<(int value, const Rational &rational) {
  return Rational(value) < rational;
}

bool operator>(int value, const Rational &rational) {
  return Rational(value) > rational;
}
bool Rational::operator<=(const Rational &other) const {
  return !(*this > other);
}
bool Rational::operator>=(const Rational &other) const {
  return !(*this < other);
}

std::istream &operator>>(std::istream &in, Rational &r) {
  std::string s;
  in >> s;
  std::istringstream iss(s);
  int n = 0;
  int d = 1;
  if (std::getline(iss, s, '/')) {
    n = std::stoi(s);
    if (std::getline(iss, s)) {
      d = std::stoi(s);
      if (d == 0) {
        throw RationalDivisionByZero{};
      }
    }
  }
  r = Rational(n, d);
  return in;
}

std::ostream &operator<<(std::ostream &out, const Rational &r) {
  if (r.GetDenominator() == 1) {
    out << r.GetNumerator();
  } else if (r.GetNumerator() == 0) {
    out << 0;
  } else {
    out << r.GetNumerator() << '/' << r.GetDenominator();
  }
  return out;
}

void Rational::Socr() {
  int gcd = std::gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;
  if (denominator_ < 0) {
    numerator_ = -numerator_;
    denominator_ = -denominator_;
  }
}


