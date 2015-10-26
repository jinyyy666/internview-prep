ListNode * findFifth(ListNode * head){
  // chech the size of list:
  ListNode * cur = head;
  int size = 0;
  while(cur){
    size++;
    cur = cur->next;
  }
  if(size < 5)
    return NULL;
  
  while(cur.next.next.next.next.next){
    cur = cur.next;
  }
  return cur;

}
