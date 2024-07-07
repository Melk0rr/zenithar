#ifndef __EXPENSE_DLIST__H__
#define __EXPENSE_DLIST__H__

#import "expense.h"
#import "utils.h"

// #########################################################
// Expense DList and node struct definition

/**
 * @brief Expenses doubled chained list node
 * 
 */
typedef struct ExpenseDListNode
{
  expense nodeExpense;
  struct ExpenseDListNode *prev;
  struct ExpenseDListNode *next;
} ExpenseDListNode;

/**
 * @brief Expense doubled chained list
 * 
 */
typedef struct ExpenseDList
{
  int length;
  struct ExpenseDListNode *begin;
  struct ExpenseDListNode *end;
} *ExpenseDList;

// #########################################################
// Prototypes

/**
 * @brief Creates an empty list
 * 
 * @return ExpenseDList : new empty list
 */
ExpenseDList newExpenseDList(void);

/**
 * @brief Checks if a list is empty
 * 
 * @param eli {ExpenseDList} : list to check
 * @return true : the list is empty
 * @return false : the list is not empty
 */
bool isExpenseDListEmpty(ExpenseDList eli);

/**
 * @brief Returns the current length of the list
 * 
 * @param eli {ExpenseDList} : target list
 * @return int : length of the targeted length
 */
int expenseDListLength(ExpenseDList eli);

/**
 * @brief Get the First Expense D List Node object
 * 
 * @param eli {ExpenseDList} : list from which retreive first node
 * @return expense : first expense
 */
expense getFirstExpenseDListNode(ExpenseDList eli);

#endif
