/**
 * < Novl Engine > CircularQueue.hpp
 * Author: DeckardZ46
 * Date: 2024/11/04
 * Note: A circular queue container for Novl Engine, it is NOT THREAD SAFE so be ware of using it in multi-threaded
 * cases. Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#include <optional>

namespace Novl {
// It is NOT thread safe!
template <typename T> class CircularQueue {
  private:
    T *array;
    size_t front;
    size_t rear;
    size_t maxSize;
    size_t count;

  public:
    CircularQueue(size_t size) : maxSize(size + 1), front(0), rear(0), count(0) {
        array = new T[maxSize];
    }

    ~CircularQueue() {
        delete[] array;
    }

    // check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // check if the queue is full
    bool isFull() const {
        return count == maxSize;
    }

    // enqueue
    bool enqueue(const T &value) {
        if (isFull()) {
            return false;
        }
        array[rear] = value;
        rear = (rear + 1) % maxSize;
        ++count;
        return true;
    }

    // Try avoiding using it, if have to use it, BE CAUTION.
    void forceEnqueue(const T &value) {
        if (isFull()) {
            dequeue();
        }
        enqueue(std::move(value));
    }

    // dequeue
    std::optional<T> dequeue() {
        if (isEmpty()) {
            return std::nullopt;
        }
        auto value = array[front];
        front = (front + 1) % maxSize;
        --count;
        return std::move(value);
    }

    // get front element
    std::optional<T> frontElement() const {
        if (isEmpty()) {
            return std::nullopt;
        }
        return array[front];
    }

    // get rear element
    std::optional<T> rearElement() const {
        if (isEmpty()) {
            return std::nullopt;
        }
        return array[(rear - 1 + maxSize) % maxSize];
    }

    // get circular queue size
    size_t size() const {
        return count;
    }

    // clear the queue, but it won't free memory usage
    void Clear() {
        front = rear = 0;
        count = 0;
    }

    // Erase the queue and deallocate memory
    void Erase() {
        delete[] array;
        array = nullptr;
        maxSize = 0;
        front = rear = 0;
        count = 0;
    }

    // iterator for circular queue
    class iterator {
      private:
        CircularQueue *q;
        size_t index;

      public:
        iterator(CircularQueue *q, size_t idx) : q(q), index(idx) {
        }

        T &operator*() {
            return q->array[(index + q->front) % q->maxSize];
        }

        iterator &operator++() {
            index++;
            return *this;
        }

        bool operator!=(const iterator &other) const {
            return index != other.index;
        }
    };

    iterator begin() {
        return iterator(this, 0);
    }

    iterator end() {
        return iterator(this, count);
    }
};
} // namespace Novl
