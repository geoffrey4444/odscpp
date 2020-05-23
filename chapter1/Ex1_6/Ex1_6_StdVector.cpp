// Distributed under the MIT License.
// See LICENSE.txt for details.
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::string string_from_vector(const std::vector<T>& list) {
  std::string string = "[";
  for (size_t i = 0; i < list.size(); ++i) {
    string += std::to_string(list[i]);
    if (i < list.size() - 1) {
      string += ", ";
    }
  }
  string += "]";
  return string;
}

int main(void) {
  std::vector<int> list{};
  std::cout << "Initial list: " << string_from_vector(list) << "\n";

  constexpr size_t length = 6;
  for (size_t i = 0; i < length; ++i) {
    list.insert(list.begin() + i, static_cast<int>(i * i));
  }
  std::cout << "List after initialization: " << string_from_vector(list)
            << " (size " << list.size() << ")\n";

  list.erase(list.begin() + 5);
  std::cout << "List after removing element 5: " << string_from_vector(list)
            << " (size " << list.size() << ")\n";
  list.erase(list.begin() + 3);
  std::cout << "List after removing element 3: " << string_from_vector(list)
            << " (size " << list.size() << ")\n";

  list[1] = 4444;
  std::cout << "List after setting element 1 to 4444: "
            << string_from_vector(list) << " (size " << list.size() << ")\n";

  constexpr size_t big_length = 400000;
  std::vector<int> big_list{};
  for (size_t i = 0; i < big_length; ++i) {
    big_list.insert(big_list.begin() + i, static_cast<int>(4 * i));
  }
  std::cout << "Created list of size " << big_list.size() << "\n";
  big_list.insert(big_list.end() - 2, 4444);
  std::cout << "Last 3 elements of list of size " << big_list.size()
            << " after changing element -2: ";
  for (size_t i = 0; i < 3; ++i) {
    std::cout << big_list[big_list.size() - 3 + i];
    if (i < 2) {
      std::cout << " ";
    } else {
      std::cout << "\n";
    }
  }

  return 0;
}