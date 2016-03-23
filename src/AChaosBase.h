/*
	32/64 bits A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012, 2015
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: MIT
*/
#pragma once

// comment for 64bits version (not all objects support)
#define ACHAOS32

#ifdef ACHAOS32
// 32bit	
	typedef float REAL;
	#define SIN sinf
	#define COS cosf

#else
// 64bit	
	typedef double REAL;
	#define SIN sin
	#define COS cos

#endif



class AChaosBase {
public:
	AChaosBase(){}
	virtual ~AChaosBase(){}	

	vector<REAL> iv;	
	vector<REAL> ov;

	virtual void setup(REAL * params = NULL, int numiv=1, int numov=1){
		iv.clear();
		ov.clear();
		for(int i=0; i<numiv; i++){
			iv.push_back(0.0f);
		}
		for(int i=0; i<numov; i++){
			ov.push_back(0.0f);
		}
		cout << "A-Chaos Lib (c) s373.net/x 2004, 2012, 2015 " << __DATE__ << " " __TIME__ << endl;
	}
	virtual void reset(){cout << "reset base" << endl;}
	void set(vector<REAL> &params){
		iv.clear();
		for(int i=0; i<params.size();i++){
			iv.push_back( params[i] );			
		}
		reset();
	}
	void set(REAL * params){
		for(int i=0; i<iv.size();i++){
			iv[i] = params[i] ;		
		}
		reset();
	}
	REAL * update(){ calc(); return get(); }
	virtual void calc(){cout << "calc base" << endl;}
	REAL * get(){ return &ov[0];}
	vector<REAL> & getVec(){return ov;}	
};