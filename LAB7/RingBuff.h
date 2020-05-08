//
// Created by user on 04.05.2020.
//

#ifndef ADVANCED_RINGBUFF_H
#define ADVANCED_RINGBUFF_H

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
        using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
        iter() {}
        iter(RingBuffer<T>* cbuf, size_t pos);
        iter(const iter& other);
        size_t pos();
        T& operator * ();
        iter& operator ++ ();
        iter& operator -- ();
        iter& operator += (int val);
        iter& operator -= (int val);
        iter operator + (int val) const;
        iter operator - (int val) const;
        iter operator + (const iter& other) const;
        difference_type operator - (const iter& other) const;
        bool operator == (const iter& other) const;
        bool operator != (const iter& other) const;
        bool operator < (const iter& other) const;
        bool operator <= (const iter& other) const;
        bool operator > (const iter& other) const;
        bool operator >= (const iter& other) const;

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

#endif //ADVANCED_RINGBUFF_H
