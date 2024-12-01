#pragma once

void help();

void printAnimals(Animal **animals, int size);

void addAnimal(Animal **&animals, int &size, int &capacity);

void removeAnimal(Animal **&animals, int &size);

void printAnimalInfo(const Animal **animals, int size);

void processCountObjectsOfEachType(Animal **animals, int size);

int countObjectsOfTypeRTTI(Animal **animals, int size, const std::type_info &type);

void processCountObjectsOfType(Animal **animals, int size);

int countAnimalsOfTypeInherited(Animal **animals, int size, const std::type_info &type);
