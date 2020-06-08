// Copyright (c) 2020 Johannes Delport
// This code is licensed under MIT license (see LICENSE for details)
#ifndef JOSIM_J_MISC_H
#define JOSIM_J_MISC_H

#include "JoSIM/TypeDefines.hpp"
#include "JoSIM/Parameters.hpp"
#include "JoSIM/Input.hpp"

#include <unordered_map>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <regex>

namespace JoSIM {
class Input;
  namespace Misc {
    double string_constant(const std::string &s);

    std::string file_from_path(const std::string &path);

    bool has_suffix(const std::string &str, 
                    const std::string &suffix);

    bool starts_with(const std::string &input, 
                      char test);

    // View vector of strings as a string with a default delimiter
    std::string vector_to_string(const tokens_t &s, std::string d = " ");


    // Split a string into tokens with a default delimiter
    tokens_t tokenize(const std::string &c,
                      std::string d = " \t",
                      int count = 0,
                      bool trimEmpty = true,
                      bool trimSpaces = false);

    void ltrim(std::string &s);

    void rtrim(std::string &s);

    double modifier(const std::string &value);

    void unique_push(std::vector<std::string> &vector,
                      const std::string &string);

    int index_of(const std::vector<std::string> &vector,
                  const std::string &value);

    std::string substring_after(const std::string &str,
                                const std::string &whatpart);

    std::string substring_before(const std::string &str,
                                  const std::string &whatpart);

    std::vector<double> parse_function(const std::string &str, 
                                        Input &iObj,
                                        const std::string &subckt = "");

    bool findX(const std::vector<std::string> &segment,
                std::string &theLine, 
                int &linePos);

    template <typename A, typename B>
    std::pair<B, A> flip_pair(const std::pair<A, B> &p) {
      return std::pair<B, A>(p.second, p.first);
    }

    template <typename A, typename B>
    std::map<B, A> flip_map(const std::unordered_map<A, B> &src) {
      std::map<B, A> dst;
      std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
                    flip_pair<A, B>);
      return dst;
    }

    template <typename T>
    std::string precise_to_string(const T a_value, const int n = 50) {
      std::ostringstream out;
      out << std::fixed << std::setprecision(n) << a_value;
      return out.str();
    }

    int numDigits(int number);

    double grand();
  } // namespace Misc
} // namespace JoSIM
#endif
