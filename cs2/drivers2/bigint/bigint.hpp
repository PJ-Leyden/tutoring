//
//  bigint.hpp
//  RivPrigOne
//
//  Created by Dawson Rivers on 9/9/19.
//  Copyright © 2019 Dawson Rivers. All rights reserved.
//

#ifndef bigint_hpp
#define bigint_hpp

#include <iostream>

const int CAPACITY = 400;

class bigint {
public:
    bigint(); //default constructor
    bigint(int);
    bigint(const char[]);
    void debugPrint()const;
    int arrayLength()const;
    bool operator==(const bigint&) const;
    
    friend std::ostream& operator<<(std::ostream&, const bigint&);

    
private:
    //int bgx;
    //arraylist for the big int
    int num[CAPACITY];
    
};

#endif
