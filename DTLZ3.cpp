#include"DTLZ3.h"


DTLZ3::DTLZ3() {
	SolutionType_ = 2;
	problemname_ = "DTLZ3";

	UpperLimit_.resize(0);;
	LowerLimit_.resize(0);;

	numberOfObjective_ =0;
	numberOfValue_ = 0;
	numberOfConstrain_ = 0;
}

DTLZ3::DTLZ3(int  numberOfVariables, int  numberOfObjectives) {

	numberOfValue_ = numberOfVariables;
	numberOfObjective_ = numberOfObjectives;
	numberOfConstrain_ = 0;
	
	problemname_ = "DTLZ3";

	LowerLimit_.resize(numberOfValue_);
	UpperLimit_.resize(numberOfValue_);

	for (int var = 0; var < numberOfVariables; var++) {
		LowerLimit_[var] = 0.0;
		UpperLimit_[var] = 1.0;
	} //for

	SolutionType_ = 2;

}

DTLZ3::~DTLZ3() {

};

void DTLZ3::repair(Solution &solution){

}


void DTLZ3::evaluate(Solution &solution) {

	double* x = new double[numberOfValue_];
	double* f = new double[numberOfValue_];
	int k = numberOfValue_ - numberOfObjective_ + 1;

	    for (int i = 0; i < numberOfValue_; i++)
	      x[i] = solution.getValue(i);

	    double g = 0.0;
	    for (int i = numberOfValue_ - k; i < numberOfValue_; i++)
	      g += (x[i] - 0.5)*(x[i] - 0.5) - cos(20.0 * PI * (x[i] - 0.5));

	    g = 100.0 * (k + g);
	    for (int i = 0; i < numberOfObjective_; i++)
	      f[i] = 1.0 + g;

	    for (int i = 0; i < numberOfObjective_; i++){
	      for (int j = 0; j < numberOfObjective_ - (i + 1); j++)
	        f[i] *= cos(x[j]*0.5*PI);
	        if (i != 0){
	          int aux = numberOfObjective_ - (i + 1);
	          f[i] *= sin(x[aux]*0.5*PI);
	        } // if
	    } //for

	    for (int i = 0; i < numberOfObjective_; i++)
	      solution.setObjective(i,f[i]);
		delete[] x;
		delete[] f;


} // evaluate
