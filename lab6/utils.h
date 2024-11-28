#pragma once

void printMenu();

void loadIslandsFromFile(std::vector<Island> &islands, const std::string &filePath);

void saveIslandsToFile(const std::vector<Island> &islands, const std::string &filePath);

double aggregateIslands(const std::vector<Island> &islands, int agg_choice, int characteristic_choice);

void testAggregateIslands();