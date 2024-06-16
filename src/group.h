#include "user.h"

typedef struct group
{
  signed char groupName[256];
  user *members;
  int memberCount;
} group;

void initGroupMembers(group *grp, user *members, int numberOfMembers);
void addGroupMember(group *grp, user newMember);