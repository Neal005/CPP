#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char strInput[100];
int currentPos = 0;

double checkTerm();
double checkFactor();

// Hàm lấy số thực
double getDouble(int pos) {
  double number = 0.0;
  int sign = 1;
  int decimalFound = 0;
  double decimalPlace = 0.1;

  // Xử lý dấu
  if (strInput[pos] == '-') {
    sign = -1;
    pos++;
  } else if (strInput[pos] == '+') {
    pos++;
  }

  while (pos < strlen(strInput) && (isdigit(strInput[pos]) || strInput[pos] == '.')) {
    if (strInput[pos] == '.') {
      if (decimalFound) {
        printf("Invalid number format\n");
        exit(1);
      }
      decimalFound = 1;
    } else {
      if (decimalFound) {
        number += (strInput[pos] - '0') * decimalPlace;
        decimalPlace /= 10.0;
      } else {
        number = number * 10.0 + (strInput[pos] - '0');
      }
    }
    pos++;
  }
  currentPos = pos;
  return sign * number;
}

// Hàm kiểm tra biểu thức
double checkExpression() {
  double result = checkTerm();
  if (currentPos == strlen(strInput)) {
    return result;
  }
  while (currentPos < strlen(strInput)) {
    if (strInput[currentPos] == '+') {
      currentPos++;
      result += checkExpression();
    } else if (strInput[currentPos] == '-') {
      currentPos++;
      result -= checkExpression();
    } else {
      break; // Dừng nếu gặp phép toán khác
    }
  }
  return result;
}

// Hàm kiểm tra số hạng
double checkTerm() {
  double result = checkFactor();
  if (currentPos == strlen(strInput)) {
    return result;
  }
  while (currentPos < strlen(strInput)) {
    if (strInput[currentPos] == '*') {
      currentPos++;
      result *= checkTerm();
    } else if (strInput[currentPos] == '/') {
      currentPos++;
      double divisor = checkTerm();
      if (divisor == 0.0) {
        printf("Error: Division by zero!\n");
        exit(1);
      }
      result /= divisor;
    } else {
      break; // Dừng nếu gặp phép toán khác
    }
  }
  return result;
}

// Hàm kiểm tra thừa số
double checkFactor() {
  if (strInput[currentPos] == '(') {
    currentPos++;
    double result = checkExpression();
    if (strInput[currentPos] == ')') {
      currentPos++;
      return result;
    } else {
      printf("Invalid Expression\n");
      exit(1);
    }
  } else {
    return getDouble(currentPos);
  }
}

int main() {
  printf("Nhap bieu thuc: ");
  fgets(strInput, sizeof(strInput), stdin); // Sử dụng fgets để đọc input an toàn hơn
  double result = checkExpression();
  printf("Result: %f\n", result);
  return 0;
}