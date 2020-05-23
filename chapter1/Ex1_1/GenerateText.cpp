// Distributed under the MIT License.
// See LICENSE.txt for details.

// This program generates 1 million lines of text and writes the result to
// a file.

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main(void) {
  constexpr size_t number_of_lines = 1000000;
  const std::string file_name{"MillionLines.txt"};

  std::ofstream out_file;
  out_file.open(file_name);
  if (out_file.is_open()) {
    for (size_t i = 0; i < number_of_lines; ++i) {
      out_file << i << " = line number of sample text in MillionLines.txt\n";
    }
    out_file.close();
  } else {
    std::cerr << "Error: unable to open file.]\n";
    return -1;
  }
  return 0;
}
