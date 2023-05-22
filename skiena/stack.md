### 3-4. [5] Design a stack S that supports S.push(x), S.pop(), and S.ﬁndmin(),
 which returns the minimum element of S. All operations should run in constant
 time.

### My solution:
What makes this exercise tricky is the constant time requirement.
push() can be made amortised constant by doubling the memory during resize
Search for minimum is constant complexity only for sorted arrays or lists.
Sorting an array or list however is not constant.
Section 3.5 reveals the solution. The key to constant min search is a pointer
the minimum element, updated during insertion.

### Missing in my solution
ChatGPT has suggested to store all minimas in a separate array. Indeed, in 
my solution `pop()` is not constant time.

```cpp
class S {
  void push(double x) {
    size_++;
    if (size_ >= size_mem_) {
      double old_data = data_;
      data_ = new double[2 * size_];
      std::copy(old_data, old_data + size_, data_);
    }
    data_[size_] = x;

    // Update minimum
    if (x < min_el_) {
      min_el_ = x;
      min_el_idx_ = size_;
    }
  }

  double findmin() { return min_el_; }

  void pop() {
    if (size_ == min_el_idx_) {
      // We are deleting the minimum. We need to find the new min.
      auto result = std::min_element(data_, data_ + (size_ - 1));
      min_el_ = *result;
    }

    size_--;
  };

 private:
  double* data_;
  size_t size_mem_{0};
  size_t size_{0};
  double min_el_ = std::numeric_limits<double>::infinity();
  size_t min_el_idx_ = 0;
}
```

### ChatGPT's solution

The key to this problem is to maintain two stacks: one for the elements and one for the current minimum values. When you push an element onto the stack, you also push the new minimum onto the min stack. When you pop an element, you also pop the top of the min stack. This way, the top of the min stack always contains the current minimum of the stack, and all operations run in constant time.

Here's a simple implementation in C++:

```cpp
#include <stack>
#include <stdexcept>

class MinStack {
 public:
  void push(int x) {
    s.push(x);
    if (min_s.empty() ||
        x <= getMin())  // If the new element is smaller than the current
                        // minimum, push it on the min stack.
      min_s.push(x);
    else  // Otherwise, duplicate the current minimum.
      min_s.push(min_s.top());
  }

  void pop() {
    if (s.empty()) throw std::out_of_range("Stack is empty");
    s.pop();
    min_s.pop();
  }

  int top() {
    if (s.empty()) throw std::out_of_range("Stack is empty");
    return s.top();
  }

  int getMin() {
    if (min_s.empty()) throw std::out_of_range("Stack is empty");
    return min_s.top();
  }

 private:
  std::stack<int> s;      // The main stack.
  std::stack<int> min_s;  // The min stack.
};
```

In this code,
the push() function checks if the new element x is smaller than
    or equal to the current minimum(which is at the top of min_s).If it is,
it pushes x onto min_s; otherwise,
it duplicates the current minimum
    .

The
pop() function pops the top elements from both s and min_s.

The top() function returns the top element of s,
and the getMin() function returns the top element of min_s,
which is the current minimum of the stack.

All these operations run in constant time,
as required.Note that this implementation can
    throw an std::out_of_range exception if you try to pop from
    or get the top element or minimum of an empty stack.
