#include "printer.h"


printer* add_printer(char* sname, float sdim_x, float sdim_y, float sdim_z, float snozzle, bool stype_fdm){
	printer *myprinter = malloc(sizeof(printer));
	myprinter->dim_x = sdim_x;
	myprinter->name = sname;
	myprinter->dim_y = sdim_y;
	myprinter->dim_z = sdim_z;
	myprinter->type_fdm = stype_fdm;
	if(myprinter->type_fdm == 0){
		myprinter->nozzle = 0;
	}else{
		myprinter->nozzle = snozzle;
	}

	return myprinter;
}


printer* edit_printer(printer *myprinter, edit_choice mychoice){
	choice_struct mychoice_str;	
	switch(mychoice){
		case Name:
			mychoice_str.val.str = "Anet A8";		// parameter to set
			myprinter->name = mychoice_str.val.str;
			break;
		case DimX: 
		case DimY: 
		case DimZ: 
		case Nozzle:
			mychoice_str.val.flo = 200;		// parameter to set 
			switch(mychoice){
				
				case DimX :
					myprinter->dim_x = mychoice_str.val.flo;
					break;
				case DimY :
					myprinter->dim_y = mychoice_str.val.flo;
					break;
				case DimZ :
					myprinter->dim_z = mychoice_str.val.flo;
					break;
				case Nozzle : 
					if(!myprinter->type_fdm){
						myprinter->nozzle = 0;
					}else{
						myprinter->nozzle = mychoice_str.val.flo;
					}
					myprinter->nozzle = mychoice_str.val.flo;
					break;
			}
			break;
		case Type_fdm:
			mychoice_str.val.bol = 0;		// parameter to set
			if(!mychoice_str.val.bol){
				myprinter->nozzle = 0;
			}
			myprinter->type_fdm = mychoice_str.val.bol;
			break; 
	}	
	return myprinter;
}


void remove_printer(printer *myprinter){
	free(myprinter);
}

void display_printer(printer *myprinter){
	printf("-------- [display_printer] --------\n");
	printf("Name : %s\n", myprinter->name);
	printf("X : %.2f\n", myprinter->dim_x);
	printf("Y : %.2f\n", myprinter->dim_y);
	printf("Z : %.2f\n", myprinter->dim_z);
	printf("Nozzle diameter : %.1f\n", myprinter->nozzle);
	if(myprinter->type_fdm){
		printf("Printer Type FDM\n");

	}else{
		printf("Printer Type Resin\n");	
	}
}