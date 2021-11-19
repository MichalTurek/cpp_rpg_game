#pragma once
#include <iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
#include <Windows.h>
using std::srand;
using std::rand;
#include <algorithm>
using std::stable_sort;
using std::sort;
using std::remove_if;
using std::find_if;
using std::find;
using std::begin;
using std::end;
#include <typeinfo>

#include <iterator>
using std::iterator;
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;
#include <vector>
using std::vector;
#include "constants.h"
#include "Organism.h"

#include "World.h"
using organism_iterator = std::vector<unique_ptr<Organism>>::iterator;

