#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include "../stack.cpp"

void th_push(std::shared_ptr<Stack<std::string>> p_stack, const int n) {
  int counter = 0;
  while (counter < n) {
    p_stack->push("abc");
    counter++;
  }
}

void th_pop(std::shared_ptr<Stack<std::string>> p_stack, const int n) {
  int counter = 0;
  while (counter < n) {
    p_stack->pop();
    counter++;
  }
}

int main() {
  std::shared_ptr<Stack<std::string>> p_stack(new Stack<std::string>());
  std::cout << "stack size (before): " << p_stack->size() << std::endl;

  const int num_threads = 3;
  const int n = 10000;
  std::vector<std::thread> threads(num_threads);
  // push
  for (int i = 0; i < num_threads; i++) {
    threads[i] = std::thread(th_push, p_stack, n);
  }
  for (auto& th: threads) {
    th.join();
  }
  std::cout << "stack size (after push): " << p_stack->size() << std::endl;
  // pop
  for (int i = 0; i < num_threads; i++) {
    threads[i] = std::thread(th_pop, p_stack, n);
  }
  for (auto& th: threads) {
    th.join();
  }
  std::cout << "stack size (after pop): " << p_stack->size() << std::endl;
}
