#include "expense_dlist.h"
#include "utils.h"

#include <cstddef>
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

// Function to push a new expense at the end of an expense dlist : see expense_dlist.h
ExpenseDList pushBackExpenseDList(ExpenseDList eli, expense exp)
{
  ExpenseDListNode *expNode = malloc(sizeof(*expNode));
  
  if (expNode == NULL)
  {
    fprintf(stderr, "pushBackExpenseDList::Memory allocation failed for new ExpenseDListNode !");
    exit(1);
  }

  expNode->nodeExpense = exp;
  expNode->prev = NULL;
  expNode->next = NULL;
  
  if (isExpenseDListEmpty(eli))
  {
    eli = malloc(sizeof(*eli));

    if (eli == NULL)
    {
      fprintf(stderr, "pushBackExpenseDList::Memory allocation failed for empty ExpenseList !");
      exit(1);
    }
    
    // If dlist is empty : new node is the first and last element
    eli->length = 0;
    eli->begin = expNode;
    eli->end = expNode;

  } else {
    // If dlist is not empty : Last dlist element next pointer now points to new node
    eli->end->next = expNode;

    // New node prev pointer now points to the previous last dlist element
    expNode->prev = eli->end;
    
    // And dlist end now points to the new node
    eli->end = expNode;
  }
  
  eli->length++;
  return eli;
}

// Function to push a new expense at the beginning of an expense dlist : see expense_dlist.h
ExpenseDList pushFrontExpenseDList(ExpenseDList eli, expense exp)
{
  ExpenseDListNode *expNode = malloc(sizeof(*expNode));
  
  if (expNode == NULL)
  {
    fprintf(stderr, "pushBackExpenseDList::Memory allocation failed for new ExpenseDListNode !");
    exit(1);
  }

  expNode->nodeExpense = exp;
  expNode->prev = NULL;
  expNode->next = NULL;
  
  if (isExpenseDListEmpty(eli))
  {
    eli = malloc(sizeof(*eli));

    if (eli == NULL)
    {
      fprintf(stderr, "pushBackExpenseDList::Memory allocation failed for empty ExpenseList !");
      exit(1);
    }
    
    // If dlist is empty : new node is the first and last element
    eli->length = 0;
    eli->begin = expNode;
    eli->end = expNode;

  } else {
    // If dlist is not empty : Last dlist element next pointer now points to new node
    eli->begin->prev = expNode;

    // New node prev pointer now points to the previous last dlist element
    expNode->next = eli->begin;
    
    // And dlist end now points to the new node
    eli->begin = expNode;
  }
  
  eli->length++;
  return eli;
}

ExpenseDList popBackExpenseDList(ExpenseDList eli)
{
  if (isExpenseDListEmpty(eli))
  {
    printf("popBackExpenseDList::List is empty. Nothing to pop.\n");
    return newExpenseDList();
  }
  
  // Check if the list contains only one element
  if (eli->begin == eli->end)
  {
    free(eli);
    eli = NULL;

    return newExpenseDList();
  }
  // Saves the las element
  ExpenseDListNode *tmp = eli->end;

  // Last node is now the second to last
  eli->end = eli->end->prev;

  // The new last node next pointer is now NULL as it is the last element
  eli->end->next = NULL;

  // Deleting removed node links to prev and next
  tmp->next = NULL;
  tmp->prev = NULL;

  free(tmp);
  tmp = NULL;

  eli->length--;

  return eli;

}