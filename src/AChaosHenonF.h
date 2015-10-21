/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosHenonF : public AChaosBase {
public:

	REAL a, b, nx, ny, dt, t;
	
	AChaosHenonF(){}
	~AChaosHenonF(){}	

	void setup(){
		AChaosBase::setup();		
		//init	
		a = 1.4f;
		b = 0.3f;
		nx = 1.0f;
		ny = 1.0f;
		dt = 0.01f;
		t=0.0f;

		iv.push_back(a);
		iv.push_back(b);
		iv.push_back(nx);
		iv.push_back(ny);
		iv.push_back(dt);

		ov.push_back(nx);
		ov.push_back(ny);
	}

	void reset(){
		nx = iv[0];
		ny = iv[1];
		a = iv[2];
		b = iv[3];
		dt = iv[4];
	}
	
 	void calc(){ 		
		// Henon Phase Diagrams
 		REAL cosa=COS(a),sina=SIN(a), lx1, ly1, nx2=nx*nx;
		
		//henon calc
		lx1 = (ny + 1) - (a * nx2);
		ly1 = b * nx;

		//advance 'a' by dt _AFTER_ calculating henon
		t += dt;
		a *= t;

		//henon phase
		nx = nx*cosa - (ny -nx2)*sina;
		ny = nx*sina - (ny -nx2)*cosa;


/*
	// henonf attractor

	lx1 = nx*cos (a) - (ny - (nx*nx))*sin(a);
	ly1 = nx*sin(a) - (ny - (nx*nx))*cos(a);
*/

		ov[0] = nx;
		ov[1] = ny;
 	}
};