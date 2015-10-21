/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/

#pragma once
#include "AChaosBase.h"

class AChaosCollatz : public AChaosBase {
public:

	long value, offset;
	bool mode;
	

	AChaosCollatz(){}
	~AChaosCollatz(){}	

	void setup(){
		AChaosBase::setup();

		//init
		value = offset = 0;
		mode = 0;
	
		iv.push_back(value);
		iv.push_back(offset);
		iv.push_back((REAL)mode);

		ov.push_back(value);
	}

	void reset(){
		value = (long) iv[0];
		offset = (long) iv[1];
		mode = iv[2]>0;
	}
	
 	void calc(){
		
		short int stub = value % 2; //par ou impar
		 
		if(!mode) { 				// L.Collatz collatz mode
			 if (!stub) value /= 2;		//par ]e metade
			 else value = 3*value+1;	//impar ]e 3n+1			 
			}
		else if (mode) { 				// Terras collatz mode
			 if (!stub) value /= 2;		//par ]e metade
			 else value = 0.5*(3*value+1);	//impar ]e 1/2(3n+1)			
			}

		ov[0] = (REAL)value;
 	}
};