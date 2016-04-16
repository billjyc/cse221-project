//
//  main.cpp
//  ReadTSC
//
//  Created by Tao Huang on 4/15/16.
//  Copyright © 2016 Tao Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unistd.h>
#include "helper.h"
#define TIMES 1000000

using namespace std;

double readOverhead(){
    uint64_t start, end;
    double sum = 0;
    for(int i=0; i<TIMES;i++){
        start = rdtsc();
        end = rdtsc();
        sum += end - start;
    }
    double avg = sum / TIMES;
    return avg;
}

double loopOverhead(){
    uint64_t start, end;
    start = rdtsc();
    for(int i=0; i<TIMES; i++){
    }
    end = rdtsc();
    double diff = end - start;
    double avg = diff / TIMES;
    return avg;
}

void procedureCallOverhead(vector<double> &ret){
    uint64_t start, end;
    uint64_t sum = 0;
    
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        func0();
        end = rdtsc();
        sum += (end - start);
    }
    ret.push_back(sum / TIMES);
    
    sum = 0;
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        func1(1);
        end = rdtsc();
        sum += (end - start);
    }
    ret.push_back(sum / TIMES);
    
    sum = 0;
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        func2(1, 2);
        end = rdtsc();
        sum += (end - start);
    }
    ret.push_back(sum / TIMES);
    
    sum = 0;
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        func3(1, 2, 3);
        end = rdtsc();
        sum += (end - start);
    }
    ret.push_back(sum / TIMES);
    
    sum = 0;
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        func4(1, 2, 3, 4);
        end = rdtsc();
        sum += (end - start);
    }
    ret.push_back(sum / TIMES);
    
    sum = 0;
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        func5(1, 2, 3, 4, 5);
        end = rdtsc();
        sum += (end - start);
    }
    ret.push_back(sum / TIMES);
    
    sum = 0;
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        func6(1, 2, 3, 4, 5, 6);
        end = rdtsc();
        sum += (end - start);
    }
    ret.push_back(sum / TIMES);
}

double systemCallOverhead(){
    uint64_t start, end;
    double sum = 0;
    for(int i=0;i<TIMES;i++){
        start = rdtsc();
        getpid();
        end = rdtsc();
        sum += end - start;
    }
    double avg = sum / TIMES;
    return avg;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    double t1 = readOverhead();
    cout << "read overhead: " << t1 << endl;
    
    double t2 = loopOverhead();
    cout << "loop overhead: " << t2 << endl;
    
    vector<double> times;
    procedureCallOverhead(times);
    for(int i=0;i<times.size();i++){
        cout << "procedure call of " << i << " arguments overhead: " << times[i] << endl;
    }
    
    double t4 = systemCallOverhead();
    cout << "system call overhead: " << t4 << endl;
    
    
}