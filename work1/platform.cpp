#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int max_player=100;

char djm[1000];

int num_player=2,winner;

double value[max_player];

double result[max_player];

double gen_value(double l,double r)
{
	return (double)rand()/RAND_MAX*(r-l)+l;
}

void mechanism()
{
	int res=1;
	for (int a=1;a<=num_player;a++)
		if (result[a]>result[res]) res=a;
	winner=res;
}

int main(int argc,char *argv[])
{
	int init=atoi(argv[1]);
	if (init==1)
	{
		for (int a=1;a<=num_player;a++)
		{
			sprintf(djm,"learn_result%d.txt",a);
			freopen(djm,"w",stderr);
			for (int a=1;a<=max_player;a++)
				fprintf(stderr,"1\n");
			fclose(stderr);
		}
	}
	int round=0;
	while (true)
	{
		round++;
		if (round%10000==0) printf("%d\n",round);
		for (int a=1;a<=num_player;a++)
			value[a]=gen_value(0,1);
		for (int a=1;a<=num_player;a++)
		{
			sprintf(djm,"./agent%d %d %lf %d",a,a,value[a],rand());
			system(djm);
			sprintf(djm,"result%d.txt",a);
			freopen(djm,"r",stderr);
			fscanf(stderr,"%lf",&result[a]);
			fclose(stderr);
		}
		mechanism();
		for (int a=1;a<=num_player;a++)
		{
			sprintf(djm,"./learn%d %d %d %lf",a,a,winner,result[winner]);
			system(djm);
		}
	}


	return 0;
}
