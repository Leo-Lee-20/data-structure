#include "Queue.h"

Queue::Queue() {
  count = 0;
  front = 0;
  rear = maxqueue - 1;
}

bool Queue::empty() const {
  return count == 0;
}

Error_code Queue::serve() {
  if (count == 0)
    return underflow;
  count--;
  front = (front + 1) % maxqueue;
  return success;
}

Error_code Queue::append(const Queue_entry &item) {
  if (count == maxqueue)
    return overflow;
  count++;
  rear = (rear + 1) % maxqueue;
  entry[rear] = item;
  return success;
}

Error_code Queue::retrieve(Queue_entry &item) const {
  if (count == 0)
    return underflow;
  item = entry[front];
  return success;
}
