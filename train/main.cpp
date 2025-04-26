#include "LinearRegressionTrain.hpp"
#define LEARNING_RATE 1e-1
#define STEP 1e3

int main()
{
	LinearRegressionTrain trainner(LEARNING_RATE, STEP);
	if (trainner.loadDataSet())
		return (1);
	trainner.normalize();
	trainner.train();
	if (trainner.saveModel())
		return (1);
	return (0);
}