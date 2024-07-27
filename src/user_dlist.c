#include "user_dlist.h"

#include <stdio.h>
#include <stdlib.h>

// Function to create an empty user dlist : see user_dlist.h
UserDList newUserDList()
{
  UserDList uli;
  return uli;
}

// Function check if a User dlist is empty : see user_dlist.h
bool isUserDListEmpty(UserDList uli)
{
  if (uli == NULL)
  {
    return true;
  }
  
  return false;
}

// Function to return user dlist length : see user_dlist.h
int userDListLength(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    return 0;
  }
  
  return uli->length;
}

// Function to retreive first element of user dlist : see user_dlist.h
user getFirstUserDListNode(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    exit(1);
  }

  return uli->begin->nodeUser;
}

// Function to retreive the last element of user dlist : see user_dlist.h
user getLastUserDListNode(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    exit(1);
  }

  return uli->end->nodeUser;
}

// Function to push a new user at the end of an user dlist : see user_dlist.h
UserDList pushBackUserDList(UserDList uli, user usr)
{
  UserDListNode *usrNode = malloc(sizeof(*usrNode));
  
  if (usrNode == NULL)
  {
    fprintf(stderr, "pushBackUserDList::Memory allocation failed for new UserDListNode !");
    exit(1);
  }

  usrNode->nodeUser = usr;
  usrNode->prev = NULL;
  usrNode->next = NULL;
  
  if (isUserDListEmpty(uli))
  {
    uli = malloc(sizeof(*uli));

    if (uli == NULL)
    {
      fprintf(stderr, "pusBackUserDList::Memory allocation failed for empty UserList !");
      exit(1);
    }
    
    // If dlist is empty : new node is the first and last element
    uli->length = 0;
    uli->begin = usrNode;
    uli->end = usrNode;

  } else {
    // If dlist is not empty : Last dlist element next pointer now points to new node
    uli->end->next = usrNode;

    // New node prev pointer now points to the previous last dlist element
    usrNode->prev = uli->end;
    
    // And dlist end now points to the new node
    uli->end = usrNode;
  }
  
  uli->length++;
  return uli;
}