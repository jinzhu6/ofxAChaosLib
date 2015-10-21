/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

#define clif_calc(a,b,c,d) (SIN((a)*(b))+(c)*COS((a)*(d)))

class AChaosClifford : public AChaosBase {
public:

	REAL a, b, c, d, nx, ny;
	
	AChaosClifford(){}
	~AChaosClifford(){}	

	void setup(){
		AChaosBase::setup();
		//init
		a = -1.4f;
		b = 1.6f;
		c = 1.0f;
		d = 0.7f;
		//do not init x and y for more chaotic results
		nx = 0.0f;
		ny = 0.0f;

		iv.push_back(a);
		iv.push_back(b);
		iv.push_back(c);
		iv.push_back(d);

		ov.push_back(nx);
		ov.push_back(ny);
	}

	void reset(){
		a = iv[0];
		b = iv[1];
		c = iv[2];
		d = iv[3];
		nx = iv[4];
		ny = iv[5];
	}
	
 	void calc(){
 	// clifford attractor
	//	lx1 = sin (a*ny) + c*cos(a*nx);
	//	ly1 = sin (b*nx) + d*cos(b*ny);
		nx = clif_calc(a, ny, c, nx);
		ny = clif_calc(b, nx, d, ny);

		ov[0] = nx;
		ov[1] = ny;
 	}
};