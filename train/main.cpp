#include "Train.hpp"

int main()
{
	Train trainner;
	trainner.loadDataSet();
	trainner.normalize();
	trainner.linearRegression();
	trainner.saveResult();

	return (0);
}