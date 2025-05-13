#include "core/Resource.h"

Resource::Resource(int id, const std::string& name, int quantity)
    : id_(id), name_(name), quantity_(quantity) {}

int Resource::getId() const {
    return id_;
}

std::string Resource::getName() const {
    return name_;
}

int Resource::getQuantity() const {
    return quantity_;
}

void Resource::setQuantity(int quantity) {
    quantity_ = quantity;
}
