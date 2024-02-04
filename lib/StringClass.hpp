#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

class String{  
    private:
        char* str; 
        int len;
    
    public:   
        // Default constructor
        String();
        
        // Destructor
        ~String();

        // Parametarized constructor 
        String(const char* copy);
        
        // Copy constructor 
        String(const String& other);

        // Copy-assignment operator
        String& operator= (const String& other);

        // Move constructor
        // && rvalue reference
        String(String&& other);

        // Move-assignment operator
        String& operator= (String&& other);

        bool operator==(const String& other) const;

        // Operator [] accesses the specified character
        char operator[](int pos) const;

        // Print the length of the string
        int printLength();
        
        // Print the string
        const char* printString();

        // To access the private members use friend keyword
        // output stream operator '<<' overloading
        friend std::ostream& operator<<(std::ostream& os, const String& obj);
        
        // Equality operator overloading 
        friend bool operator==(const String& other, const char* constStr);
};

std::ostream& operator<<(std::ostream& os, const String& obj);

bool operator==(const String& other, const char* constStr);

#endif // STRING_HPP