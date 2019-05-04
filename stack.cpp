#include "stack.hpp"

template <typename T>
void Stack<T>::push(const T value) {
  std::lock_guard<std::mutex> lock(mtx_);
  values_.push_back(value);
}

template <typename T>
T Stack<T>::pop() {
  std::lock_guard<std::mutex> lock(mtx_);
  T value = T();
  if (values_.empty()) {
    return value;
  }
  value = values_.back();
  values_.pop_back();
  return value;
}

template <typename T>
int Stack<T>::size() const {
  return values_.size();
}
