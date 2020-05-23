// Distributed under the MIT License.
// See LICENSE.txt for details.
#include <cstddef>
#include <iostream>

template <typename T>
class List {
 public:
  List() : size_(0) {}
  ~List() { delete[] data_; }

  size_t size() const noexcept { return size_; };

  T get(const size_t& i) const {
    if (i < size_) {
      return data_[i];
    } else {
      std::cerr << "Error: list index " << i << " is larger than the list size "
                << size_ << "\n";
      exit(-1);
    }
  }

  void set(const size_t& i, const T& element) {
    if (i < size_) {
      data_[i] = element;
    } else {
      std::cerr << "Error: list index " << i
                << " is out of bounds for list size " << size_ << "\n";
      exit(-1);
    }
  }

  void add(const size_t& i, const T& element) {
    if (i > size_) {
      std::cerr << "Error: cannot insert into list of size " << size_
                << " at position " << i << "\n";
      exit(-1);
    }
    size_ += 1;
    T* new_data = new T[size_];
    for (size_t j = 0; j < i; ++j) {
      new_data[j] = data_[j];
    }
    new_data[i] = element;
    if (size_ > i + 1) {
      for (size_t j = i + 1; j < size_; ++j) {
        new_data[j] = data_[j - 1];
      }
    }
    if (size_ > 1) {
      delete[] data_;
    }
    data_ = new_data;
  }

  void remove(const size_t& i) {
    if (i >= size_) {
      std::cerr << "Error: cannot remove from list of size " << size_
                << " at position " << i << "\n";
      exit(-1);
    }
    size_ -= 1;
    if (size_ > 0) {
      T* new_data = new T[size_];
      for (size_t j = 0; j < i; ++j) {
        new_data[j] = data_[j];
      }
      if (size_ > i) {
        for (size_t j = i; j < size_; ++j) {
          new_data[j] = data_[j + 1];
        }
      }
      delete[] data_;
      data_ = new_data;
    } else {
      delete[] data_;
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const List& list) noexcept {
    os << "[";
    for (size_t i = 0; i < list.size(); ++i) {
      os << list.get(i);
      if (i < list.size() - 1) {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }

 private:
  T* data_;
  size_t size_;
};

int main(void) {
  List<int> list{};
  std::cout << "Initial list: " << list << "\n";

  constexpr size_t length = 6;
  for (size_t i = 0; i < length; ++i) {
    list.add(i, static_cast<int>(i * i));
  }
  std::cout << "List after initialization: " << list << " (size " << list.size()
            << ")\n";

  list.remove(5);
  std::cout << "List after removing element 5: " << list << " (size "
            << list.size() << ")\n";
  list.remove(3);
  std::cout << "List after removing element 3: " << list << " (size "
            << list.size() << ")\n";

  list.set(1, 4444);
  std::cout << "List after setting element 1 to 4444: " << list << " (size "
            << list.size() << ")\n";

  constexpr size_t big_length = 400000;
  List<int> big_list{};
  for (size_t i = 0; i < big_length; ++i) {
    big_list.add(i, static_cast<int>(4 * i));
  }
  std::cout << "Created list of size " << big_list.size() << "\n";
  big_list.add(big_length - 2, 4444);
  std::cout << "Last 3 elements of list of size " << big_list.size()
            << " after changing element -2: ";
  for (size_t i = 0; i < 3; ++i) {
    std::cout << big_list.get(big_list.size() - 3 + i);
    if (i < 2) {
      std::cout << " ";
    } else {
      std::cout << "\n";
    }
  }

  return 0;
}