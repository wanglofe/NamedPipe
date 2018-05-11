#include "pipe.h"

int main(void)
{
	msg_t msgpkg;
	CreatePipe(MSGPIPE, 0666);
	int fd = GetPipe(MSGPIPE, 0666);
	while (RcvMsg(fd, &msgpkg, sizeof(msg_t), 5) > 0)
	{
		for(int i =0; i<(msgpkg.size); i++)
			printf("#%d ", (int)msgpkg.data[i]);
		putchar('\n');
	}
}
