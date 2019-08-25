#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include <assert.h>
#include <string.h>

#define MAX_BITS_PER_INDEX 32

/*Initialize bit map structure */
/*return 0 for success -1 for failure */
int  BitMapNew(BitMap_t *b) {

   assert(b!=NULL);

   b->bitmap = (int *) calloc(1, sizeof(int));

   if (b->bitmap == NULL) {

       printf("Memory allocation is failed during init \n\r");

       return -1;
   }

   b->actualLength = 1;

   return 0;
}
/* set the bit to bitposition*/
/* return 0 for success , -1 for failure*/ 
int BitMapSet(BitMap_t *b, int bitposition) {

    int *temp = NULL;

    int newMemBlockLength = 0;

    assert(b!=NULL);

   /* bit position should not be less than zero */
   if (bitposition < 0) {

      printf("Bit position can't be less than zero %d\n\r", bitposition);

      return -1;
   }

   int byteIndex = bitposition/MAX_BITS_PER_INDEX;

   int bitPos = bitposition%MAX_BITS_PER_INDEX;

   //Grow bit map pointer
   if ((byteIndex + 1) > b->actualLength) {

       b->actualLength += byteIndex; 

       // Incase unable to grow memory, we need not reset existing memory, hence point to temp pointer
       temp  = (int *)realloc(b->bitmap, (b->actualLength * sizeof(int)));
       if (temp == NULL) {

           printf("Realloc failed to grow bitmap size for bitposition %d\n\r", bitposition);

           return -1;
       }

       //initialize newly allocated memory block because realloc will return uninitialize memory for extended memory size
       newMemBlockLength = (b->actualLength - byteIndex);

       memset(temp+newMemBlockLength, 0, (newMemBlockLength * sizeof(int)));

       b->bitmap = temp;
       printf("Memory dynamically extended: new dynamic Array size : %ldB\n\n\r", (b->actualLength * sizeof(int)));
       
   }

   b->bitmap[byteIndex] |= (1 << bitPos);

   return 0;
}

/* clear the bit to bitposition*/

int BitMapClear(BitMap_t *b, int bitposition) {

   assert(b!=NULL);

   /* bit position should not be less than zero */
   if (bitposition < 0) {

      printf("Bit position can't be less than zero %d\n\r", bitposition);

      return -1;

   }

   int byteIndex = (bitposition / MAX_BITS_PER_INDEX);

   int bitPos = (bitposition % MAX_BITS_PER_INDEX);

   if ((byteIndex + 1) > b->actualLength) {

       printf("bitposition %d is beyond the bitmap size %ld \n\r", bitposition, (b->actualLength * sizeof(int)));
       return -1;
   }

   b->bitmap[byteIndex] &= ~(1 << bitPos);

   return 0;

}

/* check whether  the bit is set*/
/* return 1 if bit is set, 0 if bit is not set, -1 for out of boundary */
int BitMapIsSet(BitMap_t *b, int bitposition) {

   assert(b!=NULL);

   /* bit position should not be less than zero */
   if (bitposition < 0) {

      printf("Bit position can't be less than zero %d\n\r", bitposition);

      return -1;
   }

   int byteIndex = (bitposition / MAX_BITS_PER_INDEX);

   int bitPos = (bitposition % MAX_BITS_PER_INDEX);

   if ((byteIndex + 1) > b->actualLength) {

       printf("bitposition %d is beyond the bitmap size %ld \n\r", bitposition, (b->actualLength * sizeof(int)));
       return -1;
   }
   

   return (b->bitmap[byteIndex] & (1 << bitPos)?1 : 0);
}

/* free allocated memory */
int BitMapFreeMemory(BitMap_t *b) {

   assert(b!=NULL); 

   if (b->bitmap != NULL) {

    free(b->bitmap);

    b->bitmap = NULL;

   }
   return 0;
}

int main(int argc, char *argv[]) {

    BitMap_t bitmap;

    int ret = 0;

    int bitOperation = 0;

    int bitposition = 0;

    int option;

    int c = 1;

    if (argc < 2) {
	printf("Enter bitpositions as arguments to program\n\r");
	exit(0);
    }

    ret = BitMapNew(&bitmap);
    if (ret < 0) {
       printf(" bitmap init failed\n");
       exit(0);
    }

    for(int i = 1; i < argc; i++) {

        bitposition = atoi(argv[i]);

	printf("	Setting %dth bit position \n\n\r", bitposition);

        ret = BitMapSet(&bitmap, bitposition);
        if ( ret < 0) {

           printf("BitMapSet is failed \n\r");

	   break;
	}

	printf("	checking %dth bit position \n\r", bitposition);

        ret = BitMapIsSet(&bitmap, bitposition);
        if ( ret < 0) {

           printf("bit position check is failed \n\r");

	}

	printf("	%dth bit position status  1 for set, 0 for not set: %d\n\n\r", bitposition, ret);

	printf("	Clearing %dth bit position \n\r", bitposition);

	ret = BitMapClear(&bitmap, bitposition);
	if ( ret < 0) {
            printf("bit position clear is failed \n\r");
	}

	printf("	checking %dth bit position after reset \n\n\r", bitposition);

        ret = BitMapIsSet(&bitmap, bitposition);
        if ( ret < 0) {
           printf("bit position check is failed \n\r");
	}
	printf("	%dth bit position status  1 for set, 0 for not set: %d\n\r", bitposition, ret);
    }
    
    while (c == 1) {
	printf("	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit \n\r");
	scanf("%d",&c);
        if (c == 2) {
            break;
	}

        printf("	Choose the bit operation from Menu \n\n\r");
        printf("	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: \n\n\r");
        scanf("%d",&option);
        switch(option) {
            case 1:
		printf("	Enter the bit position to be set \n\n\r");
                scanf("%d",&bitposition);

		ret = BitMapSet(&bitmap, bitposition);
		if ( ret < 0) {

		    printf("BitMapSet is failed \n\r");

		}
		break;
            case 2:
		printf("	Enter the bit position to check\n\n\r");
                scanf("%d",&bitposition);

		printf("	checking %dth bit position \n\r", bitposition);

		ret = BitMapIsSet(&bitmap, bitposition);
		if ( ret < 0) {

		    printf("bit position check is failed \n\r");

		}

		printf("	%dth bit position status  1 for set, 0 for not set: %d\n\n\r", bitposition, ret);
		break;

           case 3:
		printf("	Enter the bit position to be cleared \n\r");
                scanf("%d",&bitposition);
		printf("	Clearing %dth bit position \n\r", bitposition);

		ret = BitMapClear(&bitmap, bitposition);
		if ( ret < 0) {
		    printf("bit position clear is failed \n\r");
		}
		break;
           default:
              printf("		Invalid option entered\n\r");

	}
        
        
    }
   

    //clear allocated memory
    BitMapFreeMemory(&bitmap);

    exit(0);
    
}
