#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct printer printer;
struct printer
{
	char* name;
	float dim_x, dim_y, dim_z;
	float nozzle;
	bool type_fdm;
};

typedef enum t_typename t_typename;
enum t_typename {
        TYPENAME_BOOL,
        TYPENAME_CHAR,
        TYPENAME_INT,
        TYPENAME_FLOAT,
        TYPENAME_STRING,
        TYPENAME_POINTER_TO_INT,
        TYPENAME_OTHER
    };

  #define typename(x) _Generic((x),                                                       \
            _Bool: TYPENAME_BOOL,          \
             char: TYPENAME_CHAR,          \
        short int: TYPENAME_SHORT_INT,     \
              int: TYPENAME_INT, 		   \
            float: TYPENAME_FLOAT,         \
           char *: TYPENAM_STRING	       \
            int *: TYPENAME_POINTER_TO_INT,\
          default: TYPENAME_OTHER)


typedef enum edit_choice edit_choice;
enum edit_choice {Name = 1, DimX = 2, DimY = 3, 
	DimZ = 4, Nozzle = 5, Type_fdm = 6};

typedef enum choice_type choice_type;
enum choice_type
{
    STRING_TYPE, BOOL_TYPE, FLOAT_TYPE
};

typedef struct choice_struct choice_struct;
struct choice_struct
{
    choice_type mychoice_type;
    union
    {
        bool bol;
        char* str;
        float flo;
    }val;
};




void remove_printer(printer *myprinter);

printer* edit_printer(printer *myprinter, edit_choice mychoice);

void display_printer(printer *myprinter);

printer* add_printer(char* sname, float sdim_x, float sdim_y, float sdim_z, 
	float snozzle, bool stype_fdm);
