#pragma once

void help();

void printAnimals(Animal **animals, int size);

void addAnimal(Animal **&animals, int &size, int &capacity);

void removeAnimal(Animal **&animals, int &size);
