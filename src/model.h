#ifndef SMARTCALC_MODEL_H_
#define SMARTCALC_MODEL_H_

#include <cctype>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <regex>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>

namespace war {

enum Priority {
  kFirst = 0,  // ( )
  kSecond,     // + -
  kThird,      // * % mod
  kFourth,     // power
  kFifth
};

enum Type {
  kNumber,
  kBinaryOperator,
  kUnaryOperator,
  kFunction,
  kOpenBracket,
  kCloseBracket,
  kNumberOfTokenTypes
};

using ufunc = std::function<double(double)>;
using bfunc = std::function<double(double, double)>;

class Token {
 public:
  Token() = default;
  Token(const std::string& name, Type type, Priority priority,
        std::variant<double, ufunc, bfunc, std::nullptr_t> variant1)
      : name_(name), type_(type), priority_(priority), token_data(variant1){};
  ~Token() = default;

  std::string name_;
  Type type_;
  Priority priority_;
  std::variant<double, ufunc, bfunc, std::nullptr_t> token_data;
};

class MathCalculator {
 public:
  MathCalculator() = default;
  ~MathCalculator() = default;
  void Calculate(double X, std::string& input);
  std::string GetStringAnswer() const noexcept;
  double GetDoubleAnswer() const noexcept;

  const std::map<std::string, Token> token_map{
      {"+", war::Token("plus", Type::kBinaryOperator, Priority::kSecond,
                       std::plus<double>())},
      {"-", war::Token("minus", Type::kBinaryOperator, Priority::kSecond,
                       std::minus<double>())},
      {"*", war::Token("mul", Type::kBinaryOperator, Priority::kThird,
                       std::multiplies<double>())},
      {"/", war::Token("div", Type::kBinaryOperator, Priority::kThird,
                       std::divides<double>())},
      {"mod",
       war::Token("mod", Type::kBinaryOperator, Priority::kThird, fmodl)},
      {"^", war::Token("^", Type::kBinaryOperator, Priority::kFourth, powl)},
      {"(", war::Token("(", Type::kOpenBracket, Priority::kFirst, nullptr)},
      {")", war::Token(")", Type::kCloseBracket, Priority::kFirst, nullptr)},
      {"ln", war::Token("ln", Type::kFunction, Priority::kFifth, logl)},
      {"log", war::Token("log", Type::kFunction, Priority::kFifth, log10l)},
      {"sin", war::Token("sin", Type::kFunction, Priority::kFifth, sinl)},
      {"cos", war::Token("cos", Type::kFunction, Priority::kFifth, cosl)},
      {"tan", war::Token("tan", Type::kFunction, Priority::kFifth, tanl)},
      {"acos", war::Token("acos", Type::kFunction, Priority::kFifth, acosl)},
      {"asin", war::Token("asin", Type::kFunction, Priority::kFifth, asinl)},
      {"atan", war::Token("atan", Type::kFunction, Priority::kFifth, atanl)},
      {"sqrt", war::Token("sqrt", Type::kFunction, Priority::kFifth, sqrtl)}};

 private:
  void ReplaceX(double X, std::string& input);
  void CheckInput(std::string& input);
  void FillSpaces(std::string& input);
  void CountBrackets(std::string& input);
  void ReplaceUnary(std::string& input);
  void GetNumber(std::string input);
  void CheckTokenSyntax();
  void Dijkstra_algorithm();
  double CalculateNotation();

  std::list<Token> input_;
  std::queue<Token> PolishNotation;
  double result_;
};

};  // namespace war

#endif  // SMARTCALC_SRC_MODEL_H_
