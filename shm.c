#include "param.h"
#include "types.h"
#include "defs.h"
#include "x86.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

struct {
  struct spinlock lock;
  struct shm_page {
    uint id;
    char *frame;
    int refcnt;
  } shm_pages[64];
} shm_table;

void shminit() {
  int i;
  initlock(&(shm_table.lock), "SHM lock");
  acquire(&(shm_table.lock));
  for (i = 0; i< 64; i++) {
    shm_table.shm_pages[i].id =0;
    shm_table.shm_pages[i].frame =0;
    shm_table.shm_pages[i].refcnt =0;
  }
  release(&(shm_table.lock));
}

// Get a shared memory page by its id
// Returns a pointer to the shm_page or 0 if it could not be found
shm_page * shm_get_page(int id) {
  for (int i = 0; i < 64; i++) {
    if (shm_table.shm_pages[i].id == id) {
      return shm_table_pages + i;
    }
  }
  
  cprintf("Error: no page with id: %u", id);
  return 0;
}

int shm_open(int id, char **pointer) {

//you write this




return 0; //added to remove compiler warning -- you should decide what to return
}


int shm_close(int id) {
//you write this too!


return 0; //added to remove compiler warning -- you should decide what to return
}

