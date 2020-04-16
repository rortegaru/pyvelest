#ifndef FBUFOPEN_H_
#define FBUFOPEN_H_

struct fbuf {
  size_t pos;
  size_t size;
  char *buffer;
};
typedef struct fbuf fbuf_t;
 
fbuf_t *fbufopen(void *buf, size_t size, const char *mode);
int readfn(void *handler, char *buf, int size);
int writefn(void *handler, const char *buf, int size);
size_t seekfn(void *handler, size_t offset, int whence);
int closefn(void *handler); 


#endif // #ifndef FBUFOPEN_H_
