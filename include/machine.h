#pragma once

#include <exception>
#include <variant>
#include <iostream>
#include <stack>

namespace rpn {

    class underflow : public std::exception {
        virtual const char* what() const throw()
        {
            return "empty stack";
        }
    };
    
    /*
     * a stack based computing machine
     */
    template <typename D>
    class machine {
    public:

        using value_type = D;
        
        using stack_value = std::variant<D, std::string>;
        
    private:
        std::stack<stack_value> rpn;
        
    public: 
        void push(const D p) {
            rpn.push(p);
        }

        void push(std::string const &s) {
            rpn.push(s);
        }

        stack_value pop() {
            if(!rpn.empty()) {
                const auto top = rpn.top();
                rpn.pop();
                return top;
            } else {
                throw underflow();
            }
        }

        stack_value peek() {
            return rpn.top();            
        }

        int depth(void) {
            push(size());            
        }

        int size(void) {
            return rpn.size();
        }

        bool empty(void) {
            return size() == 0;
        }

        void rand(void) {
            push((double)::rand()/(double)RAND_MAX);            
        }

        void drop(void) {
            if(!rpn.empty()) {
                pop();
            }            
        }

        void swap(void) {
            if(size() >= 2) {
                const auto r2 = pop();
                const auto r1 = pop();
                rpn.push(r2);
                rpn.push(r1);
            }
        }

        void clear(void) {
            while(!rpn.empty()) {
                pop();
            }
        }
  
        void print(void) {
            if(!rpn.empty()) {
    
                const auto var = peek();
    
                std::visit( [](auto&& val) {
                        std::cout << "= " << val << std::endl;
                    },
                    var );
            }
        }

    };

}
