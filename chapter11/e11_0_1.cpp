#include <iostream>

template <class T>
class Vec
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type; 
    Vec(const Vec& v){create(v.begin(),v.end())};
    Vec(){create();}
    explicit Vec(size_type n, const T& val=T()){create(n, val);}

    size_type size() const {return limit - data;}
    T& operator[](size_type i){return data[i]}
    const T& operator[](size_type i) const {return data[i];}
    Vec& operator=(const Vec&);

    iterator begin() {return data;}
    const_iterator begin() const {return data};
    iterator end() {return limit;}
    const_iterator end() const {return limit};

private:
    iterator data;//Vec中的首元素
    iterator limit;//Vec中的末元素
};

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if (&rhs!=this)
    {
        uncreate();
        create(rhs.begin(),rhs.end());
    }
    return *this;
}