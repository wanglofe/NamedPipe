#include "pipe.h"

int CreatePipe(char *name, mode_t mode)
{
	return mkfifo(name, mode);
}

int GetPipe(char *name, int flags)
{
	return open(name, flags);
}

int RcvMsg(int fd, void *msg, size_t len, size_t timeout)
{
	switch (timeout) {
		case 0: 
			return len == read(fd, msg, len);
		default:
		{
			fd_set readset;
			FD_ZERO(&readset);
			FD_SET(fd, &readset);
			struct timeval tv = {timeout, 0};
			int retval = select(fd+1,&readset,NULL,NULL,&tv);
			if(retval == -1) {
				printf("error select\n");	
			} else if(retval) {
				if(FD_ISSET(fd, &readset)) {
					return len == read(fd, msg, len);
				}
			} else {
				printf("timeout\n");
				return 0;
			}
		}
	}
}

int SndMsg(int fd, void *msg, size_t len)
{
	return len == write(fd, msg, len);
}

