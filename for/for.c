#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main(){
	for(int farg = LOWER; farg <= UPPER; farg = farg + 20){
		printf("%3d%6.1f\n",farg, (5.0/9.0)*(farg-32));
	}
}
