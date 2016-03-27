/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utility.h
 * Author: cyrax
 *
 * Created on March 26, 2016, 9:52 AM
 */

#ifndef UTILITY_H
#define UTILITY_H

template<typename T>
void PrintData(typename LinkedList<T>::NodeType seq)
{
    if (seq.get() != nullptr) {
        if (seq->IsTail() == false) {
            std::cout << seq->GetData() << std::endl;
        } else {
            std::cout << "Search returned no results" << std::endl;
        }
    }
}

template<typename T>
void PrintSequence(typename LinkedList<T>::NodeType seq)
{

    class Print
    {
    public:

        T operator()(T obj)
        {
            std::cout << obj << ", ";
            return obj;
        }
    };


    Print p;
    Map<Print, T>(p, seq);
    std::cout << std::endl;
}

#endif /* UTILITY_H */

