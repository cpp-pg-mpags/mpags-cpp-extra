#include <regex>
#include <iostream>

int main(int, char**) {
  std::regex punctRegex("[^A-Z0-9]");
  std::string foo("EATS, SHOOT'S AND LEAVES");

  std::cout << std::regex_replace(foo,
                                  punctRegex,
                                  "")
            << "\n";

  return 0;
}
