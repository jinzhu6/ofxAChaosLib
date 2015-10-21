/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosLogistic1 : public AChaosBase {
public:

	REAL seed, lambda, gamma;
	
	AChaosLogistic1(){}
	~AChaosLogistic1(){}	

	void setup(){
		AChaosBase::setup();		
		//init	
		seed = 0.777f;
		lambda = 3.9f;
		gamma = 3.43f;

		iv.push_back(seed);
		iv.push_back(lambda);
		iv.push_back(gamma);

		ov.push_back(seed);
	}
	
	void reset(){
		seed = iv[0];
		lambda = iv[1];
		gamma = iv[2];
	}
	
 	void calc(){ 	
 		seed = (seed*lambda) -(gamma*seed*seed);

		ov[0] = seed;		
 	}
};