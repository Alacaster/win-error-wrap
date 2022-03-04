# win-error-wrap
This is not intended for release builds but use it if you want. It's super simple and I just made it for myself.
It requires the gcc extension of putting braced groups within expressions by putting parenthesis around it.
You won't see an error if you don't use "-pedantic"

**HOW TO USE:**  
First add the two C source files to your project however you do that  
Then include errorwrapper.h to your source files where you'll use it.  
So you just use WER(function()) and function can be anything.  
This is a macro which will expand to WER_16 or WER_8 depending on  
if you #define UNICODE. 16 stands for wide characters (16 bit unicode)   
it will just do everything as wchar_t instead of char. Idk why but I   
thought it'd be better.   

So the macro will resolve to the return value of the function no matter  
what type it is and it will not impact the namespace (it doesn't create  
a variable)  
 
It will also pass the value and the function name (to know how to check   
the error) and the line number and file name. Then it will hash the filename  
and check a series of strings in on of the 20 buckets (I should add more).  
Then it will return an ID when it finds a function name the same.  

You can set these IDs to anything depending on how the value should be  
checked. Some functions can share IDs if they have the same way of  
handing an error.   

All you have to do to add another function is use SETH16 and SETH8 macros  
to check the function name and return the ID like "SETH16(printf, 6)"  
which will return an ID of 6.  

Then in the large switch statement under case 6: you put "test(expression);"  
if you want the default error handler, or any custom test you want.  

Then all you have to put for every call to that function is WER() around it.  
As long as the function doesn't change how it handles errors then it should   
work forever. You can add more group handlers by using fancy goto statements.  
  
If the function doesn't return a value on error just do whatever you need   
to do to check the error in the case statement. It would be best to use the   
case statements sequentially so you don't get confused.  

Maybe one day I will create modules for several libraries which are all   
precoded with the proper error checking and you can just link them.  