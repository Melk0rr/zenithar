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
  signed char groupName[25];

  // Member list which contains users
  UserDList members;
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
group *createGroup(const signed char *grpName);

/**
 * @brief Initialize a group's member list
 * 
 * @param grp {group} : targeted group
 * @param members {user} : member list
 * @param numberOfMembers {int} : number of members for memory allocation
 */
void initGroupMembers(group *grp, user *members, int numberOfMembers);

/**
 * @brief Adds a user into the group's member list
 * 
 * @param grp {group} : targeted group
 * @param newMember {user} : user to add
 */
void addGroupMember(group *grp, user *newMember);

/**
 * @brief Creates a new user with given username and adds it into the group's member list
 * 
 * @param grp {group} : group in which the new user will be added
 * @param userName {const signed char *} : username for the new user
 */
void addNewGroupMember(group *grp, const signed char *userName);

/**
 * @brief Removes the given user from members of the provided group
 * 
 * @param grp {group} : group from which the member will be removed
 * @param member {usr} : member to remove
 */
void removeGroupMember(group *grp, user *member);

/**
 * @brief Clears group members
 * 
 * @param grp {group} : the group the members will be cleared
 */
void clearGroupMembers(group *grp);

/**
 * @brief Prints group member name
 * 
 * @param grp {group} : group to print member of
 */
void printMemberNames(group *grp);

/**
 * @brief Sums the group expenses
 * 
 * @param grp {group} : target group
 * @return int : sum of the group expenses
 */
float sumGroupExpenses(group *grp);

/**
 * @brief Prints the balance for each group member
 * 
 * @param grp {group} : target group
 */
void getGroupBalance(group *grp);

/**
 * @brief Resets expenses of group members
 * 
 * @param grp {group} : target group
 */
void resetGroupExpenses(group *grp);

/**
 * @brief Retreives a group member by name
 * 
 * @param grp {group} : the group the user is member of
 * @param userName {const signed char *} : user name
 * @return user* : the member or NULL
 */
user *getMemberByName(group *grp, const signed char *userName);

#endif
