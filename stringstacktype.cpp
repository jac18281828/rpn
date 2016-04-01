#include <sstream>

#include "doublestacktype.h"
#include "stringstacktype.h"
#include "errorhandler.h"

StringStackType::StringStackType(const char* s, const ErrorHandler *eh) : value(s) {
  this->eh = eh;
}

const std::string &StringStackType::getValue(void) const {
  return value;
}

Type StringStackType::getType(void) const {
  return STR;
}

void StringStackType::acosh(void) {
  eh->badargument("ACOSH");
}

void StringStackType::acos(void) {
  eh->badargument("ACOS");
}

void StringStackType::abs(void) {
  eh->badargument("ABS");
}

void StringStackType::alog(void) {
  eh->badargument("ALOG");
}
  
const StackType& StringStackType::operator+=(const StackType& s) {
  switch(s.getType()) {
  case STR:
    {
      const StringStackType& str = dynamic_cast<const StringStackType&>(s);
      value.append(str.value);
      break;
    }
  case DOUBLE:
    {
      const DoubleStackType& dbl = dynamic_cast<const DoubleStackType&>(s);
      std::ostringstream strs;
      strs << dbl.getValue();
      value.append(strs.str());
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

const StackType& StringStackType::operator-=(const StackType& s) {
  eh->badargument("-");
  return *this;
}

const StackType& StringStackType::operator*=(const StackType& s) {
  eh->badargument("*");
  return *this;
}

const StackType& StringStackType::operator/=(const StackType& s) {
  eh->badargument("/");
  return *this;
}

