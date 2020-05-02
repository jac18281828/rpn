/*

    Copyright © John A Cairns <john@2ad.com> 2016-2020

    This file is part of RPN.

    RPN is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPN is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.

*/
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
