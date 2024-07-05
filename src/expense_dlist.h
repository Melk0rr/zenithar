#ifndef __EXPENSE_DLIST__H__
#define __EXPENSE_DLIST__H__

#import "expense.h"

// #########################################################
// Expense DList and node

/**
 * @brief Expenses doubled chained list node
 * 
 */
typedef struct ExpenseDListNode
{
  expense nodeExpense;
  ExpenseDListNode *prev;
  ExpenseDListNode *next;
} ExpenseDListNode;

/**
 * @brief Expense doubled chained list
 * 
 */
typedef struct ExpenseDList
{
  int length;
  ExpenseDListNode *begin;
  ExpenseDListNode *end;
} ExpenseDList;

#endif