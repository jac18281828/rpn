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
#include <cstdlib>
#include <iostream>
#include "printerrorhandler.h"

using namespace rpn;

void printerrorhandler::error(std::string const &message) const {
    std::cerr << "Error: " << message << std::endl;
    ::abort();
}

void printerrorhandler::underflow(void) const {
    std::cerr << "underflow." << std::endl;
}

