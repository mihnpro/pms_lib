#pragma once
#include <string>

class Resource {
public:
    Resource(int id, const std::string& name, int quantity);
    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    void setQuantity(int quantity);

private:
    int id_;
    std::string name_;
    int quantity_;
};
