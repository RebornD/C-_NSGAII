#pragma once
#include"Problem.h"
#include"WFG.h"

class WFG1Problem : public WFGProblem {
private:

public:
	WFG1Problem();
	WFG1Problem(int, int,int);
	~WFG1Problem();

	void evaluate(Solution &);
	void repair(Solution  &);

};