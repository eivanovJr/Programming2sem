#include "RingBuff.hpp"

template<class T>
T& RingBuffer<T>::iter:: operator *()
{
    return (*ringbuf_).DataIndex(pos_);
}

template<class T>
RingBuffer<T>::iter::iter(RingBuffer<T>* cbuf, size_t pos)
{
    pos_ = pos;
    ringbuf_ = cbuf;
}

template<class T>
RingBuffer<T>::iter::iter(const iter& other)
{
    ringbuf_ = other.ringbuf_;
    pos_ = other.pos_;
}

template<class T>
size_t RingBuffer<T>::iter::pos()
{
    return pos_;
}

template<class T>
typename RingBuffer<T>::iter& RingBuffer<T>::iter::operator++()
{
    pos_ = ringbuf_->increment(pos_, 1);
    return *this;
}

template<class T>
typename RingBuffer<T>::iter& RingBuffer<T>::iter::operator--()
{
    pos_ = ringbuf_->decrement(pos_, 1);
    return *this;
}

template<class T>
typename RingBuffer<T>::iter& RingBuffer<T>::iter::operator+=(int val)
{
    pos_ = ringbuf_->increment(pos_, val);
    return *this;
}

template<class T>
typename RingBuffer<T>::iter& RingBuffer<T>::iter::operator-=(int val)
{
    pos_ = ringbuf_->decrement(pos_, val);
    return *this;
}

template<class T>
typename RingBuffer<T>::iter RingBuffer<T>::iter::operator + (int val) const
{
    return iter(ringbuf_, ringbuf_->increment(pos_, val));
}

template<class T>
typename RingBuffer<T>::iter RingBuffer<T>::iter::operator - (int val) const
{
    return iter(ringbuf_, ringbuf_->decrement(pos_, val));
}

template<class T>
typename RingBuffer<T>::iter RingBuffer<T>::iter::operator + (const iter& other) const
{
    return iter(ringbuf_, ringbuf_->decrement(pos_, other.pos_));
}

template<class T>
using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;

template<class T>
difference_type<T> RingBuffer<T>::iter::operator-(const iter &other) const {
    return ringbuf_->decrement(pos_, other.pos_);
}

template<class T>
bool RingBuffer<T>::iter::operator == (const iter& other) const
{
    return pos_ == other.pos_;
}

template<class T>
bool RingBuffer<T>::iter::operator != (const iter& other) const
{
    return !(*this == other);
}

template<class T>
bool RingBuffer<T>::iter::operator < (const iter& other) const
{
    if ((pos_ < ringbuf_->get_begin() && other.pos_ < ringbuf_->get_begin()) || (pos_ >= ringbuf_->get_begin() && other.pos_ >= ringbuf_->get_begin())) {
        return pos_ < other.pos_;
    }
    else
        return pos_ > other.pos_;
}

template<class T>
bool RingBuffer<T>::iter::operator <= (const iter& other) const
{
    return *this < other || *this == other;
}

template<class T>
bool RingBuffer<T>::iter::operator > (const iter& other) const
{
    return !(*this < other);
}

template<class T>
bool RingBuffer<T>::iter::operator >= (const iter& other) const
{
    return *this > other || *this == other;
}




