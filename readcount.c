#include "readcount.h"

void
init_readcount(readcount_t* rc) {
  if (!rc) {
    return;
  }

  if (rc->inited) {
    return;
  }

  rc->inited = 1;
  initlock(&rc->lock, "readcount");
  rc->count = 0;
}

void
increment_readcount(readcount_t* rc) {
  if (!rc) {
    return;
  }

  acquire(&rc->lock);
  rc->count++;
  release(&rc->lock);
}

int get_readcount(readcount_t* rc) {
  int lreadcount = 0;

  acquire(&rc->lock);
  lreadcount = rc->count;
  release(&rc->lock);
  
  return lreadcount;
}