// INFO: Users manipulations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expense_dlist.h"
#include "user.h"

// ************************************************************
// INFO: User creation / initialization

// Creates a new user : see user.h
{
  user *newUser = (user *)malloc(sizeof(*newUser));
  if (newUser == NULL)
  {
    fprintf(stderr, "createUser::Memory allocation failed !");
    exit(1);
  }

  // Changes new user's name and asusring null-termination
  strncpy((char *)&newUser->userName, (char *)usrName,
          sizeof(newUser->userName) - 1);
  newUser->userName[sizeof(newUser->userName) - 1] = '\0';

  newUser->expenseList = *newExpenseDList();

  return newUser;
}

// Adds an expense to user expense dlist : see user.h
{
  // Add new expense
  expense *newExp = createExpense(expName, expCost);
  usr->expenseList = *pushBackExpenseDList(&usr->expenseList, newExp);
}

// ************************************************************
// INFO: User expenses

// Sums the given user expenses : see user.h
float getUserExpenseSum(user *usr) { return usr->expenseList.sum; }

// Resets given user expenses : see user.h
void resetUserExpenses(user *usr)
{
  usr->expenseList = *clearExpenseDlist(&usr->expenseList);
}
