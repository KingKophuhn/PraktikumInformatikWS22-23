/*
 * Tempolimit.h
 *
 *  Created on: 10.01.2023
 *      Author: mickey
 */

#ifndef TEMPOLIMIT_H_
#define TEMPOLIMIT_H_

#pragma once
#include <string>
#include<iomanip>
#include <iostream>
#include <limits>
using namespace std;

enum class Tempolimit { Innerorts = 50, Landstrasse = 100, Autobahn = numeric_limits<int>::max()};

#endif /* TEMPOLIMIT_H_ */
