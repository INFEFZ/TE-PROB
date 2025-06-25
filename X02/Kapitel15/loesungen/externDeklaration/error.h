typedef enum {
  NO_ERROR,
  ERROR_DIVISION_BY_ZERO,
  ERROR_OUT_OF_MEMORY,
  ERROR_NULL_POINTER_EXCEPTION,
  ERROR_COUNT
} ErrorId;

extern const char* errorMessages[ERROR_COUNT];
