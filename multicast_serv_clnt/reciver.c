#include<stdio.h>
	join_addr.imr_interface.s_addr=htonl(INADDR_ANY);
	setsockopt(sock,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void*)&join_addr,sizeof(join_addr));

	if(bind(sock,(struct sockaddr*)&addr,sizeof(addr))==-1)
		error_handling("bind error");
	while(1)
	{
		str_len=recvfrom(sock,buf,BUF_SIZE-1,0,NULL,0);
		if(!str_len)
			break;
		buf[str_len]=0;
		fputs(buf,stdout);
	}
	close(sock);
	return 0;
}
void error_handling(const char* message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}