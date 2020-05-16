//
// Created by menin on 16.05.2020.
//

#ifndef H3_SAFE_C_ARRAY_T_H
#define H3_SAFE_C_ARRAY_T_H


#include <iostream>

template<class T>
class safe_c_array_t {
private:
    T *_data;
    size_t _size;
public:
    explicit safe_c_array_t(size_t size);

    safe_c_array_t(const safe_c_array_t &data);

    ~safe_c_array_t();

    T operator[](int index) const;

    void operator=(const safe_c_array_t &data);

    T& operator[](int index);
};




#endif //H3_SAFE_C_ARRAY_T_H
