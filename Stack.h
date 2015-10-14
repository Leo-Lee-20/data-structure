#define Stack_entry int
#define maxstack 10

enum Error_code {
  success, overflow, underflow
};

class Stack {
 public:
  Stack();
  Error_code pop();
  Error_code push(const Stack_entry &item);
  Error_code top(Stack_entry &item) const;
  bool empty() const;
 private:
  int count;
  Stack_entry entry[maxstack];
};
