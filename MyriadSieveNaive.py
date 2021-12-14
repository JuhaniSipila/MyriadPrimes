import sys
import time

def G(n):
	#all P>5 can be expressed as 6a+-1 - Bungus 1599, Wells 1986
	return 6*((n+1)//2)+(-1 if n&1==1 else 1)

def I(n,m):
	return (G(n)*G(m)//3)

def MyriadSieveNaive(limit):
	#maximum index of the interval
	Imax = limit//3
	statePrimeIndices = [0]*(1+Imax)
	a = 1
	b = 1
	Icur=8

	while(Icur<=Imax):
		lim=(statePrimeIndices[b] if (statePrimeIndices[b]!=0) else b)
		while(True):
			while(statePrimeIndices[a]!=0):
				a+=1
			if(a>lim):
				break
			Icur=I(a,b)
			if(Icur>Imax):
				break

			statePrimeIndices[Icur]=a
			a+=1
		a=1
		b+=1
		Icur=I(a,b)
	primes=[]
	primes.append(2)
	primes.append(3)
	i=1
	while(i<Imax):
		if(statePrimeIndices[i]==0):
			#print(G(i))
			primes.append(G(i))
		i+=1
	g=G(i); #account for 'non-G' limits
	if(g<=limit):
		primes.append(g)

	return primes

if __name__ == "__main__":
	start_time = time.time()
	limit=10000000
	MyriadSieveNaive(limit)
	print("--- %s seconds ---" % (time.time() - start_time))
