#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables for calculator state
float Num1 = 0;
float Num2 = 0;
float Result = 0;
char Operator;

// Function to perform the calculation
float calculate(float num1, float num2, char operator) {
  switch (operator) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      if (num2 != 0) {
        return num1 / num2;
      } else {
        printf("Error: Division by zero.\n");
        return 0;
      }
    default:
      printf("Error: Invalid operator.\n");
      return 0;
  }
}

// Function to display the calculator interface
void display_interface() {
  printf("Simple Console Calculator\n");
  printf("Enter calculations in the format: <number1> <operator> <number2>\n");
  printf("Supported operators: +, -, *, /\n");
  printf("Type 'exit' to quit.\n\n");
}

int main() {
  char input[100];
  display_interface();

  while (1) {
    printf("Enter calculation: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {

      // Remove newline character
      size_t len = strlen(input);
      if (len > 0 && (input[len - 1] == '\n' || input[len - 1] == '\r')) {
        input[len - 1] = '\0';
      }
      if (len > 1 && (input[len - 2] == '\r' || input[len - 2] == '\n')) {
        input[len - 2] = '\0';
      }

      // Exit condition
      if (strcmp(input, "exit") == 0) {
        printf("Goodbye!\n");
        break;
      }

      // Parse input
      int ret = sscanf(input, "%f %c %f", &Num1, &Operator, &Num2);
      if (ret == 3) {
        Result = calculate(Num1, Num2, Operator);
        printf("Result: %.2f\n\n", Result);
      } else {
        printf("Error: Invalid input format. Please try again.\n\n");
      }
    }
  }

  return 0;
}
