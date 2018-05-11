#include "pipe.h"
#include <string.h>

int main(void)
{
	msg_t msgpkg[3];
	uint8_t msgdata[10] = {0,1,2,3,4,5,6,7,8,9};
	int fd = GetPipe(MSGPIPE, 0666);
	
	for(int i=0; i<3; i++) {
		memcpy(msgpkg[i].data, msgdata, sizeof(msgdata));
		msgpkg[i].size = sizeof(msgdata);
		SndMsg(fd, &msgpkg[i], sizeof(msg_t));
		sleep(3);
	}
}
