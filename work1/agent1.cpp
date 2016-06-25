#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char djm[1000];

double value;

int id;

int main(int argc,char *argv[])
{
	id=atoi(argv[1]);
	sscanf(argv[2],"%lf",&value);
	sprintf(djm,"result%d.txt",id);
	freopen(djm,"w",stdout);
	printf("0\n");

	return 0;
}
