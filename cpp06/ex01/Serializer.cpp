#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &copy) { *this = copy; }

Serializer &Serializer::operator=(Serializer const &copy) {
  if (this != &copy) {
    *this = copy;
  }
  return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *data) {
  return reinterpret_cast<uintptr_t>(data);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
