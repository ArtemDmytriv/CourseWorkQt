#pragma once
#include "head.h"

class Exchanger
{
private:
	vector<double> curren;
public:
	Exchanger() {
		curren.resize(4);
	}
	Exchanger(vector<double> ar) : Exchanger() {
		for (unsigned int i = 0; i < curren.size(); i++) {
			curren[i] = ar[i];
		}
	}
	vector<double> & getCourses();
	void AddVolume(int curr, double val) {
		curren[curr] = val;
	}
	double Change(int from, int to, double valfrom){
		if (from == to) {
			return valfrom;
		}
		else {
			double tempVal = valfrom * curren[from];
			return tempVal / curren[to];
		}
	}
	
	~Exchanger() {}
};


