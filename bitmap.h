typedef struct {
int *bitmap;
int actualLength; //actual length of bitmap
}BitMap_t;

/*Initialize bit map structure */
int BitMapNew(BitMap_t *b);
/* set the bit to bitposition*/
int BitMapSet(BitMap_t *b, int bitposition);
/* clear the bit to bitposition*/
int BitMapClear(BitMap_t *b, int bitposition);
/* check whether the bit is set*/
int BitMapIsSet(BitMap_t *b, int bitposition);
/* free allocated memory */
int BitMapFreeMemory(BitMap_t *b);

