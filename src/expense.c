// INFO: User expenses manipulations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expense.h"

// ************************************************************
// Expense creation / initialization

expense *createExpense(const signed char *expName, float cost)
{
  // Allocate memory
  expense *newExpense = (expense *)malloc(sizeof(*newExpense));

  if (newExpense == NULL)
  {
    fprintf(stderr, "createExpense::Memory allocation failed !");
    exit(1);
  }

  // Change expense name and ensure null-termination
  strncpy((char *)newExpense->expenseName, (char *)expName,
          sizeof(newExpense->expenseName) - 1);
  newExpense->expenseName[sizeof(newExpense->expenseName) - 1] = '\0';

  newExpense->expenseCost = cost;

  return newExpense;
}
