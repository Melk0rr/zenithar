#include "group.h"
#include "zenithar.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	signed char *groupName = getSecureInputSignedChar("Group name: ", 256);
	group *testGroup = createGroup(groupName);

	int numberOfMembers = getSecureInputInt("How many users are in this group ? ", 4);

	for (int i = 0; i < numberOfMembers; i++)
	{
		char buffer[50];
		sprintf(buffer, "What is the name of user %d ? ", i + 1);

		signed char *currentUsrName = getSecureInputSignedChar(buffer, 256);
		user *currentUsr = createUser(currentUsrName);
		
		addGroupMember(testGroup, currentUsr);
	}
	
	printf("%s : %d\n", testGroup->groupName, testGroup->memberCount);

	free(testGroup->members);
	free(testGroup);
	return 0;
}
