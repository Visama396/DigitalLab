#ifndef DL_RESULT_H
#define DL_RESULT_H

typedef enum {
    DL_OK,
    DL_INVALID_ARGUMENT,
    DL_OUT_OF_RANGE,
    DL_BUFFER_TOO_SMALL
} DlStatus;

const char *dl_status_message(DlStatus status);

#endif
