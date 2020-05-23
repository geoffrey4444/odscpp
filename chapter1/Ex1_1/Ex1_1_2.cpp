// Distributed under the MIT License.
// See LICENSE.txt for details.

// Ex 1.1 part 1.
// This program reads in a file, line by line, 50 lines at a time. Each
// chunk of 50 lines is output in reverse order.

#include <cstddef>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

int pop_all_and_write(std::stack<std::string>& lines,
                      const std::string& file_name) {
  std::fstream out_file;
  out_file.open(file_name, std::ios::app);
  if (out_file.is_open()) {
    while (lines.size() > 0) {
      out_file << lines.top() << "\n";
      lines.pop();
    }
    out_file.close();
  } else {
    std::cerr << "Error: cannot open file " << file_name << "\n";
    return -2;
  }
  return 0;
}

int main(void) {
  const std::string in_file_name{"MillionLines.txt"};
  const std::string out_file_name{"MillionLines_Reversed_50.txt"};
  constexpr size_t lines_per_chunk = 50;
  int error = 0;

  std::stack<std::string> lines{};

  std::fstream in_file;
  in_file.open(in_file_name, std::ios::in);
  if (in_file.is_open()) {
    std::string line{};
    while (getline(in_file, line)) {
      lines.push(line);
      if (lines.size() == 50) {
        error = pop_all_and_write(lines, out_file_name);
        if (error != 0) {
          return error;
        }
      }
    }
    in_file.close();
    if (lines.size() > 0) {
      error = pop_all_and_write(lines, out_file_name);
      if (error != 0) {
        return error;
      }
    }
  } else {
    std::cerr << "Error: cannot open file " << in_file_name << "\n";
    return -1;
  }

  return 0;
}
