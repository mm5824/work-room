#include <stdio.h>
#include <stdlib.h>

	

int *najdi_najdlhsi_monotonny_usek(int *p, int lp, int *ip)
{

	int mon_length;
	int max_mon_length;

	int *mon_start=p;
	int *max_mon_start;

	int i=0;

	while(i<lp)
	{
		mon_length=1;
		max_mon_start=&p[i];

		while(i<lp && p[i]==p[i+1])
		{
			mon_length++;
			i++;
		}

		if(mon_length>max_mon_length)
		{
			max_mon_length=mon_length;
			mon_start=max_mon_start;
		}

		i++;
	}

*ip=max_mon_length;
return max_mon_start;

}


int main () {

int p[10]={8,8,8,7,4,5,5,5,5,1};
int lp=10;
int ip;

printf("%d", *najdi_najdlhsi_monotonny_usek(p,lp,&ip));
printf("\nmonotonnost ma dlzku: %d", ip);

}
			
	


