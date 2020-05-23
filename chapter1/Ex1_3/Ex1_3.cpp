// Distributed under the MIT License.
// See LICENSE.txt for details.

// This file reads from stdin to a string, checks if it is a matching string,
// and prints the result of this check

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

// Return char_to_match, unless it is one of {}, (), []
// In those cases, return the matching symbol
char matching_character(const char& char_to_match) {
  switch (char_to_match) {
    case ')':
      return '(';
    case ']':
      return '[';
    case '}':
      return '{';
    case '(':
      return ')';
    case '[':
      return ']';
    case '{':
      return '}';
    default:
      break;
  }
  return char_to_match;
}

bool check_closing_character(const char& char_to_check,
                             const std::stack<char>& stack) {
  if (stack.size() > 0) {
    return stack.top() == matching_character(char_to_check);
  } else {
    return false;
  }
}

bool check_if_string_is_matched(const std::string& string_to_check) {
  std::stack<char> chars_to_match;
  bool string_is_matched = true;

  for (auto it = string_to_check.begin(); it != string_to_check.end(); ++it) {
    if (*it == '(' or *it == '[' or *it == '{') {
      chars_to_match.push(*it);
    }
    if (*it == ')' or *it == ']' or *it == '}') {
      if (check_closing_character(*it, chars_to_match)) {
        chars_to_match.pop();
      } else {
        string_is_matched = false;
        continue;
      }
    }
  }
  if (chars_to_match.size() > 0) {
    string_is_matched = false;
  }
  return string_is_matched;
}

int main(void) {
  // Read stdin into a string
  std::string string;
  std::cin >> string;

  // Check if the string is matched
  std::cout << "String ";
  if (string.size() < 60) {
    std::cout << "'" << string << "'";
  } else {
    std::cout << "<<...>>";
  }
  std::cout << "' is ";
  if (not check_if_string_is_matched(string)) {
    std::cout << "not ";
  }
  std::cout << "matched.\n";

  return 0;
}
