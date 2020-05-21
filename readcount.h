
#include "spinlock.h"
#include "types.h"

typedef struct __readcount_t {
  int inited;
  struct spinlock lock;
  int count;
} readcount_t;

void
init_readcount(readcount_t* rc);

void
increment_readcount(readcount_t* rc);

int 
get_readcount(readcount_t* rc);