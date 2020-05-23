// Distributed under the MIT License.
// See LICENSE.txt for details.

#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>

std::stack<int> make_stack_of_consecutive_integers(int max) {
  std::stack<int> stack{};
  for (int i = 0; i < max; ++i) {
    stack.push(i);
  }
  return stack;
}

template <typename T>
void pop_all_and_print(std::stack<T> stack) {
  while (stack.size() > 0) {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << "\n";
}

int main(void) {
  constexpr size_t stack_size = 4;

  // Print the initial stack
  pop_all_and_print(make_stack_of_consecutive_integers(stack_size));

  // Fill a stack with 44 unique numbers
  std::stack<int> stack = make_stack_of_consecutive_integers(stack_size);
  std::queue<int> queue{};

  // Using only push() and pop() operations on the stack and a queue,
  // reverse the order of all of the elements in the stack
  for (size_t i = 0; i < stack_size; ++i) {
    queue.push(stack.top());
    stack.pop();
  }
  for (size_t i = 0; i < stack_size; ++i) {
    stack.push(queue.front());
    queue.pop();
  }

  // Print the reversed stack
  pop_all_and_print(stack);

  return 0;
}