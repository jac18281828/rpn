#ifndef __DOUBLE_STACK_TYPE_H_
#define __DOUBLE_STACK_TYPE_H_ 1

#include <iostream>

#include "stacktype.h"
#include "errorhandler.h"

class DoubleStackType : public StackType {
private:
  double value;

  const ErrorHandler* eh;

  std::ostream& print(std::ostream &os) const;

public:
  DoubleStackType(const double value, const ErrorHandler *eh);

  double getValue(void) const;

  Type getType(void) const;

  void acosh(void);
  void acos(void);
  void abs(void);
  void alog(void);
  
  const StackType& operator+=(const StackType& s);
  const StackType& operator-=(const StackType& s);
  const StackType& operator*=(const StackType& s);
  const StackType& operator/=(const StackType& s);

};

#endif
