#include <optional>

namespace Novl{
template<typename T>
class CircularQueue {
private:
    T* array;             
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
    bool enqueue(const T& value) {
        if (isFull()) {
            return false;
        }
        array[rear] = value;
        rear = (rear + 1) % maxSize;
        ++count;
        return true;
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
};
} // namespace Novl
