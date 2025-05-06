#include "LinearRegressionPredict.hpp"

LinearRegressionPredict::LinearRegressionPredict()
{
}

LinearRegressionPredict::~LinearRegressionPredict()
{
}
int LinearRegressionPredict::promptAndPredict()
{
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    if (std::cin.fail())
    {
        std::cerr << "Invalid input!" << std::endl;
        return (1);
    }
    double y = estimateY(normalize(x));
    std::cout << "Estimated y: " << y << std::endl;
	return (0);
}


double LinearRegressionPredict::estimateY(double x)
{
	return (bias + weight * x);
}

double LinearRegressionPredict::normalize(double x)
{
    return 2.0 * (x - minX) / (maxX - minX) - 1.0;
}
int LinearRegressionPredict::loadModel(std::string modelPath)
{
    std::ifstream file(modelPath);
    if (!file)
        return (std::cerr << "can't open " <<  modelPath << std::endl, 1);
    file >> bias >> weight >> minX >> maxX;
    if (file.fail())
    {
        std::cerr << "Malformed " << modelPath << std::endl;
        return (1);
    }
    return (0);
}
