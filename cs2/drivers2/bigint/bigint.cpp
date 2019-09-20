//
//  bigint.cpp
//  RivPrigOne
//
//  Created by Dawson Rivers on 9/9/19.
//  Copyright © 2019 Dawson Rivers. All rights reserved.
//

#include "bigint.hpp"

//default constructor, sets the values to 0
bigint::bigint(){
    //bgx = 0;
    //places 0 is all array spots
    for(int j = 0; j < CAPACITY; j++){
        num[j] = 0;
         //debugPrint();
}
}
 //paramerizd constructor, setting up class when called
bigint::bigint(int input) : bigint() {
    int bgx = 0;

    while(input != 0){ //puts each digit in to the correct digits place
        num[bgx] = input%10;
        input = input/10;
        ++bgx; //accumulates the array to go up places
    }
}

//method for bigints entered as characters
bigint::bigint(const char readNum[]) : bigint() {
    int countChar = 0;
    //finds the number of digits in the char
    while(readNum[countChar]!= '\0'){
        countChar++;
    }
    //removes the null from total value of the counter
    //function that puts digits in array

    for(int j = 0; j < countChar; ++j){
        num[countChar-1-j] = readNum[j];
    }
    //bgx = countChar;
}

//method for debugging
void bigint::debugPrint()const{
    for(int j = CAPACITY-1 ; j > -1; --j){
        std::cout << num[j] << " | "  ;
    }
}

//method to print out the numbers
 std::ostream& operator<<(std::ostream& y, const bigint& w){
     int maxLine = 0; //varible to keep track of digits per line
     // function used to output each digit on the line

     bool hit_number = false;
     for(int j = CAPACITY - 1; j > -1; --j){
        if(hit_number){
            y << w.num[j];
        }else if(num[j] != 0){
            hit_number = true;
            y << w.num[j];
        }
     }

     return y;

/*
    for(int j = w.bgx; j <0; j++ ){
        y << w.num[w.bgx-1-j];
        ++maxLine;
        //checks to not print more than 80 characters per line
        if(maxLine > 80){
            y << "\n";
            maxLine = 0; //resets the counter to zero
        }
    }
    return y;
    */
}
//method to find the big int length
int bigint::arrayLength()const{
    
    for(int j = CAPACITY-1; j>-1; j--){
        if(num[j] != 0){
            return j + 1; //return the big int length
        }
    }
    return 1;
}


//method to compare if two bigints are equal. It returns a bool - true if equal and false otherwise.
bool bigint::operator==(const bigint& rhs) const{
    int j = 0; // varible numAcum
    debugPrint();
    rhs.debugPrint();
    while( j < CAPACITY){
            if(num[j] != rhs.num[j]){ //checks to see if all digits are the same
                return false;
            }
        ++j;
}
    return true;
}
