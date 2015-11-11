#include "msgs.h"

void server1()
{
	int rp = 0;
	int sp = 1;
	int i = 0;
	struct message m;

	while(1)
	{
		m = Receive(rp);
		
		printf("\ndata received at server 1 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
		for(i = 0 ; i < 10 ; i ++ )m.data[i]++;
		Send(sp, &m);
		printf("\ndata sent at server 1 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
	}
}

void server2()
{
	int rp = 2;
	int sp = 3;
	int i = 0;
	struct message m;

	while(1)
	{
		m = Receive(rp);
		printf("\ndata received at server 2 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
		for(i = 0 ; i < 10 ; i ++ )m.data[i]++;
		Send(sp, &m);
		printf("\ndata sent at server 2 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
	}

}

void client1()
{
	int sp = 0;
	int rp = 1;
	int i = 0;
	struct message m;

	for(i = 0 ; i < 10 ; i ++ )m.data[i] = 0;
	

	while(1)
	{
		Send(sp, &m);	
		printf("\ndata sent at client 1 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
		m = Receive(rp);
		printf("\ndata received at client 1 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
	}

}

void client2()
{
	int sp = 2;
	int rp = 3;
	int i = 0;
	struct message m;

	for(i = 0 ; i < 10 ; i ++ )m.data[i] = 1000;

	while(1)
	{
		Send(sp, &m);	
		printf("\ndata sent at client 2 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
		m = Receive(rp);
		printf("\ndata received at client 2 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
	}
}

void client3()
{
	int sp = 0;
	int rp = 1;
	int i = 0;
	struct message m;

	for(i = 0 ; i < 10 ; i ++ )m.data[i] = 2000;

	while(1)
	{
		Send(sp, &m);	
		printf("\ndata sent at client 3 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
		m = Receive(rp);
		printf("\ndata received at client 3 :");
		for( i = 0 ; i < 10 ; i ++) printf("%d ", m.data[i]);
		printf("\n");
	}

}

void main()
{
	init_port();
	start_thread(server1);
	start_thread(client1);
	start_thread(server2);
	start_thread(client2);
	start_thread(client3);
	run();
}

