#include "expense_dlist.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

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

// Function to return expense dlist length : see expense_dlist.h
int expenseDListLength(ExpenseDList eli)
{
  if (isExpenseDListEmpty(eli))
  {
    return 0;
  }
  
  return eli->length;
}

// Function to retreive first element of expense dlist : see expense_dlist.h
expense getFirstExpenseDListNode(ExpenseDList eli)
{
  if (isExpenseDListEmpty(eli))
  {
    exit(1);
  }

  return eli->begin->nodeExpense;
}

// Function to retreive the last element of expense dlist : see expense_dlist.h
expense getLastExpenseDListNode(ExpenseDList eli)
{
  if (isExpenseDListEmpty(eli))
  {
    exit(1);
  }

  return eli->end->nodeExpense;
}