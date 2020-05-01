# rpn
## rpn cli
## rpn language

Stack based cli and interpreter.    Reverse Polish Calculator.


Supported commands

| command | description |
|---|---|
|string| push string onto stack |
|number| push number onto stack |
|drop| remove the top element from the stack |
|depth| push depth of stack onto stack, stack size is 1+previous size|
|swap| transpose the top two elements on the stack |
|clear| clear the entire contents of the stack |

Supported operations.

All operations pull parameters from the stack and repace with resuls.

|command|description|
|---|---|
|abs|absolute value|
|sqrt|square root|
|cbrt|cube root|
|sq|square of number|
|exp| e to the x|
|ln|natural logarithm|
|log|log base 10|
|alog|10 to the x|
|rootx|the x root of the value|
|pow|x to the y|
|inv|1/x|
|rand|push a random number on the stack|
|sin|sin|
|asin|arcsin|
|cos|cos|
|acos|arccos|
|tan|tan|
|atan|arctan|
|neg|-x|

