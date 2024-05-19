#include <iostream>
#include <string>
#include <vector>

class CategorySeparator {
private:
    std::vector<std::string> lvalues;
    std::vector<std::string> rvalues;

public:
   
    void push(const std::string& str)
    { 
        lvalues.push_back(str);
    }

    void push(std::string&& str)
    { 
        rvalues.push_back(std::move(str));
    }
    
    void printLvalues() const 
    {
        std::cout << "(";
        for (size_t i = 0; i < lvalues.size(); ++i)
        {
            std::cout << lvalues[i];
            if (i < lvalues.size() - 1) 
            {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }

    void printRvalues() const
    {
        std::cout << "(";
        for (size_t i = 0; i < rvalues.size(); ++i)
        {
            std::cout << rvalues[i];
            
            if (i < rvalues.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
    
};

int main() 
{
    
    CategorySeparator cs;
    
    std::string a {"Cat"};
    std::string b {"Dog"};
    
    cs.push(a); 
    cs.push(std::string{"Mouse"}); 
    
    cs.push(a + b); 
    
    cs.push(b); 
    cs.push(std::move(b)); 
    
    std::cout << a << std::endl; 
    std::cout << b << std::endl;
    
    cs.printLvalues(); 
    cs.printRvalues(); 
    
    return 0;
}