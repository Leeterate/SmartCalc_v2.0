#ifndef SMARTCALC_CONTROLLER_H_
#define SMARTCALC_CONTROLLER_H_

#include "model.h"

namespace war {
class Controller {
 public:
  Controller() = default;
  explicit Controller(war::MathCalculator *other) : model_(other) {}
  ~Controller() = default;

  void LaunchModel(double X = 0, std::string input = "0") {
    try {
      model_->Calculate(X, input);
      ctrl_result = model_->GetStringAnswer();
      has_exception = false;
    } catch (std::exception &e) {
      ctrl_result = e.what();
      has_exception = true;
    }
  }

  std::string GetFinalResult() const { return ctrl_result; }
  bool CheckException() const { return has_exception; }

 private:
  war::MathCalculator *model_;
  std::string ctrl_result{};
  bool has_exception = false;
};
};  // namespace war

#endif  // SMARTCALC_CONTROLLER_H_
