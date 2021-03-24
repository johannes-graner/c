
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* createNode(int val){
  struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));

  if (!ptr)
    return NULL;

  ptr->next = NULL;
  ptr->val = val;

  if (!(ptr->val)){
    free(ptr);
    return NULL;
  }

  return ptr;  
}

struct ListNode* buildList(int* list, int listSize) {
  struct ListNode *ret, *curr;
  ret = createNode(list[0]);
  curr = ret;
  for (int i = 1; i < listSize; i++)
  {
    curr->next = createNode(list[i]);
    curr = curr->next;
  }
  //free(curr->next);
  return ret;
}

void dealloc_list(struct ListNode *list) {
  if (!list) {
    return;
  }
  dealloc_list(list->next);
  free(list);
  return;  
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
  struct ListNode *ret;
  struct ListNode *retDummy = (struct ListNode *)malloc(sizeof(struct ListNode));
  ret = retDummy;
  int i, min_index;
  int min = INT_MAX;
  int done = 0;
  
  while ( done == 0 ) {
    done = 1;
    min = INT_MAX;

    for ( i = 0; i < listsSize; i++) {
      if (lists[i] && lists[i]->val <= min ) {
        min = lists[i]->val;
        min_index = i;
        done = 0;
      }
    }
    if (done == 0) {
      retDummy->val = min;
      retDummy->next = (struct ListNode *)malloc(sizeof(struct ListNode));
      retDummy = retDummy->next;
      lists[min_index] = lists[min_index]->next;
    }
  }

  return ret;
}

int main() {
  int listsSize = 3;
  struct ListNode **lists = malloc(listsSize*sizeof(struct ListNode));
  lists[0] = buildList((int[3]){1,4,5}, 3);
  lists[1] = buildList((int[3]){1,3,4}, 3);
  lists[2] = buildList((int[2]){2,6}, 2);
  
  struct ListNode *merged = mergeKLists(lists, listsSize);
  while( merged->next )
  {
    printf("%d ", merged->val);
    merged = merged->next;
  }
  printf("\n");
  
  for (int i = 0; i < listsSize; i++)
  {
    dealloc_list(lists[i]);
  }
  
  dealloc_list(merged);
  free(lists);

  return 0;
}