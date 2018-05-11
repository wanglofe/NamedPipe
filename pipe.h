#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdint.h>
#define MSGPIPE "./MSGPIPE"
#define MaxMsgLen 1024


typedef struct msg {
	uint8_t data[MaxMsgLen];
	size_t size;
} msg_t;

int CreatePipe(char *name, mode_t mode);
int GetPipe(char *name, int flags);
int RcvMsg(int fd, void *msg, size_t len, size_t timeout);
int SndMsg(int fd, void *msg, size_t len);
