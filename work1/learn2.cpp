#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char djm[1000];

int id,winner,type;

int type_num=10;

double prob[10000];

double value,bid,pay;

int main(int argc,char *argv[])
{
	id=atoi(argv[1]);
	winner=atoi(argv[2]);
	sscanf(argv[3],"%lf",&pay);
	sprintf(djm,"helper%d.txt",id);
	freopen(djm,"r",stdin);
	scanf("%d%lf%lf",&type,&value,&bid);

	sprintf(djm,"learn_result%d.txt",id);
	freopen(djm,"r",stdin);
	for (int a=1;a<=type_num;a++)
		scanf("%lf",&prob[a]);
	
	if (id==winner) prob[type]+=value-pay;
	else
	{
		for (int a=1;a<type;a++)
			prob[a]+=0.05;
	}

	freopen(djm,"w",stdout);
	for (int a=1;a<=type_num;a++)
		printf("%lf\n",prob[a]);

	return 0;
}

