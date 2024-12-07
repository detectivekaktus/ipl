#ifndef __IPL_MACROS_ARRAY
#define __IPL_MACROS_ARRAY

#define crash(msg) \
  do { \
    printf(msg); \
    exit(1); \
  } while (0)

#define DA_INIT_CAPACITY 32

#define da_alloc(type) (type*) calloc(1, sizeof(type))
#define da_append(da, item) \
  do { \
    if ((da)->size >= (da)->capacity) { \
      (da)->capacity = (da)->capacity == 0 ? DA_INIT_CAPACITY : (da)->capacity * 2; \
      (da)->items = realloc((da)->items, (da)->capacity * sizeof(*(da)->items)); \
      if ((da)->items == NULL) crash("Couldn't update a dynamic array capacity"); \
    } \
    (da)->items[(da)->size++] = (item); \
  } while (0)
#define da_heapfree(da) \
  do { \
    free((da)->items); \
    free(da); \
  } while (0)
#define da_free(da) free((da)->items)

#endif
