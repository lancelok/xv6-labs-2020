#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p2s[2],s2p[2];
  char x;

  pipe(p2s);
  pipe(s2p);

  if(fork() == 0){
	  close(s2p[0]);
	  close(p2s[1]);
	  read(p2s[0],&x,1);
	  fprintf(1,"%d: received ping\n", getpid());
	  write(s2p[1],&x,1);

  }else{
	  close(p2s[0]);
	  close(s2p[1]);
	  write(p2s[1],&x,1);
	  read(s2p[0],&x,1);
	  fprintf(1,"%d: received pong\n", getpid());
  }
  exit(0);
}
