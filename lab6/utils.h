#pragma once

void printMenu();

void loadIslandsFromFile(std::vector<Island> &islands, const std::string &filePath);

void saveIslandsToFile(const std::vector<Island> &islands, const std::string &filePath);