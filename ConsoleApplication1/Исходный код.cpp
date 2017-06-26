#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

const int n = 20;
const int h = 6;

int x_0 = 0;
int x_n = n;
int y_0 = 0;
int y_n = n;

int k[n][n];


void main(){
	srand(time(0));
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j)
		k[i][j]=0;
	int i = 0;
	k[0][0] = 1;
	
	for (int j=1;j<n;++j){
		k[i][j] = (rand()%6>2)?1:0;
	}
	for (int i=1;i<n;++i)
	for (int j=0;j<n;++j)
	for (int u=0;u<2;++u){
		switch(j){
		case 0:
			if (		//_0_0_
						//_x_0	
					(	k[i-1][0]==0	&&	k[i-1][1]==0	&&	k[i][1]==0	)	||
						//_1_0_
						//_x_0_
					(	k[i-1][0]==1	&& k[i-1][1]==0	&&	k[i][1]==0	)	||
						//_1_0_
						//_x_1_
					(	k[i-1][0]==1	&&	k[i-1][1]==0	&&	k[i][1]==1	)
				)
			{
				k[i][j] = 1;
			}
			if (		//_0_0_
						//_x_1_	
					(	k[i-1][0]==0	&&	k[i-1][1]==0	&&	k[i][1]==1	)	||
						//_0_1_
						//_x_0_
					(	k[i-1][0]==0	&& k[i-1][1]==1	&&	k[i][1]==0	)	||
						//_0_1_
						//_x_1_
					(	k[i-1][0]==0	&&	k[i-1][1]==1	&&	k[i][1]==1	)	||
						//_1_1_
						//_x_0_
					(	k[i-1][0]==1	&&	k[i-1][1]==1	&&	k[i][1]==0	)
				)
			{
				k[i][j] = rand()%2;
			}
			if (		//_1_1_
						//_x_1_
					k[i-1][0]==1	&&	k[i-1][1] ==1	&&	k[i][1]==1
				)
			{
				k[i][0] = 0;
			}
			break;

		case n-1:
			if (	(k[i-1][j]!=0&&k[i-1][j-1]==0)	){
				k[i][j] = 1;
			}
			break;

		default:
			if (	k[i-1][j-1]==0 && k[i-1][j]==0 && k[i-1][j]!=0	){
				k[i][j] = 1;
			}
			if ( k[i-1][j-1]==0 && k[i-1][j]==0 &&k[i][j-1]==0){
				k[i][j] = 1;
			}
			if (	k[i-1][j]==0 && k[i][j-1]!=0 && k[i-1][j-1]!=0	){
				k[i][j] = 1;
			}
			if (	k[i-1][j-1]==0 && k[i-1][j] !=0 && k[i-1][j+1]==0){
				k[i][j]=1;
			}
			if (	k[i-1][j-1]==0 && k[i-1][j]!=0 && k[i-1][j+1]!=0){
				k[i][j]=rand()%2;
			}
			if (k[i-1][j-1]!=0 && k[i-1][j] != 0 && k[i][j-1]==0){
				k[i][j] = 1;
			}
			if (	k[i-1][j+1]==1 && k[i][j+1]==1){
				k[i][j] = 1;
			}

			break;
		}
	}
	int m[n+2][n+2];
	for (int i=0;i<n+2;++i)
		for (int j=0;j<n+2;++j)
		{ 
			if (k[i-1][j-1]==1&&	(j==1||i==n-1||j==n-1||i==1)){
				x_n = i;
				y_n = j;
			}
			if (i==0||i==n+1||j==0||j==n+1){ 
				m[i][j]=0;
			} else {
				m[i][j] = k[i-1][j-1];
			}
		}
	m[0][1]=1;
	if (y_n>n/2) {
		while (y_n<n+1){
			m[x_n][y_n+1]=1;
			++y_n;
		}
	} else {
		while (y_n>-2){
			m[x_n][y_n+1]=1;
			--y_n;
		}
	}

	
	for(int i=0;i<n+2;++i){
		for(int j=0;j<n+2;++j)
		{
			//if (k[i][j]==0) k[i][j] = (rand()%4>2)?1:0;
			if (m[i][j]!=0){ 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xB);
			} else {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x2); }
			cout<<m[i][j]<<" ";
		}
		cout<<"\n";
	}
	cin.seekg(0);
	cin.ignore();
}
