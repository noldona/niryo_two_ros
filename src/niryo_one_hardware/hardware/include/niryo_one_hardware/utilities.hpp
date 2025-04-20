#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace niryo_one_hardware {
	bool stob(std::string str);

	std::vector<int> stovi(std::string str, char delimiter = ',');
}

#endif
