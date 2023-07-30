#include <iostream>
#include <cstdlib>
#include <random>
#include "PriorityQueueArr.h"
#include "PriorityQueuePtr.h"
#include <chrono>
#include <iomanip>

//#define TEST
#define NUMBER 50000
#define SEED 27331

// The same seed is used to feed the random generator twice - for two implementations.

int main()
{
#ifdef TEST
    PriorityQueueArr k;
    std::cout<<k.isEmpty()<<"\n";
    k.add(10,10);
    k.printTab();
    k.add(5,5);
    k.add(4,4);
    k.add(3,1);
    std::cout<<k.toString()<<"\n";
    //std::cout<<k.peek()<<"\n";
    //k.pop();
    std::cout<<k.toString()<<"\n";
    //pop();
    std::cout<<k.toString()<<"\n";
    k.add(1000);
    k.add(1000);
    k.add(1000);
    k.add(1000);
    k.add(1000);
    k.add(1000);
    k.add(1000);
    k.add(1000);
    k.add(8, 1);
    k.pop();
    k.pop();
    k.pop();
    k.pop();
    k.pop();
    k.add(3,1);
    k.add(3,1);
    k.add(3,1);
    k.add(3,1);
    k.add(9,0);
    std::cout<<k.toString()<<"\n";
    k.printTab();

    PriorityQueuePtr kol;
    kol.add(10,10);
    kol.add(10,10);
    kol.add(10,10);
    kol.add(10,10);
    kol.add(5,5);
    kol.add(1,1);
    std::cout<<kol.toString()<<"\n";
    kol.pop();
    std::cout<<kol.toString()<<"\n";
    kol.pop();
    std::cout<<kol.toString()<<"\n";
#endif
#ifndef TEST
    PriorityQueueArr arr(NUMBER);
    srand(SEED);
    auto start = std::chrono::high_resolution_clock::now();
    int add_number = rand()%(NUMBER/2)+(NUMBER/2);
    for(int i=0; i<add_number; i++){ // 0 - 24999 + 25000
        arr.add(rand()%NUMBER, rand()%MAX_PRIORITY);
    }
    int del_num = rand()%(NUMBER/2)+(NUMBER/2);
    for(int i=0; i<del_num; i++){ // 0 - 24999 + 25000
        arr.pop();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<<"Number of additions: "<<add_number<<", Number of deletions: "<<del_num<<"\n";
    std::chrono::duration<double> diff = end-start;
    std::cout<<"Array: ";
    std::cout<<std::setw(9)<<diff.count()<<" s.\n";

    PriorityQueuePtr ptr;
    srand(SEED);
    start = std::chrono::high_resolution_clock::now();
    add_number = rand()%(NUMBER/2)+(NUMBER/2);
    for(int i=0; i<add_number; i++){ // 0 - 49999 + 50000
        ptr.add(rand()%NUMBER, rand()%MAX_PRIORITY);
    }
    del_num = rand()%(NUMBER/2)+(NUMBER/2);
    for(int i=0; i<del_num; i++){ // 0 - 49999 + 50000
        ptr.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout<<"Number of additions: "<<add_number<<", Number of deletions: "<<del_num<<"\n";
    diff = end-start;
    std::cout<<"Pointers: ";
    std::cout<<std::setw(9)<<diff.count()<<" s.\n";
    return 0;
#endif
}
