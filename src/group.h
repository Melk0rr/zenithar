#ifndef __GROUP__H__
#define __GROUP__H__

#include "user.h"
#include "user_dlist.h"

// #########################################################
// Group struct definition

/**
 * @brief Group of users to share expenses
 *
 */
typedef struct group
{
  // Group name
  char groupName[25];

  // Member list which contains users
  UserDList * members;
} group;

// #########################################################
// Prototypes

/**
 * @brief Create a new Group
 *
 * @param grpName {const signed char} : group name
 * @param members {user} : members of the group
 * @param numberOfMembers {int} : number of members
 * @return group* : new group
 */
group * createGroup(char const * const grpName);

/**
 * @brief Initialize a group's member list
 *
 * @param grp {group} : targeted group
 * @param members {user} : member list
 * @param numberOfMembers {int} : number of members for memory allocation
 */
void initGroupMembers(group * const grp, user * const members, size_t const numberOfMembers);

/**
 * @brief Adds a user into the group's member list
 *
 * @param grp {group} : targeted group
 * @param newMember {user} : user to add
 */
void addGroupMember(group * const grp, user * const newMember);

/**
 * @brief Creates a new user with given username and adds it into the group's
 * member list
 *
 * @param grp {group} : group in which the new user will be added
 * @param userName {const signed char *} : username for the new user
 */
void addNewGroupMember(group * const grp, char const * userName);

/**
 * @brief Removes the given user from members of the provided group
 *
 * @param grp {group} : group from which the member will be removed
 * @param member {usr} : member to remove
 */
void removeGroupMember(group * const grp, user * const member);

/**
 * @brief Clears group members
 *
 * @param grp {group} : the group the members will be cleared
 */
void clearGroupMembers(group * const grp);

/**
 * @brief Prints group member name
 *
 * @param grp {group} : group to print member of
 */
void printMemberNames(group * const grp);

/**
 * @brief Prints the balance for each group member
 *
 * @param grp {group} : target group
 */
void getGroupBalance(group * const grp);

/**
 * @brief Resets expenses of group members
 *
 * @param grp {group} : target group
 */
void resetGroupExpenses(group * const grp);

#endif
