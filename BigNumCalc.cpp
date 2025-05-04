#include "BigNumCalc.h"

#include <algorithm>
#include <iterator>

bigNumCalc::bigNumCalc() {}

bigNumCalc::~bigNumCalc() {}

std::list<int> bigNumCalc::buildBigNum(const std::string& numString) {
  std::list<int> result;
  for (char ch : numString) {
    if (isdigit(ch)) {
      result.push_back(ch - '0');
    }
  }
  return result;
}

std::list<int> bigNumCalc::add(const std::list<int>& num1,
                               const std::list<int>& num2) {
  std::list<int>::const_reverse_iterator it1 = num1.rbegin();
  std::list<int>::const_reverse_iterator it2 = num2.rbegin();
  std::list<int> result;
  int carry = 0;

  while (it1 != num1.rend() || it2 != num2.rend() || carry > 0) {
    int sum = carry;
    if (it1 != num1.rend()) {
      sum += *it1;
      ++it1;
    }
    if (it2 != num2.rend()) {
      sum += *it2;
      ++it2;
    }
    result.push_front(sum % 10);
    carry = sum / 10;
  }

  return result;
}

std::list<int> bigNumCalc::sub(const std::list<int>& num1,
                               const std::list<int>& num2) {
  std::list<int>::const_reverse_iterator it1 = num1.rbegin();
  std::list<int>::const_reverse_iterator it2 = num2.rbegin();
  std::list<int> result;
  int borrow = 0;

  while (it1 != num1.rend()) {
    int val1 = *it1 - borrow;
    int val2 = (it2 != num2.rend()) ? *it2 : 0;

    if (val1 < val2) {
      val1 += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }

    result.push_front(val1 - val2);

    ++it1;
    if (it2 != num2.rend()) ++it2;
  }

  while (result.size() > 1 && result.front() == 0) {
    result.pop_front();
  }

  return result;
}

std::list<int> bigNumCalc::mul(const std::list<int>& num1, int singleDigit) {
  std::list<int> result;
  if (singleDigit == 0) {
    result.push_back(0);
    return result;
  }

  int carry = 0;
  for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
    int product = (*it) * singleDigit + carry;
    result.push_front(product % 10);
    carry = product / 10;
  }
  if (carry > 0) {
    result.push_front(carry);
  }

  // Remove leading zeros
  while (result.size() > 1 && result.front() == 0) {
    result.pop_front();
  }

  return result;
}
