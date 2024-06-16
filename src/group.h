#include "user.h"

/**
 * @brief Group of users to share expenses
 * 
 */
typedef struct group
{
  signed char groupName[256];
  user *members;
  int memberCount;
} group;

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
void addGroupMember(group *grp, user newMember);