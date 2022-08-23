#ifndef UTIL_H_
#define UTIL_H_
#include <vector>
#include <string.h>
using namespace std;
typedef uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;
hash_t hash_(char const* str)
{
    hash_t ret{basis};
    while (*str)
    {
        /* code */
        ret ^= *str;
        ret *= prime;
        str++;
    }
    return ret;
}
constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)  
{  
    return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;  
}  

constexpr unsigned long long operator "" _hash(char const* p, size_t)  
{  
    return hash_compile_time(p);  
}  

vector<string> split(const string &str, const string &pattern)
{
    vector<string> result;
        // vector<string> result;
    //p = strtok(str.c_str(),pattern.c_str());
    result.push_back(str);
    
    return result;
}

#endif