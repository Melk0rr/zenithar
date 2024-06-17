#include "expense.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

expense *createExpense(const signed char *expName, int cost)
{
  // Allocate memory
  expense *newExpense = (expense *)malloc(sizeof(expense));

  if (newExpense == NULL)
  {
    fprintf(stderr, "createExpense::Memory allocation failed !");
    exit(1);
  }

  // Change expense name and ensure null-termination
  strncpy(newExpense->expenseName, expName, sizeof(newExpense->expenseName) - 1);
  newExpense->expenseName[sizeof(newExpense->expenseName) - 1] = '\0';

  newExpense->expenseCost = cost;

  return newExpense;
}