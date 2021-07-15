#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int
main(int argc, char *argv[])
{
  int ticknum;
  if(argc < 2)
	  fprintf(2, "num wrong%d\n", argc);
  ticknum = atoi(argv[1]);
  //fprintf(1, "ticknum:%d\n", ticknum);
  sleep(ticknum);

  exit(0);
}
