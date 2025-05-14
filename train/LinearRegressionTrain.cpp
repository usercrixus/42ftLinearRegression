#include "LinearRegressionTrain.hpp"

LinearRegressionTrain::LinearRegressionTrain(double learningRate, int step):
learningRate(learningRate),
step(step),
bias(0),
weight(0),
maxX(0),
minX(0)
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
        return (false);
    }
    file << bias << " " << weight << " " << minX << " " << maxX << "\n";
    std::cout << "bias: " << bias << std::endl;
    std::cout << "weight: " << weight << std::endl;
    std::cout << "minX: " << minX << std::endl;
    std::cout << "maxX: " << maxX << std::endl;
	return (true);
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
	for (std::vector<std::pair<double, double>>::iterator it = data.begin(); it != data.end(); ++it)
	{
		double diff = estimateY(it->first) - it->second;
		averageError += diff * it->first;
	}
	return (averageError / data.size());
}

bool LinearRegressionTrain::train()
{
	if (data.size() == 0)
		return (std::cerr <<"Train error: data.size() == 0", false);
	double lossBias;
	double lossWeight;
    while (step > 0)
    {
        lossBias = getLossBias();
        lossWeight = getLossWeight();
        bias -= learningRate * lossBias;
        weight -= learningRate * lossWeight;
        step--;
    }
	return (true);
}

bool LinearRegressionTrain::normalize()
{
	std::sort(data.begin(), data.end());
    minX = data.at(0).first;
    maxX = data.at(data.size() - 1).first;
	if ((maxX - minX) == 0)
		return (std::cerr <<"Normalisation: Division by 0", false);
	for (std::pair<double, double> &p : data)
        p.first = 2.0 * (p.first - minX) / (maxX - minX) - 1.0;
	return (true);
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
