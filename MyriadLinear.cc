/*
Linear Myriad prime sieve v1.1 19.5.2018
Author: Juhani Sipilä
Aalto University - Systems Analysis Laboratory
*/
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

long long G(long long n){
	//All primes>5 can be expressed as 6a+-1 - Bungus 1599, Wells 1986
	return 3*n+((n&1)==1?2:1); //optimized 6*floor((n+1)/2)+(-1)^n
}

long long I(long long x,long long y){
	//optimized I=floor(G(x)*G(y)/3)
	return 3*x*y+x*((y&1)==1?2:1)+y*((x&1)==1?2:1)+((((x&1)==1)&&((y&1)==1))?1:0);
}

void MyriadSieveLinear(long long limit){
	//init sieving range
	long long Imax = limit/3; 				//NOTE: floor(limit/3)
	
	vector<long long> lpi(1+Imax);			//Lowest Prime Indices
	fill(lpi.begin(), lpi.end(), 0);		//Set all elements to 0. >0 indicates composite!

	//init variables for looping
	long long x = 1;						//start from x=y=1 i.e. composite 25
	long long y = 1;
	long long Icur = 8;						//init current index. floor(25/3)=8
	long long yLim = 1;						//init yLim(x)! lpi[x], x or I_x <=Imax

	while(Icur<=Imax){						//horizontal loop
		//5's multiples are always crossable as it is the lowest prime in G! floor(5/3)=1
		lpi[Icur] = 1;						//crossed off xth 5's multiple (y=1)
		y = 2;								//increment y ==> y=2
		yLim = (lpi[x]!=0?lpi[x]:x);
		while(y<=yLim){						//vertical loop
			if(lpi[y]!=0){y++; continue;}	//skip composite rows
			Icur = I(x,y);					//calculate next current index
			if(Icur>Imax){break;}			//is the index out of search space?
			lpi[Icur] = y;					//crossed off Icur and saved its lowest prime index
			y++;
		}									//columns relevant elements crossed off
		x++;								//move horizontally
		Icur = I(x,1);						//prepare for next iteration
	}										//all composites <=G_max=G(Imax) crossed off

	long long i = 1;						//init output iterator
	long long g = 5;						//init output to smallest prime in G
	long long pi = 2;
	cout << 2 << endl;						//manually output 2 & 3 since they aren't in space G
	cout << 3 << endl;						//assuming limit>3
	while(i<=Imax){
		if(lpi[i]==0){						//lpi=0 ==> G(i) is prime
			g = G(i);
			if(g>limit){break;}				//stop output
			cout << g << endl;
			pi++;
		}
		i++;
	}
	cout << "PI(N): " << pi << endl;
}

int main(){
	auto t0 = chrono::steady_clock::now();
	long long lim = 1000000000;
	MyriadSieveLinear(lim);
	auto t1 = chrono::steady_clock::now();
	auto dt = t1-t0;
	cout << "Runtime " << chrono::duration <double, milli> (dt).count() << " ms" << endl;
	return 0;
}
