#ifndef __USER_DLIST__H__
#define __USER_DLIST__H__

#import "user.h"
#import "utils.h"

// #########################################################
// User DList and node struct definition

/**
 * @brief Users doubled chained list node
 * 
 */
typedef struct UserDListNode
{
  user nodeUser;
  struct UserDListNode *prev;
  struct UserDListNode *next;
} UserDListNode;

/**
 * @brief User doubled chained list
 * 
 */
typedef struct UserDList
{
  int length;
  struct UserDListNode *begin;
  struct UserDListNode *end;
} *UserDList;

// #########################################################
// Prototypes

#endif