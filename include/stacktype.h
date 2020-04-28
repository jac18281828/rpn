#ifndef __STACK_TYPE_H_
#define __STACK_TYPE_H_ 1

typedef enum {
  DOUBLE,
  STR
} Type;


class StackType {
protected:
  virtual std::ostream& print(std::ostream &os) const = 0;

public:

  virtual Type getType(void) const = 0;
  
  virtual void acosh(void) = 0;
  virtual void acos(void) = 0;
  virtual void abs(void) = 0;
  virtual void alog(void) = 0;

  friend std::ostream& operator<<(std::ostream& os, const StackType &s);

  virtual const StackType& operator+=(const StackType& s) = 0;
  virtual const StackType& operator-=(const StackType& s) = 0;
  virtual const StackType& operator*=(const StackType& s) = 0;
  virtual const StackType& operator/=(const StackType& s) = 0;

};


inline std::ostream& operator<<(std::ostream& os, const StackType &s) {
  return s.print(os);
}

#endif
