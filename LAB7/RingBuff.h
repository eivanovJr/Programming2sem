//
// Created by user on 04.05.2020.
//

#ifndef ADVANCED_RINGBUFF_H
#define ADVANCED_RINGBUFF_H

template<class T>
class iter;

template<class T>
class RingBuffer
{
public:
    explicit RingBuffer(int size);
    ~RingBuffer();
    void push_front(const T& obj);
    void push_back(const T&);
    void pop_front();
    void pop_back();
    void push(int, const T&);
    void pop(int);
    [[nodiscard]] size_t size() const;
    size_t increment(int what, int on);
    size_t decrement(int what, int on);
    iter<T> begin()
    {
        return iter(this, begin_);
    }
    iter<T> end()
    {
        return iter(this, end_);
    }
    int get_begin() const {return begin_;}
    int get_end() const {return end_;}
    T& DataIndex(int pos) {return _data[pos];}
    void resize(int);
    T& operator[](int) const;

private:
    size_t _size;
    size_t _elements_written;
    T *_data;
    int begin_;
    int end_;
};

template<class T>
class iter : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    size_t pos_;
    RingBuffer<T>* ringbuf_;
public:
    iter() {}
    iter(RingBuffer<T>* cbuf, size_t pos) {
        pos_ = pos;
        ringbuf_ = cbuf;
    }
    iter(const iter& other) {
        ringbuf_ = other.ringbuf_;
        pos_ = other.pos_;
    }
    size_t pos()
    {
        return pos_;
    }
    using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
    typedef T& reference;
    reference operator * () {return (*ringbuf_).DataIndex(pos_);}
    iter& operator ++ () {pos_ = ringbuf_->increment(pos_, 1); return *this;}
    iter& operator -- () {pos_ = ringbuf_->decrement(pos_, 1); return *this;}
    iter& operator += (int val) {pos_ = ringbuf_->increment(pos_, val); return *this;}
    iter& operator -= (int val) {pos_ = ringbuf_->decrement(pos_, val); return *this;}
    iter operator + (int val) const {return iter(ringbuf_, ringbuf_->increment(pos_, val));}
    iter operator - (int val) const {return iter(ringbuf_, ringbuf_->decrement(pos_, val));}
    iter operator + (const iter& other) const {return iter(ringbuf_, ringbuf_->decrement(pos_, other.pos_));}
    difference_type operator - (const iter& other) const {return ringbuf_->decrement(pos_, other.pos_);}
    bool operator == (const iter& other) const {return pos_ == other.pos_;}
    bool operator != (const iter& other) const {return !(*this == other);}
    bool operator < (const iter& other) const {
        if ((pos_ < ringbuf_->get_begin() && other.pos_ < ringbuf_->get_begin()) || (pos_ >= ringbuf_->get_begin() && other.pos_ >= ringbuf_->get_begin())) {
            return pos_ < other.pos_;
        }
        else
            return pos_ > other.pos_;
    }
    bool operator <= (const iter& other) const {return *this < other || *this == other;}
    bool operator > (const iter& other) const {return !(*this < other);}
    bool operator >= (const iter& other) const {return *this > other || *this == other;}

};



#endif //ADVANCED_RINGBUFF_H
