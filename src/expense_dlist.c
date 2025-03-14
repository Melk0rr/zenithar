// INFO: DList to handle expenses

#include <stdio.h>
#include <stdlib.h>

#include "expense_dlist.h"
#include "expense.h"

// Function to create an empty expense dlist : see expense_dlist.h
ExpenseDList *newExpenseDList()
{
  ExpenseDList *eli = malloc(sizeof(*eli));

  if (eli != NULL)
  {
    eli->length = 0;
    eli->sum = 0;
    eli->begin = NULL;
    eli->end = NULL;
  }

  return eli;
}

// Function check if an expense dlist is empty : see expense_dlist.h
bool isExpenseDListEmpty(ExpenseDList *eli)
{
  if (eli == NULL || eli->end == NULL)
  {
    return true;
  }

  return false;
}

// Function to return expense dlist length : see expense_dlist.h
int expenseDListLength(ExpenseDList *eli)
{
  if (isExpenseDListEmpty(eli))
  {
    return 0;
  }

  return eli->length;
}

// Function to retreive first element of expense dlist : see expense_dlist.h
expense *getFirstExpenseDListNode(ExpenseDList *eli)
{
  if (isExpenseDListEmpty(eli))
  {
    exit(1);
  }

  return eli->begin->nodeExpense;
}

// Function to retreive the last element of expense dlist : see expense_dlist.h
expense *getLastExpenseDListNode(ExpenseDList *eli)
{
  if (isExpenseDListEmpty(eli))
  {
    exit(1);
  }

  return eli->end->nodeExpense;
}

// Function to push a new expense at the end of an expense dlist : see
// expense_dlist.h
ExpenseDList *pushBackExpenseDList(ExpenseDList *eli, expense *exp)
{
  ExpenseDListNode *expNode = malloc(sizeof(*expNode));

  if (expNode == NULL)
  {
    fprintf(stderr, "pushBackExpenseDList::Memory allocation failed for new "
                    "ExpenseDListNode !");
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
      fprintf(stderr, "pushBackExpenseDList::Memory allocation failed for "
                      "empty ExpenseList !");
      exit(1);
    }

    // If dlist is empty : new node is the first and last element
    eli->begin = expNode;
    eli->end = expNode;

  } else
  {
    // If dlist is not empty : Last dlist element next pointer now points to new
    // node
    eli->end->next = expNode;

    // New node prev pointer now points to the previous last dlist element
    expNode->prev = eli->end;

    // And dlist end now points to the new node
    eli->end = expNode;
  }

  eli->length++;
  eli->sum += exp->expenseCost;

  return eli;
}

// Function to push a new expense at the beginning of an expense dlist : see
// expense_dlist.h
ExpenseDList *pushFrontExpenseDList(ExpenseDList *eli, expense *exp)
{
  ExpenseDListNode *expNode = malloc(sizeof(*expNode));

  if (expNode == NULL)
  {
    fprintf(stderr, "pushFrontExpenseDList::Memory allocation failed for new "
                    "ExpenseDListNode !");
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
      fprintf(stderr, "pushFrontExpenseDList::Memory allocation failed for "
                      "empty ExpenseList !");
      exit(1);
    }

    // If dlist is empty : new node is the first and last element
    eli->begin = expNode;
    eli->end = expNode;

  } else
  {
    // If dlist is not empty : Last dlist element next pointer now points to new
    // node
    eli->begin->prev = expNode;

    // New node prev pointer now points to the previous last dlist element
    expNode->next = eli->begin;

    // And dlist end now points to the new node
    eli->begin = expNode;
  }

  eli->length++;
  eli->sum += exp->expenseCost;

  return eli;
}

// Function to pop an expense node from given list end : see expense_dlist.h
ExpenseDList *popBackExpenseDList(ExpenseDList *eli)
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
  // Saves the last element
  ExpenseDListNode *tmp = eli->end;

  // Last node is now the second to last
  eli->end = eli->end->prev;

  // The new last node next pointer is now NULL as it is the last element
  eli->end->next = NULL;

  // Deleting removed node links to prev and next
  tmp->next = NULL;
  tmp->prev = NULL;
  eli->sum -= tmp->nodeExpense->expenseCost;

  free(tmp);
  tmp = NULL;

  eli->length--;

  return eli;
}

// Function to pop an expense node from given list beginning : see
// expense_dlist.h
ExpenseDList *popFrontExpenseDList(ExpenseDList *eli)
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
  // Saves the first element
  ExpenseDListNode *tmp = eli->begin;

  // First node is now the second to first
  eli->begin = eli->begin->next;

  // The new first node prev pointer is now NULL as it is the first element
  eli->begin->prev = NULL;

  // Deleting removed node links to prev and next
  tmp->next = NULL;
  tmp->prev = NULL;
  eli->sum -= tmp->nodeExpense->expenseCost;

  free(tmp);
  tmp = NULL;

  eli->length--;

  return eli;
}

// Function to remove a specific expense from an expense dlist : see
// expense_dlist.h
ExpenseDList *popExpenseFromDList(ExpenseDList *eli, expense *exp)
{
  if (isExpenseDListEmpty(eli))
  {
    printf("popUserFromDList::List is empty, no user to pop");
    return newExpenseDList();
  }

  ExpenseDListNode *temp = eli->begin;

  while (temp != NULL && &temp->nodeExpense != &exp)
  {
    temp = temp->next;
  }

  // If list only contains one element
  if (eli->begin == eli->end)
  {
    free(eli);
    eli = NULL;

    return newExpenseDList();
  }
  // If first in list
  else if (temp->prev == NULL)
  {
    eli->begin = temp->next;
    eli->begin->prev = NULL;
  }
  // If last in list
  else if (temp->next == NULL)
  {
    eli->end = temp->prev;
    eli->end->next = NULL;
  } else
  {
    // Pointing previous node to the next and vice versa
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    temp->prev = NULL;
    temp->next = NULL;
  }

  free(temp);
  temp = NULL;

  eli->length--;
  return eli;
}

// Function to print the content of an expense dlist : see expense_dlist.h
void printExpenseDList(ExpenseDList *eli)
{
  if (isExpenseDListEmpty(eli))
  {
    printf("printExpenseDlist::List is empty, nothing to print");
    return;
  }

  ExpenseDListNode *temp = eli->begin;

  while (temp != NULL)
  {
    printf("%s : %f\n", temp->nodeExpense->expenseName,
           temp->nodeExpense->expenseCost);
    temp = temp->next;
  }
}

// Function to clear an expense dlist content : see expense_dlist.h
ExpenseDList *clearExpenseDlist(ExpenseDList *eli)
{
  while (!isExpenseDListEmpty(eli))
  {
    eli = popBackExpenseDList(eli);
  }

  return newExpenseDList();
}
