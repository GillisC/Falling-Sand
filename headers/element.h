#pragma once

// Base class for all elements
class Element {
  public:
    virtual void display() const = 0;
    virtual ~Element() = default;
};

