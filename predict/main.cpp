#include "LinearRegressionPredict.hpp"
#define MODEL "model.mo"

int main(int argc, char const *argv[])
{
	LinearRegressionPredict p(MODEL);
	if (p.loadModel())
		return (1);
	p.promptAndPredict();
	return 0;
}
