template<class Iterator, class Pre>
bool all_of(Iterator begin, Iterator end, Pre funct)
{
    for (; begin != end; begin++)
    {
        if (!funct(*begin))
            return false;
    }
    return true;
}

template<class Iterator, class Criteria>
bool is_sorted(Iterator begin, Iterator end, Criteria check)
{
    bool Increment = true, Decrement = true;
    for (; begin != end; begin++)
    {
        if (check(*begin, *(++begin)) == check(*begin, *(--begin)))
            continue;
        if (check(*begin, *(++begin)))
            Decrement = false;
        else
            Increment = false;
        begin--;
    }
    return Increment || Decrement;
}

template<class Iterator, class Object>
Object find_backward(Iterator begin, Iterator end, Object find)
{
    Object result;
    for (; begin != end; begin++)
    {
        if (*begin == find)
        {
            result = *begin;
        }
    }
    return result;
}