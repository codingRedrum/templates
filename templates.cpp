// Return a pointer to the block of memory that contains the elements of a container
// Return  a pointer to the first element of the container / trailing return type C++
template <typename Container>
constexpr auto data (Container &c) -> decltype(c.data())
{
    return c.data();
}

// same as above but according to Template Type Deduction Param is declared to be const
// so T will drop constness 
template <typename Container>
constexpr auto data (Container const &c) -> decltype(c.data())
{
    return c.data();
}

// Return a pointer to the block of memory that contains the elements of a raw array
template <typename T, std::size_t N>
constexpr T* data(T (&array)[N]) noexcept
{
    return array;
}


// Return a pointer to the block of memory that contains the elements of a std::initializer_list
template <typename T>
constexpr T const* data(std::initializer_list<T> initList) noexcept
{
    return initList.begin();
}

// returns size of array during compilation time 
template <typename T, std::size_t N>
constexpr std::size_t size (T const (&array)[N]) noexcept
{
    return N;
}

// Return whether the given container is empty
template <typename Container>
constexpr auto empty (Container const &c) -> decltype(c.empty())
{
    return c.empty();
}

// Return whether the given raw array is empty.
// As raw arrays cannot have zero elements in C++, this function always returns false.
template <typename T, std::size_t N>
constexpr bool empty (T const (&array)[N]) noexcept
{
    return false;
}
