#ifndef __EXPENSE_DLIST__H__
#define __EXPENSE_DLIST__H__

#include "expense.h"
#include "utils.h"

// #########################################################
// Expense DList and node struct definition

/**
 * @brief Expenses doubled chained list node
 *
 */
typedef struct ExpenseDListNode
{
  expense * nodeExpense;
  struct ExpenseDListNode * prev;
  struct ExpenseDListNode * next;
} ExpenseDListNode;

/**
 * @brief Expense doubled chained list
 *
 */
typedef struct ExpenseDList
{
  int length;
  float sum;
  struct ExpenseDListNode * begin;
  struct ExpenseDListNode * end;
} ExpenseDList;

// #########################################################
// Prototypes

/**
 * @brief Creates an empty expense dlist
 *
 * @return ExpenseDList : new empty expense dlist
 */
ExpenseDList * newExpenseDList(void);

/**
 * @brief Checks if an expense dlist is empty
 *
 * @param eli {ExpenseDList} : list to check
 * @return true : the list is empty
 * @return false : the list is not empty
 */
bool isExpenseDListEmpty(ExpenseDList * const eli);

/**
 * @brief Returns the current length of the expense dlist
 *
 * @param eli {ExpenseDList} : targeted dlist
 * @return int : length of the targeted length
 */
int expenseDListLength(ExpenseDList * const eli);

/**
 * @brief Get the First Expense D List Node object
 *
 * @param eli {ExpenseDList} : list from which retreive first node
 * @return expense : first expense
 */
expense * getFirstExpenseDListNode(ExpenseDList * const eli);

/**
 * @brief Get the Last Expense D List Node object
 *
 * @param eli {ExpenseDList} : list from which retreive first node
 * @return expense : last expense
 */
expense * getLastExpenseDListNode(ExpenseDList * const eli);

/**
 * @brief Pushes an expense node at the end of the given expense dlist
 *
 * @param eli {ExpenseDList} : expense dlist in which push the expense
 * @param exp {expense} : expense to push
 * @return ExpenseDList
 */
ExpenseDList * pushBackExpenseDList(ExpenseDList * const eli, expense * const exp);

/**
 * @brief Pushes an expense node at the beginning of the given expense dlist
 *
 * @param eli {ExpenseDList} : expense dlist in which push the expense
 * @param exp {expense} : expense to push
 * @return ExpenseDList
 */
ExpenseDList * pushFrontExpenseDList(ExpenseDList * const eli, expense * const exp);

/**
 * @brief Pops an expense node from the end of the given expense dlist
 *
 * @param eli {ExpenseDList} : expense dlist from which a node will be poped
 * @return ExpenseDList
 */
ExpenseDList * popBackExpenseDList(ExpenseDList * const eli);

/**
 * @brief Pops an expense node from the beginning of the given expense dlist
 *
 * @param eli {ExpenseDList} : expense dlist from which a node will be poped
 * @return ExpenseDList
 */
ExpenseDList * popFrontExpenseDList(ExpenseDList * const eli);

/**
 * @brief Removes a specific expense from an expense dlist
 *
 * @param eli {ExpenseDlist} : expense dlist from which the expense will be
 * removed
 * @param exp {Expense} : the expense that will be removed
 * @return ExpenseDList
 */
ExpenseDList * popExpenseFromDList(ExpenseDList * const eli, expense * const exp);

/**
 * @brief Prints the content of an expense dlist
 *
 * @param eli {ExpenseDlist} : list to print
 */
void printExpenseDList(ExpenseDList * eli);

/**
 * @brief Clears an expense dlist content
 *
 * @param eli {ExpenseDlist} : expense dlist to clear
 * @return ExpenseDList
 */
ExpenseDList * clearExpenseDlist(ExpenseDList * const eli);

#endif
