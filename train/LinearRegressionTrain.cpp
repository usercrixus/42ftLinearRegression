#include "LinearRegressionTrain.hpp"

LinearRegressionTrain::LinearRegressionTrain(double learningRate, double step):
learningRate(learningRate),
step(step),
bias(0),
weight(0)
{
}

LinearRegressionTrain::~LinearRegressionTrain()
{
}

int LinearRegressionTrain::saveModel()
{
    std::ofstream file("model.mo");
    if (!file)
    {
        std::cerr << "can't open model.mo" << std::endl;
        return (1);
    }
    file << bias << " " << weight << " " << minMileage << " " << maxMileage << "\n";
    std::cout << "bias: " << bias << std::endl;
    std::cout << "weight: " << weight << std::endl;
    std::cout << "minMileage: " << minMileage << std::endl;
    std::cout << "maxMileage: " << maxMileage << std::endl;
	return (0);
}

double LinearRegressionTrain::estimatePrice(double mileage) // mileage is normalized
{
	return (bias + weight * mileage);
}

double LinearRegressionTrain::getLossBias()
{
	double averageError = 0;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		double diff = estimatePrice(it->first) - it->second;
		averageError += diff;
	}
	return (averageError / data.size());
}

double LinearRegressionTrain::getLossWeight()
{
	double averageError = 0;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		double diff = estimatePrice(it->first) - it->second;
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
    minMileage = data.at(0).first;
    maxMileage = data.at(data.size() - 1).first;

    for (auto& p : data)
    {
        p.first = 2.0 * (p.first - minMileage) / (maxMileage - minMileage) - 1.0;
    }
}

int LinearRegressionTrain::loadDataSet()
{
	std::ifstream file("data.csv");
	if (!file)
		return (std::cerr << "can't open data.csv" << std::endl, 1);
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string key, value;

		if (std::getline(ss, key, ',') && std::getline(ss, value))
		{
			int mileage = std::stoi(key);
			int price = std::stoi(value);
			data.emplace_back(mileage, price);
		}
		else
			return (std::cerr << "Malformed line: " << line << std::endl, 1);
	}
	return (0);
}
