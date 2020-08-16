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
|print|print the current top of stack|
|digits|configure the output to display the specified number of digits|

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
|sin|sine|
|asin|arcsine|
|cos|cosine|
|acos|arccose|
|tan|tangent|
|atan|arctangent|
|neg|-x|
|cosh|hyperbolic cosine|
|acosh|hyperbolic arccosine|
|sinh|hyperbolic sine|
|asinh|hyperbolic arcsine|
|tanh|hyperbolic tangent|
|atanh|hyperbolic tangent|
|ciel|integer part rounding up|
|floor|integer part rounding down|
|trunc|integer part rounding toward zero|
|round|round up if .5 or larger, down otherwise|
|mod|return any remainder resulting from dividing the two arguments|
|min|return the least of the two entries at the top of the stack|
|max|return the greater of the two entries at the top of the stack|


