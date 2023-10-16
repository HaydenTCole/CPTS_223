#ifndef MAPPINGFUNCTIONS_HPP
#define MAPPINGFUNCTIONS_HPP

#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include "TwitterData.hpp"
using namespace std;

void print_map(map<string, TwitterData*> data);
void find_and_print(const map<string, TwitterData*> data, string key);

#endif
