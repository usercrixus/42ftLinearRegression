#include "Predict.hpp"

int main(int argc, char const *argv[])
{
	Predict p;
	if (p.loadModel())
		return (1);
	p.promptAndPredict();
	return 0;
}
