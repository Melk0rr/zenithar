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

/**
 * @brief Get the Last Expense D List Node object
 * 
 * @param eli {ExpenseDList} : list from which retreive first node
 * @return expense : last expense
 */
expense getLastExpenseDListNode(ExpenseDList eli);

/**
 * @brief Pushes an expense node at the end of the given expense dlist
 * 
 * @param eli {ExpenseDList} : expense dlist in which push the expense
 * @param exp {expense} : expense to push
 * @return ExpenseDList 
 */
ExpenseDList pushBackExpenseDList(ExpenseDList eli, expense exp);

/**
 * @brief Pushes an expense node at the beginning of the given expense dlist
 * 
 * @param eli {ExpenseDList} : expense dlist in which push the expense
 * @param exp {expense} : expense to push
 * @return ExpenseDList 
 */
ExpenseDList pushFrontExpenseDList(ExpenseDList eli, expense exp);

/**
 * @brief Pops an expense node from the end of the given expense dlist
 * 
 * @param eli {ExpenseDList} : expense dlist from which a node will be poped
 * @return ExpenseDList 
 */
ExpenseDList popBackExpenseDList(ExpenseDList eli);

/**
 * @brief Pops an expense node from the beginning of the given expense dlist
 * 
 * @param eli {ExpenseDList} : expense dlist from which a node will be poped
 * @return ExpenseDList 
 */
ExpenseDList popFrontExpenseDList(ExpenseDList eli);

#endif
