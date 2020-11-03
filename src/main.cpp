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
    along with RPN.  If not, see <https://www.gnu.org/licenses/>.

*/
#include <memory>
#include <cstdlib>

#include "printerrorhandler.h"
#include "errorhandler.h"
#include "machine.h"
#include "rpn.h"

extern "C" int yyparse(void);

rpn::machine<rpn::machine_t> machine;

std::unique_ptr<rpn::errorhandler> errorhandler;

int main(int argc, char* argv[]) {

    errorhandler = std::make_unique<rpn::printerrorhandler>();

    while(yyparse() != 0);

    ::exit(EXIT_SUCCESS);
}
