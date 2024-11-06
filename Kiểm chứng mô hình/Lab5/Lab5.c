#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define debug 0

char strInput[100];
int currentPos = 0;

double checkTerm();
double checkFactor();

// Hàm lấy số thực
double getDouble(int pos)
{
  double number = 0.0;
  int sign = 1;
  int decimalFound = 0;
  double decimalPlace = 0.1;

  // Xử lý dấu
  if (strInput[pos] == '-')
  {
    sign = -1;
    pos++;
  }
  else if (strInput[pos] == '+')
  {
    pos++;
  }

  while (pos < strlen(strInput) && (isdigit(strInput[pos]) || strInput[pos] == '.'))
  {
    if (strInput[pos] == '.')
    {
      if (decimalFound)
      {
        printf("Invalid number format at position %d\n", pos);
        exit(1);
      }
      decimalFound = 1;
    }
    else
    {
      if (decimalFound)
      {
        number += (strInput[pos] - '0') * decimalPlace;
        decimalPlace /= 10.0;
      }
      else
      {
        number = number * 10.0 + (strInput[pos] - '0');
      }
    }
    pos++;
  }
  currentPos = pos;
  return sign * number;
}

void removeSpaces(char *str)
{
  int i, j;
  for (i = 0, j = 0; str[i] != '\0'; i++)
  {
    if (str[i] != ' ' && str[i] != '\t')
    {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
}

// Hàm kiểm tra biểu thức
double checkExpression()
{
  double result = checkTerm();
  while (currentPos < strlen(strInput))
  {
    if (strInput[currentPos] == '+')
    {
      currentPos++;
      result += checkTerm();
    }
    else if (strInput[currentPos] == '-')
    {
      currentPos++;
      result -= checkTerm();
    }
    else if (strInput[currentPos] != '\n' && strInput[currentPos] != ')')
    {
      printf("Invalid character '%c' at position %d\n", strInput[currentPos], currentPos);
      exit(1);
    }
    else
    {
      break;
    }
  }
  return result;
}

// Hàm kiểm tra số hạng
double checkTerm()
{
  double result = checkFactor();
  while (currentPos < strlen(strInput))
  {

    if (strInput[currentPos] == '*')
    {
      currentPos++;
      result *= checkTerm();
    }
    else if (strInput[currentPos] == '/')
    {
      currentPos++;
      double divisor = checkTerm();
      if (divisor == 0.0)
      {
        printf("Error: Division by zero!\n");
        exit(1);
      }
      result /= divisor;
    }
    else
    {
      break;
    }
  }
  return result;
}

// Hàm kiểm tra thừa số
double checkFactor()
{
  if (strInput[currentPos] == ')')
  {
    printf("Unmatched parenthesis at position %d\n");
    exit(1);
  }
  else if (strInput[currentPos] == '(')
  {
    currentPos++;
    double result = checkExpression();
    if (strInput[currentPos] == ')')
    {
      currentPos++;
      return result;
    }
    else
    {
      printf("Unmatched parenthesis at position %d\n", currentPos);
      exit(1);
    }
  }
  else
  {
    return getDouble(currentPos);
  }
}

int main()
{
  char choice;
  FILE *fp;

  printf("How to input:\n");
  printf("1. From keyboard\n");
  printf("2. Choosing file\n");
  scanf(" %c", &choice);

  if (choice == '1')
  {
    printf("Enter an expression: ");
    fgets(strInput, sizeof(strInput), stdin);
    fgets(strInput, sizeof(strInput), stdin);
    removeSpaces(strInput);
  }
  else if (choice == '2')
  {
    char filename[100];
    printf("Enter file name: ");
    fgets(filename, sizeof(filename), stdin);
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    if(debug==1) printf("%s ",filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
      printf("cannot open file.\n");
      return 1;
    }

    fgets(strInput, sizeof(strInput), fp);
    removeSpaces(strInput);
    fclose(fp);
  }
  else
  {
    printf("invalid choice.\n");
    return 1;
  }

  double result = checkExpression();
  printf("Result: %f\n", result);
  return 0;
}