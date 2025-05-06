#include "LinearRegressionTrain.hpp"

LinearRegressionTrain::LinearRegressionTrain(double learningRate, int step):
learningRate(learningRate),
step(step),
bias(0),
weight(0)
{
}

LinearRegressionTrain::~LinearRegressionTrain()
{
}

bool LinearRegressionTrain::saveModel(char *path)
{
    std::ofstream file(path);
    if (!file)
    {
        std::cerr << "can't open model.mo" << std::endl;
        return (1);
    }
    file << bias << " " << weight << " " << minX << " " << maxX << "\n";
    std::cout << "bias: " << bias << std::endl;
    std::cout << "weight: " << weight << std::endl;
    std::cout << "minX: " << minX << std::endl;
    std::cout << "maxX: " << maxX << std::endl;
	return (0);
}

double LinearRegressionTrain::estimateY(double x)
{
	return (bias + weight * x);
}

double LinearRegressionTrain::getLossBias()
{
	double averageError = 0;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		double diff = estimateY(it->first) - it->second;
		averageError += diff;
	}
	return (averageError / data.size());
}

double LinearRegressionTrain::getLossWeight()
{
	double averageError = 0;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		double diff = estimateY(it->first) - it->second;
		averageError += diff * it->first;
	}
	return (averageError / data.size());
}

void LinearRegressionTrain::train()
{
    while (step > 0)
    {
        double lossBias = getLossBias();
        double lossWeight = getLossWeight();

        bias -= learningRate * lossBias;
        weight -= learningRate * lossWeight;

        step--;
    }
}

void LinearRegressionTrain::normalize()
{
	std::sort(data.begin(), data.end());
    minX = data.at(0).first;
    maxX = data.at(data.size() - 1).first;

    for (auto& p : data)
    {
        p.first = 2.0 * (p.first - minX) / (maxX - minX) - 1.0;
    }
}

bool LinearRegressionTrain::loadDataSet(char *path)
{
	std::ifstream file(path);
	if (!file)
		return (std::cerr << "can't open " << path << std::endl, false);
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string key, value;

		if (std::getline(ss, key, ',') && std::getline(ss, value))
		{
			double x = std::stoi(key);
			double y = std::stoi(value);
			data.emplace_back(x, y);
		}
		else
			return (std::cerr << "Malformed line: " << line << std::endl, false);
	}
	return (true);
}
