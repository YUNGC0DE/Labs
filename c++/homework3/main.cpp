#include <iostream>

class Safe_long_long_t{
private:
    long long value;
public:
    Safe_long_long_t(long long i){
        value = i;
    }

    long long Value(){
        return value;
    }

    Safe_long_long_t operator+(Safe_long_long_t b){
        return {this->value + b.value};
    }
    Safe_long_long_t operator-(Safe_long_long_t b){
        return {this->value - b.value};
    }
    Safe_long_long_t operator*(Safe_long_long_t b){
        return {this->value * b.value};
    }
    Safe_long_long_t operator/(Safe_long_long_t b){
        return {this->value / b.value};
    }
};
std::ostream& operator<<(std::ostream &out, Safe_long_long_t i)
{
    out << i.Value();
    return out;
}
std::istream& operator>>(std::istream &in, Safe_long_long_t i)
{
    in >> i.Value();
    return in;
}


int main() {
    Safe_long_long_t a = Safe_long_long_t(1);
    std::cout << a;

}
