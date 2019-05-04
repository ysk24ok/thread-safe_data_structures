#ifndef THSAFE_DATA_STRUCT_
#define THSAFE_DATA_STRUCT_

#include <list>
#include <mutex>

template <typename T>
class Stack {
 public:
  Stack()
    : values_() {}
  void push(const T value);
  T pop();
  int size() const;

 private:
  std::list<T> values_;
  std::mutex mtx_;
};

#endif  // THSAFE_DATA_STRUCT_
