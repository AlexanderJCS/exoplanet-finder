#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "../include/exoplanetFinder/detect_exoplanets.h"
#include "../include/exoplanetFinder/parseData.h"

using namespace std::chrono;


int main()
{
	DetectExoplanets::FindPlanet planetFinder{ readData("test/data.csv"), 0.9999, 0.002, 1.5, 0.4 };
	
	auto start = high_resolution_clock::now();
	auto planetFluxes = planetFinder.findPlanets(false);
	auto stop = high_resolution_clock::now();

	std::cout << "*** FAST ALGORITHM ***\n";

	for (auto& flux : planetFluxes) {
		std::cout << "Planet identified with flux: " << flux << "\n";
	}

	auto duration = duration_cast<milliseconds>(stop - start);
	std::cout << "\nCompleted in " << duration.count() << " ms\n";

	start = high_resolution_clock::now();
	planetFluxes = planetFinder.findPlanetsPrecise(false);
	stop = high_resolution_clock::now();

	std::cout << "\n *** PRECISE ALGORITHM ***\n";

	for (auto& flux : planetFluxes) {
		std::cout << "Planet identified with flux: " << flux << "\n";
	}

	duration = duration_cast<milliseconds>(stop - start);
	std::cout << "\nCompleted in " << duration.count() << " ms\n";
}