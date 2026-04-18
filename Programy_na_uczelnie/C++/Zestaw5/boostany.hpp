#ifndef BOOST_ANY_HPP
#define BOOST_ANY_HPP

#include <typeinfo>
#include <stdexcept>

namespace boost
{

class any
{
    // abstrakcyjny uchwyt na wartość
    struct placeholder
    {
        virtual ~placeholder() {}
        virtual const std::type_info& type() const = 0;
        virtual placeholder* clone() const = 0;
    };

    // konkretny uchwyt przechowujący wartość typu T
    template<typename T>
    struct holder : public placeholder
    {
        T value;

        holder(const T& val) : value(val) {}

        virtual const std::type_info& type() const
        {
            return typeid(T);
        }

        virtual placeholder* clone() const
        {
            return new holder<T>(value);
        }
    };

    placeholder* content;  // wskaźnik na przechowywaną wartość

public:
    // konstruktor domyślny — pusta wartość
    any() : content(nullptr) {}

    // konstruktor z wartością
    template<typename T>
    any(const T& val) : content(new holder<T>(val)) {}

    // konstruktor kopiujący
    any(const any& other)
        : content(other.content ? other.content->clone() : nullptr) {}

    // destruktor
    ~any()
    {
        delete content;
    }

    // operator przypisania dla wartości
    template<typename T>
    any& operator=(const T& val)
    {
        delete content;
        content = new holder<T>(val);
        return *this;
    }

    // operator przypisania kopiujący
    any& operator=(const any& other)
    {
        if(this != &other)
        {
            delete content;
            content = other.content ? other.content->clone() : nullptr;
        }
        return *this;
    }

    // zwraca type_info przechowywanego typu
    const std::type_info& type() const
    {
        return content ? content->type() : typeid(void);
    }

    // czy jest pusta
    bool empty() const
    {
        return content == nullptr;
    }

    // any_cast potrzebuje dostępu do content
    template<typename T>
    friend T any_cast(const any& a);
};

// wyjątek rzucany gdy rzutowanie się nie powiedzie
class bad_any_cast : public std::bad_cast
{
public:
    const char* what() const noexcept override
    {
        return "bad_any_cast: failed conversion";
    }
};

// wyciąga wartość typu T z any
template<typename T>
T any_cast(const any& a)
{
    if(a.type() != typeid(T))
        throw bad_any_cast();

    return static_cast<any::holder<T>*>(a.content)->value;
}

} // namespace boost

#endif
