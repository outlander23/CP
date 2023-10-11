#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <string>
#include <complex>

// Helper function to print any type
template <typename T>
void print(const T &value)
{
    std::cout << value << " ";
}

// Specializations for std::pair
template <typename T1, typename T2>
void print(const std::pair<T1, T2> &pair)
{
    std::cout << "(" << pair.first << ", " << pair.second << ") ";
}

// Specializations for containers
template <typename T>
void printContainer(const T &container)
{
    std::cout << "[ ";
    for (const auto &element : container)
    {
        print(element);
    }
    std::cout << "]\n";
}

// Specializations for arrays
template <typename T, std::size_t N>
void print(const std::array<T, N> &array)
{
    printContainer(array);
}

template <typename T>
void print(const std::vector<T> &vector)
{
    printContainer(vector);
}

template <typename T>
void print(const std::list<T> &list)
{
    printContainer(list);
}

template <typename T>
void print(const std::deque<T> &deque)
{
    printContainer(deque);
}

template <typename T>
void print(const std::set<T> &set)
{
    printContainer(set);
}

template <typename T>
void print(const std::multiset<T> &multiset)
{
    printContainer(multiset);
}

template <typename KeyType, typename ValueType>
void print(const std::map<KeyType, ValueType> &map)
{
    std::cout << "{ ";
    for (const auto &pair : map)
    {
        print(pair.first);
        std::cout << " -> ";
        print(pair.second);
    }
    std::cout << "}\n";
}

template <typename KeyType, typename ValueType>
void print(const std::multimap<KeyType, ValueType> &multimap)
{
    std::cout << "{ ";
    for (const auto &pair : multimap)
    {
        print(pair.first);
        std::cout << " -> ";
        print(pair.second);
    }
    std::cout << "}\n";
}

// Specializations for queues
template <typename T>
void print(const std::queue<T> &queue)
{
    std::queue<T> tempQueue = queue; // Create a copy of the original queue
    std::vector<T> elements;         // Create a vector to store the elements

    while (!tempQueue.empty())
    {
        elements.push_back(tempQueue.front()); // Copy elements to the vector
        tempQueue.pop();
    }

    std::cout << "Queue: ";
    printContainer(elements); // Print the vector
}

// Specializations for stacks
template <typename T>
void print(const std::stack<T> &stack)
{
    std::stack<T> tempStack = stack; // Create a copy of the original stack
    std::vector<T> elements;         // Create a vector to store the elements

    while (!tempStack.empty())
    {
        elements.push_back(tempStack.top()); // Copy elements to the vector
        tempStack.pop();
    }

    std::cout << "Stack: ";
    printContainer(elements); // Print the vector
}
// Specializations for bitsets
template <std::size_t N>
void print(const std::bitset<N> &bitset)
{
    std::cout << "[ ";
    for (std::size_t i = 0; i < N - 1; i++)
    {
        std::cout << bitset[i] << ", ";
    }
    std::cout << bitset[N - 1] << " ]" << std::endl;
}

// Specializations for strings
void print(const std::string &str)
{
    std::cout << str << std::endl;
}

// Specializations for C-style strings (char*)
void print(const char *str)
{
    std::cout << str << std::endl;
}

// Specializations for complex numbers
template <typename T>
void print(const std::complex<T> &complex)
{
    std::cout << "(" << complex.real() << ", " << complex.imag() << ")";
}

// Overload to print a string prefix followed by any number of arguments
template <typename... Args>
void printWithPrefix(const std::string &prefix, const Args &...args)
{
    std::cout << prefix;
    (print(args), ...);
    std::cout << '\n';
}
template <typename... Args>
void print(const Args &...args)
{

    (print(args), ...);
    std::cout << '\n';
}

#endif // DEBUG_H
