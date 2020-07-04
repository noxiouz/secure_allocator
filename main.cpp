#include <iostream>
#include <string>
#include <vector>

#include <sodium.h>

template <class T> class safe_allocator {
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T value_type;

  safe_allocator() = default;
  safe_allocator(const safe_allocator &) = default;

  T *allocate(size_type n, const void * = 0) {
    T *t = (T *)sodium_malloc(n * sizeof(T));
    std::cout << " used safe_allocator to allocate   at address " << t << " (+)"
              << std::endl;
    return t;
  }

  void deallocate(void *p, size_type) {
    if (p) {
      sodium_free(p);
      std::cout << "  used safe_allocator to deallocate at address " << p
                << " (-)" << std::endl;
    }
  }
};

int main() {
  if (sodium_init() < 0) {
    std::cout << "initialization failed\n";
    return 1;
  }
  auto v = std::vector<int, safe_allocator<int>>(10);
  return 0;
}