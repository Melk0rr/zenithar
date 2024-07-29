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

/**
 * @brief Creates an empty user dlist
 * 
 * @return UserDList : new empty list
 */
UserDList newUserDList(void);

/**
 * @brief Checks if a user dlist is empty
 * 
 * @param uli {UserDList} : dlist to check
 * @return true : the dlist is empty
 * @return false : the dlist is not empty
 */
bool isUserDListEmpty(UserDList uli);

/**
 * @brief Returns the current length of the user dlist
 * 
 * @param uli {UserDList} : targeted dlist
 * @return int : length of the targeted length
 */
int userDListLength(UserDList uli);

/**
 * @brief Get the first user dlist node object
 * 
 * @param uli {UserDList} : list from which retreive first node
 * @return user : first user
 */
user getFirstUserDListNode(UserDList uli);

/**
 * @brief Get the last user dist node object
 * 
 * @param eli {UserDList} : list from which retreive first node
 * @return user : last user
 */
user getLastUserDListNode(UserDList uli);

/**
 * @brief Pushes a user node at the end of the given user dlist
 * 
 * @param uli {UserDList} : user dlist in which push the User
 * @param usr {user} : user to push
 * @return UserDList 
 */
UserDList pushBackUserDList(UserDList uli, user usr);

/**
 * @brief Pushes a user node at the beginning of the given user dlist
 * 
 * @param uli {UserDList} : user dlist in which push the user
 * @param usr {user} : user to push
 * @return UserDList 
 */
UserDList pushFrontUserDList(UserDList uli, user usr);

/**
 * @brief Pops an user node from the end of the given user dlist
 * 
 * @param uli {UserDList} : user dlist from which a node will be poped
 * @return UserDList 
 */
UserDList popBackUserDList(UserDList uli);

/**
 * @brief Pops an user node from the beginning of the given user dlist
 * 
 * @param uli {UserDList} : user dlist from which a node will be poped
 * @return UserDList 
 */
UserDList popFrontUserDList(UserDList uli);

/**
 * @brief Prints the content of an user dlist
 * 
 * @param eli {UserDlist} : list to print
 */
void printUserDList(UserDList uli);

/**
 * @brief Clears an user dlist content
 * 
 * @param uli {UserDlist} : user dlist to clear
 * @return UserDList 
 */
UserDList clearUserDlist(UserDList uli);

#endif
