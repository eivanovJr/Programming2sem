#include "RingBuff.h"
#include "MyException.h"

template<class T>
RingBuffer<T>::RingBuffer(int size)
{
    _size = size + 1;
    _data = new T[_size];
    begin_ = 0;
    end_ = 0;
    _elements_written = 0;
}

template<class T>
RingBuffer<T>::~RingBuffer()
{
    delete[] _data;
}

template<class T>
void RingBuffer<T>::push_front(const T &obj)
{
    if (end_ % _size - begin_ % _size == 1 || (end_ == _size - 1 && begin_ == 0))
    {
        end_ = (end_ + _size - 1) % _size;
    }
    else
        _elements_written++;
    begin_ = (begin_ + _size - 1) % _size;
    _data[begin_ % _size] = obj;
}

template<class T>
void RingBuffer<T>::push_back(const T &obj)
{
    if (begin_ % _size - end_ % _size == 1)
        begin_ = (begin_ + 1) % _size;
    else
        _elements_written++;
    _data[end_ % _size] = obj;
    end_ = (end_ + 1) % _size;
}

template<class T>
size_t RingBuffer<T>::size() const
{
    return _elements_written;
}

template<class T>
void RingBuffer<T>::pop_back()
{
    if (begin_ % _size != end_ % _size)
    {
        end_ = (end_ + _size - 1) % _size;
        _elements_written--;
    }
    else
        throw MyException("Buffer is empty");
}

template<class T>
void RingBuffer<T>::pop_front()
{
    if (begin_ % _size != end_ % _size)
    {
        begin_ = (begin_ + 1) % _size;
        _elements_written--;
    }
    else
        throw MyException("Buffer is empty");
}

template<class T>
size_t RingBuffer<T>::increment(int what, int on)
{
    return (what + on) % _size;
}

template<class T>
size_t RingBuffer<T>::decrement(int what, int on)
{
    return (what + _size - on) % _size;
}

template<class T>
void RingBuffer<T>::resize(int capacity)
{
    T* buffer = new T[_size];
    int max_size = 0;

    for (int i = 0; i < capacity; i++)
    {
        if (i == _elements_written)
            break;

        buffer[i] = operator[](i);
        max_size++;
    }

    delete[] _data;
    _data = new T[capacity + 1];

    for (int i = 0; i < max_size; i++)
        _data[i] = buffer[i];

    _elements_written = max_size;
    _size = capacity + 1;
    begin_ = 0;
    end_ = _elements_written;

    delete[] buffer;
}

template<class T>
void RingBuffer<T>::pop(int from)
{
    from--;
    auto current = begin() + from;
    if (current == begin())
        pop_front();
    else if (current == end())
        pop_back();
    else
    {
        auto next(current + 1);
        for (auto i = current; i != end(); ++i) {
            _data[i.pos()] = _data[next.pos()];
            ++next;
        }
        next = next - 2;
        end_ = next.pos();
        _elements_written--;
    }
}

template<class T>
void RingBuffer<T>::push(int pos, const T& obj)
{
    pos--;
    auto current = begin() + pos;
    if (current == begin())
        push_front(obj);
    else if (current == end())
        push_back(obj);
    else
    {
        T temp, pr;
        pr = *current;
        for (auto i = current + 1; i != end(); ++i) {
            temp = *i;
            _data[i.pos()] = pr;
            pr = temp;
        }
        _data[current.pos()] = obj;
        if (_elements_written < _size - 1)
        {
            _data[end_] = pr;
            end_ = (end() + 1).pos();
            _elements_written++;
        }
    }
}

template<class T>
T& RingBuffer<T>::operator[](const int i) const
{
    return _data[(begin_ + i) % _size];
}