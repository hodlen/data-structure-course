#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode {
  ElemType data;
  LNode *next;
} LNode;

#ifndef CLNode
#define CLNode LNode
#endif

void MergeCircularLink(CLNode *h1, CLNode *h2, CLNode *&h3) {
  CLNode *h1n = h1->next;
  h1->next = h2->next;

  CLNode *p;
  for (p = h2->next; p->next != h2; p = p->next)
    ;
  p->next = h1n;
  delete h2;

  h3 = h1;
  return;
}

int main(void) {
  LNode *list1 = new LNode;
  list1->data = 0xF0000000;
  LNode *p = list1;
  for (int i = 1; i < 6; i++) {
    p->next = new LNode;
    p->next->data = 2 * i - 1;
    p = p->next;
  }
  p->next = list1;

  LNode *list2 = new LNode;
  list2->data = 0xF0000000;
  p = list2;
  for (int i = 1; i < 6; i++) {
    p->next = new LNode;
    p->next->data = i * 2;
    p = p->next;
  }
  p->next = list2;

  LNode *NewList;
  MergeCircularLink(list1, list2, NewList);

  return 0;
}