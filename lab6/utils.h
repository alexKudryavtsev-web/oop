#pragma once

void printMenu();

void loadIslandsFromFile(std::vector<Island> &islands, const std::string &filePath);

void testLoadIslandsFromFile();

void saveIslandsToFile(const std::vector<Island> &islands, const std::string &filePath);

double aggregateIslands(const std::vector<Island> &islands, int agg_choice, int characteristic_choice);
void testAggregateIslands();

// Компараторы
bool compareByName(const Island &a, const Island &b);
bool compareByArea(const Island &a, const Island &b);
bool compareByPopulation(const Island &a, const Island &b);

Island getExtremumValue(const std::vector<Island> &islands, int extremum_choice, int characteristic_choice);
void testExtremumValue();

std::vector<Island> filterByValue(const std::vector<Island> &islands, double threshold, int characteristic_choice);
void testFilterByValue();