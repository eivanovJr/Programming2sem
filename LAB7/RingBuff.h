//
// Created by user on 04.05.2020.
//

#ifndef ADVANCED_RINGBUFF_H
#define ADVANCED_RINGBUFF_H

using namespace std;
template<class T>
class RingBuffer
{
public:
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
        reference operator * () {return (*ringbuf_)._data[pos_];}
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
            if ((pos_ < ringbuf_->begin_ && other.pos_ < ringbuf_->begin_) || (pos_ >= ringbuf_->begin_ && other.pos_ >= ringbuf_->begin_)) {
                return pos_ < other.pos_;
            }
            else
                return pos_ > other.pos_;
        }
        bool operator <= (const iter& other) const {return *this < other || *this == other;}
        bool operator > (const iter& other) const {return !(*this < other);}
        bool operator >= (const iter& other) const {return *this > other || *this == other;}

    };

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
    iter begin()
    {
        return iter(this, begin_);
    }
    iter end()
    {
        return iter(this, end_);
    }
    void resize(int);
    T& operator[](int) const;

private:
    size_t _size;
    size_t _elements_written;
    T *_data;
    int begin_;
    int end_;
};


#endif //ADVANCED_RINGBUFF_H
