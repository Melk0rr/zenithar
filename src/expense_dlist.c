#include "expense_dlist.h"
#include "utils.h"

#include <stdio.h>

// Function to create an empty expense dlist : see expense_dlist.h
ExpenseDList newExpenseDList()
{
  ExpenseDList eli;
  return eli;
}

// Function check if an expense dlist is empty : see expense_dlist.h
bool isExpenseDListEmpty(ExpenseDList eli)
{
  if (eli == NULL)
  {
    return true;
  }
  
  return false;
}

// Function to return expense dlist length
int expenseDListLength(ExpenseDList eli)
{
  if (isExpenseDListEmpty(eli))
  {
    return 0;
  }
  
  return eli->length;
}