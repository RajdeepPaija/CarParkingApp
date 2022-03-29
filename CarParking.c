#include <stdio.h>
#include <stdlib.h>
static char park[3][6]={{'0','0','0','0','0','0'},//taking static ary bcuz changes will remains same
						{'0','0','0','0','0','0'},
						{'0','0','0','0','0','0'}};
void car_in(void);//func for parking the car
void car_out(void);//func for getting car exit status
void park_status(void);//func which showing the current status about the parking
int park_check(void);//func which allocating parking id

int main()
{
	int opt;
	while(1)
	{
		printf("enter the option:\n (1)CAR IN\n (2)CAR OUT\n (3)STATUS\n (4)EXIT\n");
		scanf(" %d",&opt);
		switch(opt)
		{
			case 1: car_in();break;
			case 2:car_out();break;
			case 3:park_status();break;
			case 4:printf("------------Thank You! visit Again!-----------\n");
					exit(0) ;
			default:printf("-----------USAGE:choose correct option-------\n");
		}
	}
	return 0;
}
void car_in(void)
{
	int park_id=park_check();
	if(park_id != -1)
	{
		park[park_id/10][park_id%10] = '*';
		printf("\tyour park id is:%d\n",park_id);
	}
	else
		printf("\tNo space for parking\n");
}
int park_check(void)
{
	int index,index2,park_id;
	for(index=0;index<3;index++)
		for(index2=0;index2<6;index2++)
			if(park[index][index2] == '0')
			{
			park_id =index*10 +index2;
			return park_id;
			}
return -1;
}
void car_out(void)
{
	int park_id;
	printf("\tenter the parking id:\n");
	scanf("%d",&park_id);
	if(park[park_id/10][park_id%10] == '*')
	{
		park[park_id/10][park_id%10] ='0';
		printf("\tcar exited successfully\n");
	}
	else
		printf("\tcar is already vacant\n");
}
void park_status(void)
{
	int index,index2;
	printf("----------status of parking------------\n\n");
	for(index=0;index<3;index++)
	{
		printf("\tpark row->%d\t",index);
		for(index2=0;index2<6;index2++)
			printf(" %c ",park[index][index2]);
		printf("\n\n");
	}
	printf("\n (*) - filled\t(0) - Available\n");
}




