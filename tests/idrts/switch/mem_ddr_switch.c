// Here's an example including a Memory Management switch file.

// We can use Switch statement to check for equality Versus a list of values, instead of many `Else If`s.

// Every case have a value to compare with. When Switch's Value is equal another case value, Code inside it is executed til a `break` statement is achieved.

// the `break` is used to halt the switch, when the case it aligned.

#include <stdio.h> // header (important)

int main() {
   int mem_mb = 512; // Memory MB integer

   switch(state) = { // Switch
     case 1:
       printf("Ram too low. OS Won't Load");
       break;
     case 2:
       printf("Ram Detected");
       break;
     default:
       printf("RAM Memory Device 'DDR' 512MB");
   }

   return 0;
}
