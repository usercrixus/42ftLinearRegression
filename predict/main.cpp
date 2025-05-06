#include "LinearRegressionPredict.hpp"
#define MODEL "model.mo"

/**
 * 
 * Should be call like ./predict.out modelPath.mo
 * The model should be generated with train.out (see the Makefile)
 * 
 */
int main(int argc, char const *argv[])
{
	if (argc != 2)
		return (std::cout << "Bad usage. 1 arg needed: model path ex: ./predict.out model.mo" << std::endl, 1);
	LinearRegressionPredict p;
	if (p.loadModel(std::string(argv[1])))
		return (1);
	p.promptAndPredict();
	return (0);
}
