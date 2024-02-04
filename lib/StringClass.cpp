    #include "StringClass.hpp"
    
    // Default Constructor
    String::String() : str(new char[1]), len(1){
        std::cout << "Default Constructor" << std::endl;
        str[0] = '\0'; // Initialize the string with a null terminator
    }
    // Destructor
    String::~String(){ delete[] str; } // Deallocate the memory
            
    // Parametarized constructor 
    String::String(const char* copy){ 
        std::cout << "Parametarized Constructor" << std::endl;
        len = std::strlen(copy);
        str = new char[len + 1];
        std::strcpy(str, copy);
    } 
    
    // Copy constructor 
    String::String(const String& other){
        std::cout << "Copy Constructor" << std::endl;
        this->len = other.len; 
        this->str = new char[len + 1];
        std::strcpy(str, other.str);
    }
            
    // Copy-assignment operator
    String& String::operator= (const String& other){
        std::cout << "Copy-assignment operator" << std::endl;
        if(this != &other){
            delete [] this->str;
            this->len = other.len;
            str = new char[len + 1];
            std::strcpy(this->str, other.str);
        }
        return *this;
    }

    // Move constructor
    // && rvalue reference
    String::String(String&& other){
        std::cout << "Move constructor" << std::endl;
        if(other.str){
            this->str = other.str;  // Transfer ownership
            this->len = other.len;
            other.str = nullptr;  // Set to null to avoid double deletion
            other.len = 0;  // Reset the length
        }
    }

    // Move-assignment operator
    String& String::operator= (String&& other){
        std::cout << "Move-assignment operator" << std::endl;
        if(this != &other){
            delete[] this->str;
            len = other.len;
            str = new char[len + 1];
            std::strcpy(str, other.str);
            delete[] other.str;
            other.str = nullptr;
        }
        return *this;
    }

    bool String::operator==(const String& other) const{
        return (this->len == other.len) && (std::strcmp(str, other.str) == 0);
    }
    
    // Operator [] accesses the specified character
    char String::operator[](int pos) const{
        if(pos < 0 || pos >= this->len){
            throw std::out_of_range("Index out of bounds");
        }
        return *(this->str + pos);
    }
            
    // Print the length of the string
    int String::printLength() { return len; }
            
    // Print the string
    const char* String::printString(){ return str; }

    std::ostream& operator<<(std::ostream& os, const String& obj)
    {
        os << obj.str;
        return os;
    }

    bool operator==(const String& other, const char* constStr) {
            return (std::strcmp(constStr, other.str) == 0);
    }