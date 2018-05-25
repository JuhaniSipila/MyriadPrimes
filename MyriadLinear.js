/*
Linear Myriad prime sieve v1.1 19.5.2018
Author: Juhani Sipila
Aalto University - Systems Analysis Laboratory
*/
function G(n){
	//all P>5 can be expressed as 6a+-1 - Bungus 1599, Wells 1986
	return 3*n+(n&1==1?2:1);
}

function I(n,m){
	return 3*n*m+n*(m&1==1?2:1)+m*(n&1==1?2:1)+((n&1==1)&&(m&1==1)?1:0);
}

function MyriadSieveLinear(limit){
	//maximum index of the interval
	var Imax = Math.floor(limit/3);
	var lpi = Array(1+Imax).fill(0); //lowest prime indices
	//interval = Array(1+limit);
	var x = 1;
	var y = 1;
	var Icur = 8;
	var yLim;

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

	primes=[];								//push primes to an array
	primes.push(2);
	primes.push(3);
	var i=1;
	while(i<Imax){
		if(lpi[i]==0){
			primes.push(G(i));
		}
		i++;
	}
	g=G(i); //account for 'non-G' limits
	if(g<=limit && lpi[i]==0){primes.push(g)}

	return primes;
}