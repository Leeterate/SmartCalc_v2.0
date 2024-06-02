#include <gtest/gtest.h>

#include "model.h"
#include "controller.h"

#define ACCURACY 1e-07

TEST(priority_and_input_test, test_1) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "1999999999-478.23472-381389+.";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_2) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000000-+-478.23472-381389";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_3) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000000-sgh-478.23472-381389";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_4) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "x-0.0001+xx-890317+x";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_5) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "00-+478.23472";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_6) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "100000.00--478.23472-..381389";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_7) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "*569/3901/(199.237*23678.6785)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_8) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000000-*-478.23472/381389";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_9) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = ".*367/3782";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_10) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "x-0.0001*xx-890317/x";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_11) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "x-0.0001*x-890317//x";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(priority_and_input_test, test_12) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "100000.00/478.23472*..381389";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_1) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "^247^(0.4379)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_2) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "4269+478=48";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_3) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = ".367^..3782";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_4) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "()";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_5) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "x-0.0001*x-890317/()-x";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_6) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "100000.00/478.23472(381389)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_7) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "1ee-7+cos(4)*1e+3";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_8) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "sin65)-cos()3";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_9) {
war::MathCalculator m;
war::Controller controller_(&m);

std::string input = "sin(45)+cas(37)-456*log(0)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_10) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "32849-log(()";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_11) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "lg(2.75)/log(100)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_12) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "ln(2)-atan(0x)*cos(30)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_func_test, test_13) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "sqrt(389*389)/tan(5)+log(100x0000)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_1) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "46/3+5^2*.(89+4)*sin(2)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_2) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "sin(-30)+()-34.5";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_3) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "46/3+5^2*(89+4)*san(2)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_4) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "46/3+5^2*(89+)*sin(2)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_5) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "46/3+5^2*(89+4)*sin2";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_6) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "56.-90(cos(3))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_7) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "56.-90*cos(3))^";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_8) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "57+[-9]*(46-24/3)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_9) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = ".*567.98*(-cos(0/0))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_10) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "567.98*(-cos))mod";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_11) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "mod5-90/7";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_12) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "5467.43.290+327-cos(0)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_13) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "x456-cos(3)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_14) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "76sin(4)-9823";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_15) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "76*sin(4)-9823+";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_16) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "7.9-gd(0)+652-cos(3)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_17) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "901/67*1-546+coscos(984)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_18) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "tan(50)/3+./0.0";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_20) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000..000+98/100000-cos(90)*(sqrt(625))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_21) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000.000+98/10.00.00-cos(90)*(sqrt(625))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_22) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000000+98/10.0000-cos(90)**(sqrt(625))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_23) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000000+98/10.0000-c-os(90)*(sqrt(625))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_24) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "10000000+98/100000-cos(90)*(sqrt(625),)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_26) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "++78-cos(3)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_27) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "+67*(asan(-2)/5)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_28) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "96mod^2-98*(1/2)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_29) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "46/3+5^2*(89+4)*sin.(2)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_30) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = ".";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_31) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "++";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_32) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "/";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_33) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "cos";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_34) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "mod";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_35) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "-1+";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_36) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = ".";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_37) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "100-+";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_38) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_39) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "1e+10000000000000";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_41) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "(1+(2+3)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_42) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "1+(2+3))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_43) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "1+(3*6)))))))";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_44) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "1+()";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_45) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "(1+2)sin(8)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_46) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "(1+2)sin()";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_47) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = ")()()";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_48) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "abcdefg1";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_49) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "(-)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_50) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "(3)-";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_51) {
 
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "(--4)-(---5)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_52) {
 
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "-(a)";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_53) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "a";
  double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_54) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "sin";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_55) {
war::MathCalculator m;
war::Controller controller_(&m);
std::string input = "t";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_56) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "s+4";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_57) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "+4";
  std::string stdr = "4";
  double X = 0;
  m.Calculate(X, input);
  EXPECT_EQ(m.GetStringAnswer(), stdr);
}

TEST(exceptions_input_test, test_58) {
 
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "2+d7";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_59) {
 
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "4 s+4";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(exceptions_input_test, test_60) {
 
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "   ";
double X = 0;
ASSERT_ANY_THROW(m.Calculate(X, input));
}

TEST(accuracy_test, test_1) {
    war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "((+4))";
  double X = 0;
  m.Calculate(X, input);  EXPECT_NEAR(m.GetDoubleAnswer(), 4, ACCURACY);
}

TEST(accuracy_test, test_2) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "(+4)";
  std::string stdr = "4";
  double X = 0;
  m.Calculate(X, input);  EXPECT_EQ(m.GetStringAnswer(), stdr);
}

TEST(accuracy_test, test_4) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "log(-178)+634/2/0.5";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_TRUE(std::isnan(m.GetDoubleAnswer()));
}

TEST(accuracy_test, test_5) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 2538.250420002308894;
  std::string input = "log(178)+634/2/0.5^3";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_6) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = -1.582661488475988;
  std::string input = "atan(0)^3-155.87633/098.49mod(356-42)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_7) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 4247.389013;
  std::string input = "3958-sqrt(567^3-567)*ln(1)+289.389013";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_8) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 10000007.962414428;
  std::string input = "100010001/3794*0.00034+9999999";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_9) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "1.0/0.0+cos(180)-1.0/0.0";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_TRUE(std::isnan(m.GetDoubleAnswer()));
}

TEST(accuracy_test, test_10) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "cos(180)-1.0/0.0";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_TRUE(std::isinf(m.GetDoubleAnswer()));
}

TEST(accuracy_test, test_11) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "tan(50)/3+1.0/0.0";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_TRUE(std::isinf(m.GetDoubleAnswer()));
}
TEST(accuracy_test, test_12) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = -12.046197928264263;
  std::string input = "150-cos(180)*150/5+(-180)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_14) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = -0.55193482688;
  std::string input = "cos(76-60)*(35mod7)-542/982";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_15) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 3.85919608528;
  std::string input = "log(1000*ln(200*ln(1000)))";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
  result = 1;
  input = "10000*(1e-4)";
  X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_16) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = -12.046197928264263;
  std::string input = "150-cos(180)*150/5+(-180)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_19) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "ln(100000)-78361+asin(2)-(645mod82)^7";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_TRUE(std::isnan(m.GetDoubleAnswer()));
}

TEST(accuracy_test, test_21) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 3.4785444;
  std::string input = "8-cos(8^9)*7";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_22) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 204.1237307;
  std::string input = "187/5+9*(ln(10)^3.5)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_23) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 2339.424035906;
  std::string input = "46/3+5^2*(89+4)-sin(2)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_24) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 2129.4498507030432;
  std::string input = "46/3+5^2*(89+4)*sin(2)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_25) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 29.3898559;
  std::string input = "987.65^(1/2)+7*tan(3/0.5)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_26) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 2.0044135;
  std::string input = "2+tan(45)/(7-90*(-4))";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
  result = -0.3047384;
  input = "cos(23.4+tan(23*(0-23)))";
  X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_28) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = -93.0218387;
  std::string input = "87.9/456+atan(1)-94";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_29) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 8.99808109;
  std::string input = "sqrt(64)-cos(90+64)/log(10)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_30) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 1406.78106838;
  std::string input = "46/3+5^2*(89+4)*sin(2.5)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_31) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 5764801;
  std::string input = "7*7^7";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_32) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  std::string input = "3mod9-7^(1/2)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(m.GetDoubleAnswer(), 0.35424868, ACCURACY);
}


TEST(accuracy_test, test_33) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = -0.1;
  std::string input = "1/(-10)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_34) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = -0.9999014;
  std::string input = "+986*0.0000001-(91mod3)^3";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
  input = "+986*(1E-7)-(91mod3)^3";
  X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_35) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 1087.2641095702704976;
  std::string input = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  double X = 0;
  m.Calculate(X, input);  
  EXPECT_NEAR(result, m.GetDoubleAnswer(), ACCURACY);
}

TEST(accuracy_test, test_36) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 64;
  std::string input = "x*x*sqrt(x)*2*2/2";
  double X = 4;
  m.Calculate(X, input);  
  EXPECT_EQ(result, m.GetDoubleAnswer());
}

TEST(accuracy_test, test_37) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 64;
  std::string input = "X*x*sqrt(x)/2*2*2";
  double X = 4;
  m.Calculate(X, input);  
  EXPECT_EQ(result, m.GetDoubleAnswer());
}

TEST(accuracy_test, test_38) {
  war::MathCalculator m;
  war::Controller controller_(&m);
  double result = 3;
  std::string input = " 3 ";
  double X = 900;
  m.Calculate(X, input);  
  EXPECT_EQ(result, m.GetDoubleAnswer());
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
