Valgrind like program
you can check with this api whether there is a dynamic allocation leak or not and how many

using:
at fisrt of the program add initMemory()
at end of the program add finishMemory()

use allocate instead of malloc like: "int* i = allocate(sizeof(int));"
use deallocate instead of free function like: "deallocate(i,sizeof(*i));"

you have to tell the size of the pointer which is sizeof(*i)