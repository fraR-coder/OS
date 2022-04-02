#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct lock_s {
  int ticketNumber;
  int turnNumber;
} lock_t;

int atomicIncrement (int *var) {
  int tmp = *var;
  *var = tmp + 1;
  return (tmp);
}

void init (lock_t lock) {
  lock.ticketNumber = 0;
  lock.turnNumber = 0;
}

void lock (lock_t lock) {
  int myTurn = atomicIncrement (&lock.ticketNumber);
  while (lock.turnNumber != myTurn);
}

void unlock (lock_t lock) {
  atomicIncrement (&lock.turnNumber);
}

int main(int argc, char** argv)
{


    return 0;

}