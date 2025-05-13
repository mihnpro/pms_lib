#pragma once
#include <string>
#include <unordered_map>

class ConfigParser {
public:
    explicit ConfigParser(const std::string& filename);
    std::string get(const std::string& key, const std::string& defaultValue = "") const;

private:
    std::unordered_map<std::string, std::string> config_;
};
