// Distributed under the MIT License.
// See LICENSE.txt for details.

// Ex 1.1 part 1.
// This program reads in a file, line by line, and then writes the lines in
// reverse order.

#include <cstddef>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

int main(void) {
  const std::string in_file_name{"MillionLines.txt"};
  const std::string out_file_name{"MillionLines_Reversed.txt"};

  std::stack<std::string> lines{};

  std::fstream in_file;
  in_file.open(in_file_name, std::ios::in);
  if (in_file.is_open()) {
    std::string line{};
    while (getline(in_file, line)) {
      lines.push(line);
    }
    in_file.close();
  } else {
    std::cerr << "Error: cannot open file " << in_file_name << "\n";
    return -1;
  }

  std::fstream out_file;
  out_file.open(out_file_name, std::ios::out);
  if (out_file.is_open()) {
    while (lines.size() > 0) {
      out_file << lines.top() << "\n";
      lines.pop();
    }
    out_file.close();
  } else {
    std::cerr << "Error: cannot open file " << out_file_name << "\n";
    return -2;
  }

  return 0;
}
