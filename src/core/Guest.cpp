#include "core/Guest.h"

Guest::Guest(int id, const std::string& name)
    : id_(id), name_(name) {}

int Guest::getId() const {
    return id_;
}

std::string Guest::getName() const {
    return name_;
}
