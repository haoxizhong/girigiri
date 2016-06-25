#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char djm[1000];

double value;

double prob[10000];

int id;

int type_num=20;

double get_value(double value,int type)
{
	return value*type/20;
}

int main(int argc,char *argv[])
{
	id=atoi(argv[1]);
	sscanf(argv[2],"%lf",&value);
	int seed=atoi(argv[3]);
	srand(seed);
	sprintf(djm,"learn_result%d.txt",id);
	freopen(djm,"r",stdin);
	for (int a=1;a<=type_num;a++)
	{
		scanf("%lf",&prob[a]);
		prob[a]+=prob[a-1];
	}
	for (int a=1;a<=type_num;a++)
		prob[a]/=prob[type_num];
	double v=(double)rand()/RAND_MAX;
	int type;
	for (int a=type_num;a>=0;a--)
		if (v>prob[a])
		{
			type=a+1;
			break;
		}

	sprintf(djm,"helper%d.txt",id);
	freopen(djm,"w",stdout);
	printf("%d %lf %lf\n",type,value,get_value(value,type));

	sprintf(djm,"result%d.txt",id);
	freopen(djm,"w",stdout);
	printf("%lf\n",get_value(value,type));

	return 0;
}
