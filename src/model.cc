#include "model.h"

namespace war {

void war::MathCalculator::Calculate(double X, std::string& source) {
  double res = 0;
  try {
    ReplaceX(X, source);
    CheckInput(source);
    Dijkstra_algorithm();
    res = CalculateNotation();
  } catch (std::exception& error_message) {
    input_.clear();
    throw;
  }
  result_ = res;
  return;
}

void war::MathCalculator::ReplaceX(double X, std::string& source) {
  std::ostringstream oss1;
  oss1.precision(10);
  oss1 << X;
  std::string x_replace = oss1.str();
  x_replace.insert(0, 1, '(');
  x_replace.append(")");
  source = regex_replace(source, std::regex("x"), x_replace);
  source = regex_replace(source, std::regex("X"), x_replace);
}

void war::MathCalculator::CheckInput(std::string& str) {
  if (str.empty()) {
    throw std::runtime_error("Input is empty");
  }
  std::string str1 = str;
  std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);

  FillSpaces(str1);
  CountBrackets(str1);
  ReplaceUnary(str1);
  size_t input_amount = str1.size();
  std::regex reg_expr(
      R"(sin|cos|tan|acos|asin|atan|sqrt|ln|log|mod|\+|\-|\*|\/|\(|\)|\^|\d+(\.\d+)?[e][-+]?\d+|\d+\.\d+|\d+)");
  std::smatch reg_found;
  size_t recogn_amount = 0;
  bool flg = std::regex_search(str1, reg_found, reg_expr);
  if (flg != 1)
    throw std::runtime_error("Error: no correct operands/operators");
  while (flg) {
    if (isdigit(reg_found.str().at(0))) {
      GetNumber(reg_found.str());
      str1 = reg_found.suffix().str();
      recogn_amount += reg_found.length();
    } else {
      auto iter = token_map.find(reg_found.str());
      if (iter != token_map.end()) {
        input_.push_back(iter->second);
      }
      str1 = reg_found.suffix().str();
      recogn_amount += reg_found.length();
    }
    flg = std::regex_search(str1, reg_found, reg_expr);
  }
  if (recogn_amount != input_amount) {
    throw std::runtime_error("Error: unrecognized characters in the input");
  }
  CheckTokenSyntax();
}

void war::MathCalculator::FillSpaces(std::string& str) {
  str.erase(
      std::remove_if(str.begin(), str.end(), [](char c) { return c == ' '; }),
      str.end());
}

void war::MathCalculator::CountBrackets(std::string& str) {
  int brackets = 0;
  std::string::iterator iter = str.begin();
  while (iter != str.end()) {
    if (*iter == '(') {
      if (*(iter + 1) == ')') {
        throw std::runtime_error("Error: wrong brackets usage");
      }
      ++brackets;
      ++iter;
    } else if (*iter == ')') {
      if (*(iter + 1) == '(') {
        throw std::runtime_error("Error: wrong brackets usage");
      }
      --brackets;
      ++iter;
    } else {
      ++iter;
    }
    if (brackets < 0) throw std::runtime_error("Error: uneven brackets");
  }
  if (brackets != 0) {
    throw std::runtime_error("Error: uneven brackets");
  }
}

void war::MathCalculator::ReplaceUnary(std::string& str) {
  if (str.front() == '-') {
    str.insert(str.begin(), '0');
  } else if (str.front() == '+') {
    str.insert(str.begin(), '0');
  }
  size_t __pos;
  while ((__pos = str.find("(+")) != std::string::npos) {
    str.insert(__pos + 1, 1, '0');
  }
  while ((__pos = str.find("(-")) != std::string::npos) {
    str.insert(__pos + 1, 1, '0');
  }
}

void war::MathCalculator::CheckTokenSyntax() {
  auto curr = input_.begin();
  auto prev = input_.begin();
  if (input_.front().type_ == kCloseBracket ||
      input_.front().type_ == kBinaryOperator) {
    throw std::logic_error("Error: first symbol lacks an operand");
  }
  if (input_.back().type_ == kFunction || input_.back().type_ == kOpenBracket ||
      input_.back().type_ == kBinaryOperator) {
    throw std::logic_error("Error: last symbol lacks an operand");
  }

  ++curr;
  while (curr != input_.end()) {
    if (prev->type_ == kNumber) {
      if (curr->type_ != kBinaryOperator && curr->type_ != kCloseBracket) {
        throw std::logic_error("Error: incompartible tokens");
      }
    } else if (prev->type_ == kCloseBracket) {
      if (curr->type_ != kBinaryOperator && curr->type_ != kCloseBracket) {
        throw std::logic_error("Error: incompartible tokens");
      }
    } else if (prev->type_ == kBinaryOperator) {
      if (curr->type_ != kNumber && curr->type_ != kOpenBracket &&
          curr->type_ != kFunction) {
        throw std::logic_error("Error: incompartible tokens");
      }
    } else if (prev->type_ == kFunction) {
      if (curr->type_ != kOpenBracket) {
        throw std::logic_error("Error: incompartible tokens");
      }
    }
    ++curr;
    ++prev;
  }
}

void war::MathCalculator::Dijkstra_algorithm() {
  std::stack<Token> operators;
  while (!input_.empty()) {
    if (input_.front().type_ == kNumber) {
      PolishNotation.push(input_.front());
    } else if (input_.front().type_ == kOpenBracket) {
      operators.push(input_.front());
    } else if (input_.front().type_ == kCloseBracket) {
      while (operators.top().type_ != kOpenBracket) {
        PolishNotation.push(operators.top());
        operators.pop();
      }
      operators.pop();
    } else if (operators.empty()) {
      operators.push(input_.front());
    } else {
      if (input_.front().priority_ > operators.top().priority_ ||
          (input_.front().name_ == "^" && operators.top().name_ == "^")) {
        operators.push(input_.front());
      } else {
        while (!operators.empty() &&
               input_.front().priority_ <= operators.top().priority_) {
          PolishNotation.push(operators.top());
          operators.pop();
        }
        operators.push(input_.front());
      }
    }
    input_.pop_front();
  }

  while (!operators.empty()) {
    PolishNotation.push(operators.top());
    operators.pop();
  }
}

void war::MathCalculator::GetNumber(std::string tok) {
  Token number(tok, kNumber, kFirst, std::stod(tok));
  input_.push_back(number);
}

double war::MathCalculator::CalculateNotation() {
  double first_op, second_op;
  double result = 0;
  std::stack<Token> operands;
  while (!PolishNotation.empty()) {
    if (PolishNotation.front().type_ == kNumber) {
      result = std::get<double>(PolishNotation.front().token_data);
      operands.push(war::Token("", kNumber, kFirst, result));
      PolishNotation.pop();
    } else if (PolishNotation.front().type_ == kBinaryOperator) {
      auto operation = std::get<bfunc>(PolishNotation.front().token_data);
      PolishNotation.pop();
      second_op = std::get<double>(operands.top().token_data);
      operands.pop();
      first_op = std::get<double>(operands.top().token_data);
      operands.pop();
      result = operation(first_op, second_op);
      operands.push(war::Token("", kNumber, kFirst, result));
    } else {
      auto operation = std::get<ufunc>(PolishNotation.front().token_data);
      PolishNotation.pop();
      second_op = std::get<double>(operands.top().token_data);
      operands.pop();
      result = operation(second_op);
      operands.push(war::Token("", kNumber, kFirst, result));
    }
  }
  return result;
}

std::string MathCalculator::GetStringAnswer() const noexcept {
  std::ostringstream oss;
  oss.precision(10);
  oss << result_;
  return oss.str();
}

double MathCalculator::GetDoubleAnswer() const noexcept { return result_; }

};  // namespace war
