#include <iostream>
#include <cassert>
#include "string.hpp"

////////////////////////

String::String(){
  
  stringSize = 1;
  str = new char[stringSize];
  str[0] = 0;
}

String::String(const char ch){

  stringSize = 2;
  str = new char[stringSize];
  str[0] = ch;
  str[1] = 0;
}

String::String(const char s[]){
  
  int i = 0;
  while(s[i] != 0){
      i++;
  }
    
    stringSize = i + 1;
    str = new char[stringSize];
    
    for(int j = 0; j < stringSize-1; j++){
    str[j] = s[j];
   }
    
    str[stringSize-1] = '\0'; 
}

String::String(int i){
  stringSize = i +1;
  str = new char[stringSize];
}

String::String(int num, const char* ch){

  stringSize = num + 1;
  str = new char[stringSize];
  int i = 0;
  
  while(ch[i] != '\0'){
    str[i] = ch[i];
    ++i;
  }
  str[i]= '\0';
}

String::String(const String& rhs){

  stringSize = rhs.stringSize;
  str = new char[stringSize];
  
  for(int i =0; i < stringSize-1; ++i){
    str[i] = rhs.str[i];
  }
  str[stringSize-1] = '\0';
}
 
String:: ~String(){
  delete[] str;
}

///////////////////////////

int String::capacity() const {
  return stringSize-1;
}

int String::length() const {
  
  int len = 0;
  while(str[len] != 0){
    ++len;
  }
  return len;
}

void String::swap(String& rhs){
  char* temp = str;
  str = rhs.str;
  rhs.str = temp;

  int tempSize = stringSize;
  rhs.stringSize = stringSize;
  stringSize = tempSize;
}

///////////////////////////

char String::operator[](int i) const{

  if(0 > i)  i = 0;
  
  if(i >= capacity()) i = capacity() - 1;
  
  return str[i];
}

char& String::operator[](int i ){
  
  if(0 > i) i = 0;
  
  if(i >= capacity())  i = capacity() - 1;
  
  return str[i];
}
/////////////////////////


String String::operator+(const String& rhs) const {
  int totalLen = length() + rhs.length() + 1;
  String result (totalLen,str);
  
  for(int i = length(); i < totalLen; i++){
    result.str[i] = rhs.str[i - length()];
  }
  return result;
}

String& String::operator=(String arr){
  stringSize = arr.stringSize;
  swap(arr);
  return *this;
}

String& String::operator+=(const String& rhs){
  int start = length();
  int i = 0;
  
  while(rhs.str[i] != 0){
    if((start + i) >= capacity())
      break;
      str[start + i] = rhs.str[i];
      i++;
  }
    str[start + i] = 0;
    return *this;
}
 
bool String::operator==(const String& rhs) const{

  int i = 0;
  while((str[i] != 0) && (str[i] == rhs.str[i]))
    i++;
 
  return str[i] == rhs.str[i];
}

bool String::operator<(const String& rhs) const{

  int i = 0;
  while((str[i] != 0) && (rhs[i] != 0) &&  (str[i] == rhs.str[i])){
    ++i;
  }
  return str[i] < rhs.str[i];
}

///////////////////////////

std::istream& operator>>(std::istream& in, String& rhs){

  char temp[256];
  in >> temp;
  
  String tempStr(temp);
  rhs.swap(tempStr);
  return in;
}

std::ostream& operator<<(std::ostream& out,const String& rhs){
  
  out << rhs.str;
  return out;
}

////////////////////////////

String String::substr(int start, int end) const{
  
  int i = 0;
  char temp[256];

  for(i = start; i <= end; i++){
    if( i < length()){
      temp[i+start] = str[i];
    }
  }
  
  temp[i-start] = '\0';
  String result(temp);
  return result;
}

int String::findch(int pos, char target) const{

  int i = pos;
  while(str[i] != '\0'){
      if(str[i] == target){
	  return i;
      }
      i++;
    }
  return -1;
}

int String::findstr(int pos, const String& target) const{

  int i = pos;
  while(str[i] != 0){
    if(str[i] == target.str[0]){
      int find = 0;
      while((str[i+find]) == (target.str[find])
	    && (str[i + find] != 0) && (target.str[find] != 0)){
	find++;
      }
      if(find == target.length()){
	return i;
      }
    }
    ++i;
  }
  return -1;
}

void String:: resetCapacity(int num){
  char* temp = str;
  str = new char[num];
  
  for(int i = 0; i < num; i--){
    str[i] = temp[i];
    temp[i] = capacity();
  }
}

////////////////////////
inline String operator+(const char lhs[], const String& rhs){
  return String(lhs) + rhs;
}

inline bool operator==(const char lhs[], const String& rhs){
  return String(lhs) == rhs;
}

inline bool operator==(const char lhs, const String& rhs){
  return String(lhs) == rhs;
}

inline bool operator<(const char lhs[], const String& rhs){
  return String(lhs) < rhs;
}

inline bool operator<(const char lhs, const String& rhs){
  return String(lhs) < rhs;
}

inline bool operator<=(const String& lhs, const String& rhs){
  return ((lhs < rhs) || (lhs == rhs));
}

inline bool operator!=(const String& lhs, const String& rhs){
  return !(lhs == rhs);
}

inline bool operator>=(const String& lhs, const String& rhs){
  return !(lhs < rhs);
}

inline bool operator>(const String& lhs, const String& rhs){
  return (rhs < lhs);
}