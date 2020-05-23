// Distributed under the MIT License.
// See LICENSE.txt for details.

// This program generates 1 million lines of text and writes the result to
// a file.

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main(void) {
  constexpr size_t number_of_chars = 100000000 / 2;
  const std::string file_name_matching{"LongMatching.txt"};
  const std::string file_name_not_matching{"LongNotMatching.txt"};

  std::ofstream out_file_matching;
  std::ofstream out_file_not_matching;
  out_file_matching.open(file_name_matching);
  out_file_not_matching.open(file_name_not_matching);
  if (out_file_matching.is_open() and out_file_not_matching.is_open()) {
    for (size_t i = 0; i < number_of_chars / 2; ++i) {
      out_file_matching << "{";
      out_file_not_matching << "{";
    }
    for (size_t i = 0; i < number_of_chars / 2; ++i) {
      out_file_matching << "}";
      out_file_not_matching << "{";
    }
    out_file_matching << "\n";
    out_file_matching.close();
    out_file_not_matching << "}\n";
    out_file_not_matching.close();
  } else {
    std::cerr << "Error: unable to open file for writing.\n";
    return -1;
  }
  return 0;
}
