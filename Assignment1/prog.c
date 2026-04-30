#include <stdio.h>
#include <string.h>

#define SIZE 8   //هون خترت حجم المخزن

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

// تهيئة المخزن
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// التحقق اذا كان ممتلئ 
int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// التحقق اذا كان فارغ
int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// دالة الكتابة داخل المخزن
void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }

    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

// دالة القراءة من المخزن
char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }

    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;

    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    // إضافة CE-ESYبعد الاسم 
    strcat(name, "CE-ESY");

    // الكتابة
    for (int i = 0; i < strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    }

    // القراءة والطباعة
    printf("Output: ");
    while (!isEmpty(&cb)) {
        char c = readBuffer(&cb);
        if (c != '\0') {
            printf("%c", c);
        }
    }

    printf("\n");

    return 0;
}
