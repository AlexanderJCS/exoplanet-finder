#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "../include/exoplanetFinder/detect_exoplanets.h"
#include "../include/exoplanetFinder/parseData.h"

using namespace std::chrono;


int binSearch(std::vector<int> data, int target) {
	auto lowerBoundIt = std::lower_bound(data.begin(), data.end(), target);

	if (lowerBoundIt == data.end() || *lowerBoundIt != target) {
		return -1;
	}

	else {
		return std::distance(data.begin(), lowerBoundIt);
	}
}


int main()
{
	DetectExoplanets::FindPlanet planetFinder{ readData("test/data.csv"), 0.9999, 0.002, 1.5, 0.4 };
	
	auto start = high_resolution_clock::now();
	auto planetFluxes = planetFinder.findPlanets(false);
	auto stop = high_resolution_clock::now();

	for (auto& flux : planetFluxes) {
		std::cout << "Planet identified with flux: " << flux << "\n";
	}

	auto duration = duration_cast<milliseconds>(stop - start);
	std::cout << "\nCompleted in " << duration.count() << " ms\n";
}