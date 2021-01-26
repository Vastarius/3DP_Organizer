#include <stdio.h>
#include <stdlib.h>

#include "../src/function.h"
#include "../src/printer.h"

int main(void){
	printer *myprinter = (printer *)malloc(sizeof(printer));
   	myprinter = add_printer("name", 220.0, 220.0, 235.0, 0.4, 1);
   	display_printer(myprinter);
   	
   	
   	edit_printer(myprinter, Type_fdm);
   	display_printer(myprinter);
   	
   	edit_printer(myprinter, DimY);
   	edit_printer(myprinter, DimX);
   	edit_printer(myprinter, DimZ);
   	display_printer(myprinter);
   		
   	edit_printer(myprinter, Name);
   	edit_printer(myprinter, Type_fdm);
	display_printer(myprinter);
	remove_printer(myprinter);	
  	return 0;
}

