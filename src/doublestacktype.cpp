#include <cmath>

#include "doublestacktype.h"

using namespace std;

DoubleStackType::DoubleStackType(const double p, const ErrorHandler *eh) : value(p) {
  this->eh = eh;
}

Type DoubleStackType::getType(void) const {
  return DOUBLE;
}

double DoubleStackType::getValue(void) const {
  return value;
}

void DoubleStackType::acosh(void) {
  value = ::acosh(value);
}

void DoubleStackType::acos(void) {
  value = ::acos(value);
}

void DoubleStackType::abs(void) {
  value = ::fabs(value);
}

void DoubleStackType::alog(void) {
  value = ::pow(10.0, value);
}

const StackType& DoubleStackType::operator+=(const StackType& s) {
  switch(s.getType()) {
  case DOUBLE:
    {
      const DoubleStackType& d = dynamic_cast<const DoubleStackType&>(s);
      value += d.value;
      break;
    }
  default:
    {
      eh->badargument("+");
      break;
    }
  }
  return *this;
}

const StackType& DoubleStackType::operator-=(const StackType& s) {
  switch(s.getType()) {
  case DOUBLE:
    {
      const DoubleStackType& d = dynamic_cast<const DoubleStackType&>(s);
      value -= d.value;
      break;
    }
  default:
    {
      eh->badargument("-");
      break;
    }
  }
  return *this;
}

const StackType& DoubleStackType::operator*=(const StackType& s) {
  switch(s.getType()) {
  case DOUBLE:
    {
      const DoubleStackType& d = dynamic_cast<const DoubleStackType&>(s);
      value *= d.value;
      break;
    }
  default:
    {
      eh->badargument("*");
      break;
    }
  }
  return *this;
}

const StackType& DoubleStackType::operator/=(const StackType& s) {
  switch(s.getType()) {
  case DOUBLE:
    {
      const DoubleStackType& d = dynamic_cast<const DoubleStackType&>(s);
      value /= d.value;
      break;
    }
  default:
    {
      eh->badargument("-");
      break;
    }
  }
  return *this;
}

std::ostream& DoubleStackType::print(std::ostream& os) const {
  os << value;
  return os;
}
