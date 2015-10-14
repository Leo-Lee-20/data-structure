#include "Stack.h"

Stack::Stack() {
  count = 0;
}

Error_code Stack::pop() {
  if (count == 0)
    return underflow;
  --count;
  return success;
}

Error_code Stack::push(const Stack_entry &item) {
  if (count == maxstack)
    return overflow;
  entry[count++] = item;
  return success;
}

Error_code Stack::top(Stack_entry &item) const {
  if (count == 0)
    return underflow;
  item = entry[count - 1];
  return success;
}

bool Stack::empty() const {
  return count == 0;
}
