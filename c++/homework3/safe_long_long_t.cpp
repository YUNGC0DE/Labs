#include <iostream>

class safe_long_long_t {

private:
    long long value;

public:
    safe_long_long_t(long long x) {
        value = x;
    }
    explicit safe_long_long_t() {
        value = 0;
    }
    long long get() {
        return value;
    }

    safe_long_long_t(safe_long_long_t const &temp) {
        value = temp.value;
    }


    void operator=(const safe_long_long_t& el) {
        value = el.value;
    }

    safe_long_long_t operator++() {
        return safe_long_long_t(++value);
    }

    safe_long_long_t operator++(int) {
        return safe_long_long_t(value++);
    }

    safe_long_long_t operator--() {
        return safe_long_long_t(--value);
    }

    safe_long_long_t operator--(int) {
        return safe_long_long_t(value--);
    }

    void operator+=(const safe_long_long_t& el) {
        value += el.value;
    }

    void operator-=(const safe_long_long_t& el) {
        value -= el.value;
    }

    void operator*=(safe_long_long_t& el) {
        value *= el.value;
    }

    void operator/=(const safe_long_long_t& el) {
        value /= el.value;
    }

    void operator%=(const safe_long_long_t& el) {
        value %= el.value;
    }

    friend std::ostream&operator<<(std::ostream &out, const safe_long_long_t &el);
};


safe_long_long_t operator+(const safe_long_long_t& el, const safe_long_long_t& el1) {
    safe_long_long_t current = el;
    current += el1;
    return current;
}

safe_long_long_t operator-(const safe_long_long_t& el, const safe_long_long_t& el1) {
    safe_long_long_t current = el;
    current -= el1;
    return current;
}

safe_long_long_t operator*(const safe_long_long_t& el, safe_long_long_t el1) {
    safe_long_long_t current = el;
    current *= el1;
    return current;
}

safe_long_long_t operator/(const safe_long_long_t& el, const safe_long_long_t& el1) {
    safe_long_long_t current = el;
    current /= el1;
    return current;
}

safe_long_long_t operator%(safe_long_long_t &el, safe_long_long_t &el1) {
    safe_long_long_t current = el;
    current %= el1;
    return current;
}

bool operator==(safe_long_long_t el, safe_long_long_t el1) {
    return el.get() == el1.get();
}

bool operator<(safe_long_long_t el, safe_long_long_t el1) {
    return el.get() < el1.get();
}

bool operator>(safe_long_long_t el, safe_long_long_t el1) {
    return el.get() > el1.get();
}

bool operator<=(safe_long_long_t el, safe_long_long_t el1) {
    return el.get() <= el1.get();
}

bool operator>=(safe_long_long_t el, safe_long_long_t el1) {
    return el.get() >= el1.get();
}

std::ostream &operator<<(std::ostream &out, const safe_long_long_t &el) {
    return out << el.value;
}


std::istream& operator>>(std::istream &stream,const safe_long_long_t &el) {
    stream >> el;
    return stream;
}

int main()
{
    safe_long_long_t custom_long = 10;

    std::cout << custom_long;

    return 0;
}