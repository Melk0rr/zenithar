#include "user_dlist.h"

#include <cstddef>
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

// Function to push a new user at the beginning of an user dlist : see user_dlist.h
UserDList pushFrontUserDList(UserDList uli, user usr)
{
  UserDListNode *usrNode = malloc(sizeof(*usrNode));
  
  if (usrNode == NULL)
  {
    fprintf(stderr, "pushFrontUserDList::Memory allocation failed for new UserDListNode !");
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
      fprintf(stderr, "pushFrontUserDList::Memory allocation failed for empty UserList !");
      exit(1);
    }
    
    // If dlist is empty : new node is the first and last element
    uli->length = 0;
    uli->begin = usrNode;
    uli->end = usrNode;

  } else {
    // If dlist is not empty : Last dlist element next pointer now points to new node
    uli->begin->prev = usrNode;

    // New node prev pointer now points to the previous last dlist element
    usrNode->next = uli->begin;
    
    // And dlist end now points to the new node
    uli->begin = usrNode;
  }
  
  uli->length++;
  return uli;
}

// Function to pop an user node from given list end : see user_dlist.h
UserDList popBackUserDList(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    printf("popBackUserDList::List is empty. Nothing to pop.\n");
    return newUserDList();
  }
  
  // Check if the list contains only one element
  if (uli->begin == uli->end)
  {
    free(uli);
    uli = NULL;

    return newUserDList();
  }
  // Saves the last element
  UserDListNode *tmp = uli->end;

  // Last node is now the second to last
  uli->end = uli->end->prev;

  // The new last node next pointer is now NULL as it is the last element
  uli->end->next = NULL;

  // Deleting removed node links to prev and next
  tmp->next = NULL;
  tmp->prev = NULL;

  free(tmp);
  tmp = NULL;

  uli->length--;

  return uli;
}

// Function to pop an user node from given list beginning : see user_dlist.h
UserDList popFrontUserDList(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    printf("popBackUserDList::List is empty. Nothing to pop.\n");
    return newUserDList();
  }
  
  // Check if the list contains only one element
  if (uli->begin == uli->end)
  {
    free(uli);
    uli = NULL;

    return newUserDList();
  }
  // Saves the first element
  UserDListNode *tmp = uli->begin;

  // First node is now the second to first
  uli->begin = uli->begin->next;

  // The new first node prev pointer is now NULL as it is the first element
  uli->begin->prev = NULL;

  // Deleting removed node links to prev and next
  tmp->next = NULL;
  tmp->prev = NULL;

  free(tmp);
  tmp = NULL;

  uli->length--;

  return uli;
}

// Function to remove a specific user from a user dlist : see user_dlist.h
UserDList popUserFromDList(UserDList uli, user usr)
{
  if (isUserDListEmpty(uli))
  {
    printf("printUserDlist::List is empty, nothing to print");
    return newUserDList();
  }
    
  UserDListNode *temp = uli->begin;

  while (&temp->nodeUser != &usr)
  {
    temp = temp->next;
  }

  // If list only contains one element
  if (uli->begin == uli->end)
  {
    free(uli);
    uli = NULL;

    return newUserDList();
  }
  // If first in list
  else if (temp->prev == NULL)
  {
    return popFrontUserDList(uli);
  }
  // If last in list
  else if (temp->next == NULL) {
    return popBackUserDList(uli);
  }
  else {
    // Pointing previous node to the next and vice versa
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    temp->prev = NULL;
    temp->next = NULL;

    free(temp);
    temp = NULL;

    uli->length--;

    return uli;
  }
}

// Function to print the content of an user dlist : see user_dlist.h
void printUserDList(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    printf("printUserDlist::List is empty, nothing to print");
    return;
  }
  
  UserDListNode *temp = uli->begin;
  
  while (temp->next != NULL) {
    printf("%s : %f\n", temp->nodeUser.userName, temp->nodeUser.expenseSum);
    temp = temp->next;
  }
}

// Function to clear a user dlist content : see user_dlist.h
UserDList clearUserDlist(UserDList uli)
{
  while(!isUserDListEmpty(uli))
  {
    uli = popBackUserDList(uli);
  }
  
  return newUserDList();
}