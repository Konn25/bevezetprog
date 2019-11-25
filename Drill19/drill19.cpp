#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S{
    public:
        explicit S(T vv = 0) : val{vv} { }

        S& operator=(const T&);

        const T& get() const;
        T& get();
    private:
        T val;
};

template<typename T>
T& S<T>::get(){
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

template<typename T> void read_val(T& v)
{
    std::cin >> v;
}



int main(){

    S<int> si {15};
    S<char> sc {'d'};
    S<double> sd {10.2};
    S<std::string> ss {"Alma"};
    S<std::vector<int>> svi {std::vector<int>{1,5,8,6,7,2}};

    std::cout << "S<int>: "<<si.get()<<"\n";
    std::cout << "S<char>: "<<sc.get()<<"\n";
    std::cout << "S<double>: "<<sd.get()<<"\n";
    std::cout << "S<string>: "<<ss.get()<<"\n";
    std::cout << "S<vector<int>>: "<<svi.get()<<"\n";

}
