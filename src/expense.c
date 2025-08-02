// INFO: User expenses manipulations

#include <string.h>

#include "expense.h"
#include "utils.h"

// ************************************************************
// Expense creation / initialization

expense * createExpense(char const * const expName, float const cost)
{
  // Allocate memory
  expense * newExpense = (expense *)xmalloc(
      sizeof(*newExpense),
      "createExpense::Failed to allocate memory for new expense");

  // Change expense name and ensure null-termination
  strncpy((char *)newExpense->expenseName, expName,
          sizeof(newExpense->expenseName) - 1);

  newExpense->expenseName[sizeof(newExpense->expenseName) - 1] = '\0';
  newExpense->expenseCost = cost;

  return newExpense;
}
