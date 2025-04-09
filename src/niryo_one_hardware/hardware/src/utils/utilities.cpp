#include "niryo_one_hardware/utilities.hpp"

namespace niryo_one_hardware {
	bool stob(std::string str) {
		bool result;
		std::istringstream(str) >> std::boolalpha >> result;
		return result;
	}

	std::vector<int> stovi(std::string str, char delimiter) {
		std::string s;
		std::vector<int> result;
		std::stringstream ss(str);
		while (getline(ss, s, delimiter)) {
			result.push_back(stoi(s));
		}
		return result;
	}
}
