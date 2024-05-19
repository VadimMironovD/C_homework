#include <iostream>
#include <string>
#include <vector>

class StringStack {
private:
    std::vector<std::string> stack;

public:

    
    void push(const std::string& str)
    { 
        stack.push_back(str);
    }

    void push(std::string&& str)
    { 
        stack.push_back(std::move(str));
    }

    
    void print() const 
    {
        std::cout << "(";
        
        for (size_t i = 0; i < stack.size(); ++i)
        {
            std::cout << stack[i];
            
            if (i < stack.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
    
    
    
    std::string pop() 
    {
        if (stack.empty()) 
        {
            throw std::out_of_range("Stack is empty");
        }
        
        std::string temp = std::move(stack.back());
        stack.pop_back();
        
        return temp;
    }
    
};


int main() 
{
    StringStack ss;
    std::string a {"Cat"};
    
    ss.push(a); 
    ss.push(std::string{"Mouse"}); 
    ss.print(); 
    
    std::cout << a << std::endl; 
    
    ss.push(std::move(a)); 
    ss.print(); 
    
    std::cout << a << std::endl; 
    std::cout << ss.pop() << std::endl;
    
    ss.print(); 
    
    std::cout << ss.pop() << std::endl; 
    std::cout << ss.pop() << std::endl; 
    ss.print(); 
    
    return 0;
}