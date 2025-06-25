#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyString MyString;
struct MyString {
  char* ptr;
  size_t byteSize;
};

MyString makeString(const char* str) {
  MyString string;
  size_t len = strlen(str);
  string.byteSize = len + 1;
  string.ptr = malloc(string.byteSize);
  strncpy(string.ptr, str, len);
  string.ptr[string.byteSize - 1] = '\0';
  return string;
}

void enlargeString(MyString* string, size_t byteSize) {
  string->ptr = realloc(string->ptr, byteSize);
  string->byteSize = byteSize;
  string->ptr[string->byteSize - 1] = '\0';
}

void enlargeString2(MyString* string, size_t byteSize) {
  char* newPtr = malloc(byteSize);
  newPtr[byteSize - 1] = '\0';
  size_t max = byteSize > string->byteSize ? string->byteSize : byteSize;
  strncpy(newPtr, string->ptr, max - 1);
  newPtr[max - 1] = '\0';
  string->ptr = newPtr;
  string->byteSize = byteSize;
}

int main(void) {
  MyString test = makeString("Hallo, das ist ein Test.");
  printf("%s\n", test.ptr);
  enlargeString(&test, 40);
  printf("%s\n", test.ptr);
  enlargeString(&test, 10);
  printf("%s\n", test.ptr);

  MyString test2 = makeString("Hallo, das ist ein Test.");
  printf("%s\n", test2.ptr);
  enlargeString2(&test2, 40);
  printf("%s\n", test2.ptr);
  enlargeString2(&test2, 10);
  printf("%s\n", test2.ptr);
  
  return 0;
}
