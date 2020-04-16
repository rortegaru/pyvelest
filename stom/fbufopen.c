//   Buffer memory handler based on fmemopen for MAC
//
//   There is a problem about flag EOF in reading streams in fortran
//
//   Program created 22, March, 2020. ROR.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fbufopen.h"


int readfn(void *handler, char *buf, int size) {
  fbuf_t *mem = handler;
  size_t available = mem->size - mem->pos;
  
  if (size > available) {
    size = available;
  }
  memcpy(buf, (mem->buffer)+(mem->pos), sizeof(char) * size);
  mem->pos += size+1;
  
  return size;
}

int writefn(void *handler, const char *buf, int size) {
  fbuf_t *mem = handler;
  size_t available = mem->size - mem->pos;

  if (size > available) {
    size = available;
  }
  memcpy(mem->buffer, buf, sizeof(char) * size);
  mem->pos += size;

  return size;
}

int nextchfn(void *handler, const char ch ) {
  size_t nextch;
  fbuf_t *mem = handler;
  nextch = (size_t) strchr((mem->buffer)+(mem->pos), ch);
  if(nextch){
  int numc = nextch-(int)(mem->buffer+mem->pos); 
   return numc;
  }
  else {
  return 0; }
}


size_t seekfn(void *handler, size_t offset, int whence) {
  size_t pos;
  fbuf_t *mem = handler;

  switch (whence) {
    case SEEK_SET: pos = offset; break;
    case SEEK_CUR: pos = mem->pos + offset; break;
    case SEEK_END: pos = mem->size + offset; break;
    default: return -1;
  }

  if (pos > mem->size) {
    return -1;
  }

  mem->pos = pos;
  return pos;
}

int closefn(void *handler) {
  free(handler);
  return 0;
}

fbuf_t *fbufopen(void *buf, size_t size, const char *mode) {

  // This data is released on fclose.
  fbuf_t* mem = (fbuf_t *) malloc(sizeof(fbuf_t));

  // Zero-out the structure.
  memset(mem, 0, sizeof(fbuf_t));

  mem->size = size;
  mem->buffer = buf;

  return  mem;
}
