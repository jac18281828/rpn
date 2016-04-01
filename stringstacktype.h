#ifndef __STRING_STACK_TYPE_H_
#define __STRING_STACK_TYPE_H_ 1

#include <iostream>

#include "stacktype.h"
#include "errorhandler.h"

class StringStackType : public StackType {
private:
  std::string value;

  const ErrorHandler* eh;

  std::ostream& print(std::ostream &os) const;

public:
  StringStackType(const char* value, const ErrorHandler *eh);

  Type getType() const;

  const std::string &getValue(void) const;

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
