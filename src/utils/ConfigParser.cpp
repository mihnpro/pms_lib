#include "utils/ConfigParser.h"
#include <fstream>
#include <sstream>

ConfigParser::ConfigParser(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open config file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        auto pos = line.find('=');
        if (pos == std::string::npos) continue;
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        config_[key] = value;
    }
}

std::string ConfigParser::get(const std::string& key, const std::string& defaultValue) const {
    auto it = config_.find(key);
    if (it != config_.end()) {
        return it->second;
    }
    return defaultValue;
}
