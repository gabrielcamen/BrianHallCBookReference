//
// Created by Gabe C on 31.12.2025.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct car {
    char *name;
    float price;
    int speed;
};

void NineFileInputOutput(void);
void set_price(struct car *carToUpdate, float newPrice);
void print_car_specs(struct car *carToPrint);
void EightStructs(void);
int my_strlen(char *s);
void SevenStrings();
void double_array(int *f, int len);
void print_continues(void);
void print_spaces(void);
void SixArrays(void);
void increment(int *pointer);
//function prototype, can be defined here and implementation later
int plus_one(int n);
//if you dont type void when there is 0 arguments then the compiler might not give you errors if this is called with a parameter
//In modern C, void foo(void) means “no arguments”, while void foo() means “I don’t know what arguments”, so always use void.
void print_hello(void);
void print_number_and_pointer(int someNumber, int* pointerToSomeNumber, int **pointToSomeNumberByReference);
void passing_array_to_function_size_of(float[4]);
void pass_array_by_reference(int *f, int len);
void pass_array_by_notation(int f[], int len);

int main(void) {
    //3. Variables and statements
    int i = 0;
    float f = 3.1414;
    char *s = "Hello World!";
    printf("String value is: %s, Float value is %f, int value is %d\n", s, f, i);
    bool myValue = true;
    if (myValue == true) {
        printf("Bools work with stdbool.h\n");
    }else {
        printf("Bools do not work with stdbool.h\n");
    }

    int a = 999;
    printf("%zu\n", sizeof(a));
    printf("%zu\n", sizeof(-a));
    printf("%zu\n", sizeof(2 + 7));
    printf("%zu\n", sizeof(3.14));

    //basic loop that can be done like this
    while (i < 10) {
        printf("i is now: %d\n", i);
        i++;
    }

    //you can infinte loop and break out of it
    while (1) {
        if (i == 20) {
            break;
        }
        printf("i is now: %d\n", i);
        i++;
    }

    for (i = 0; i < 10; i++) {
        printf("i is now in for loop: %d\n", i);
    }
    /*
    for (;;) {
        printf("This will run infinetely until you hit CTRL-C.\n");
    }
    */

    char character = 'b';
    switch (character) {
        case 'a':
            printf("a was pressed\n");
            break;
        case 'b':
            printf("b was pressed\n");
            break;
        case 'c':
            printf("c was pressed\n");
            break;
    }
    //4. Functions
    int value = 5;
    printf("value is: %d\n", plus_one(value));
    print_hello();

    //5. Pointers
    int someNumber = 25;
    int* pointerToSomeNumber = &someNumber;
    print_number_and_pointer(someNumber, pointerToSomeNumber, &pointerToSomeNumber);

    someNumber += 42;
    print_number_and_pointer(someNumber, pointerToSomeNumber, &pointerToSomeNumber);
    *pointerToSomeNumber += 55;
    print_number_and_pointer(someNumber, pointerToSomeNumber, &pointerToSomeNumber);
    //increasing the pointer itself makes it point to some random garbage location that has nothing in it
    pointerToSomeNumber += 100;
    print_number_and_pointer(someNumber, pointerToSomeNumber, &pointerToSomeNumber);
    *pointerToSomeNumber += 55;
    print_number_and_pointer(someNumber, pointerToSomeNumber, &pointerToSomeNumber);
    increment(&someNumber);
    print_number_and_pointer(someNumber, pointerToSomeNumber, &pointerToSomeNumber);

    int* nullPointer = NULL;
    printf("Null pointer is %p\n", (void*)nullPointer);
    //seg fault if you dereference null pointer
    //*nullPointer += 1;

    //if this is not initialized this will point to garbage or null pointer
    int* garbagePointer;
    printf("Garbage pointer is %p\n", (void*)garbagePointer);

    //p is a int*, q is just an int
    int *p, q;
    //z is a int*, x is just an int, same declaration as above
    int* z, x;

    int d = 23;
    int *dPointer = &d;
    printf("Size of pointer dpointer: %zu\n", sizeof(dPointer));
    printf("Size of value dpointer points to %zu\n", sizeof(*dPointer));

    //6. Arrays
    SixArrays();
    print_spaces();
    //7. Strings
    SevenStrings();
    print_spaces();
    //8. Structs
    EightStructs();
    print_spaces();
    //9. File Input/Output
    NineFileInputOutput();
    print_spaces();
}

int plus_one(int n) {
    return n + 1;
}

void print_hello() {
    printf("Hello World!\n");
}

void increment(int *pointer) {
    *pointer = *pointer + 1;
}

void print_number_and_pointer(int someNumber, int* pointerToSomeNumber, int **pointToSomeNumberByReference) {
    print_continues();
    printf("The value of someNumber is: %d\n", someNumber);
    printf("The address of pointerToSomeNumber is %p\n",  (void *)pointerToSomeNumber);
    printf("The address of pointToSomeNumberByReference is %p\n",  (void *)pointToSomeNumberByReference);
    printf("The value of pointer to some number:%d\n", *pointerToSomeNumber);
    print_continues();
}

void print_spaces() {
    printf("--------------------------------\n");
}

void print_continues() {
    printf("======>>=====>>=====>>========>>\n");
}

void SixArrays(void) {
    print_spaces();
    printf("6. Arrays\n");
    //size of the array must be fixed.
    float f[4];

    f[0] = 3.1415;
    f[1] = 2.3232;
    f[2] = 5.1241;
    f[3] = 2451.51;

    for (int i = 0; i < 4; i++) {
        printf("%f\n", f[i]);
    }
    //how to get the size of an array in the scope, this won't work if you are passing it to a function
    constexpr size_t total_size = sizeof(f);
    constexpr size_t element_size = sizeof(f[0]);
    printf("Size of all elements: %zu\n", total_size);
    printf("Size of one element: %zu\n", element_size);
    printf("How many elements: %zu\n", total_size / element_size);
    passing_array_to_function_size_of(f);
    print_continues();
    printf("Size needed for a double array of 48 elements: %zu\n", sizeof(double[48]));
    print_continues();
    // Initialize array in one line
    int a[5] = {22, 37, 3490, 18, 95};
    for (int i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }
    print_continues();
    //Make the first element zero, and then automatically make the rest zero, as well
    int z[100] = {0};
    //element at position 5 is going to be 55, rest is 0 then the ones define
    int my[10] = {0, 11, 22, [5]=55, 66, 77};
    //you do not need to specify the size explicit
    int xz[] = {0, 11, 22, [5]=55, 66, 77};
    //you can exceed the element of an array and go overboard it will just print what is at that data adress
    for (int i = 0; i < 15; i++) {
        printf("Size of one element: %d\n", xz[i]);
    }
    print_continues();
    int row, col;
    int v[2][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 5; col++) {
            printf("(%d,%d) = %d\n", row, col, v[row][col]);
        }
    }
    print_continues();
    // Make a 3x3 identity matrix
    int identity[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            printf("(%d,%d) = %d\n", row, col, identity[row][col]);
        }
    }
    print_continues();
    pass_array_by_reference(a, 5);
    print_continues();
    pass_array_by_notation(a, 5);
    print_continues();
    int stackInt = 5;
    //even if the method is defined as an array, you can pass anything that is a pointer to the value of that array and it will just iterate through that memory space
    pass_array_by_notation(&stackInt, 5);
    print_continues();
    int mv[5] = {1, 2, 3, 4, 5};
    double_array(mv, 5);
    for (int i = 0; i < 5; i++)
        printf("%d\n", mv[i]);
}

void passing_array_to_function_size_of(float f[4]) {
    //because this is passed this actually points to the pointer of the first element in the list
    constexpr size_t total_size = sizeof(f);
    constexpr size_t element_size = sizeof(f[0]);
    printf("Size of all elements: %zu\n", total_size);
    printf("Size of one element: %zu\n", element_size);
    printf("How many elements: %zu\n", total_size / element_size);
}

void pass_array_by_reference(int *f, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", f[i]);
    }
}

void pass_array_by_notation(int f[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", f[i]);
    }
}

void double_array(int *f, int len) {
    for (int i = 0; i < len; i++) {
            f[i] *= 2;
    }
}

void SevenStrings(void) {
    //This form points to wherever that string was placed. Typically, that place is in a land faraway from the rest of your program’s memory – read-only memory – for reasons related to performance & safety.
    char *s = "This is a nice string";
    //But declaring it as an array is different. The compiler doesn’t stow those bytes in another part of town, they’re right down the street. This one is a mutable copy of the string – one we can change at will:
    char se[] = "This is a nice string as well";
    printf("%s\n", s);
    printf("%c\n", s[0]);
    printf("%c\n", se[0]);
    print_continues();
    //undefined behavior will produce a crash
    //s[0] = 'E';

    //this actually works
    se[0] = 'E';
    printf("%c\n", s[0]);
    printf("%c\n", se[0]);
    print_continues();
    printf("Length of se is: %zu\n", strlen(se));
    print_continues();
    printf("Length of se is: %d\n", my_strlen(se));
    print_continues();
    char sw[] = "Hello, world!";
    printf("%zu\n", sizeof(sw));
    char t[sizeof(sw)];
    strcpy(t, sw);
    t[0] = 'z';
    // s remains unaffected
    printf("%s\n", sw);
    // But t has been changed
    printf("%s\n", t);
}

int my_strlen(char *s) {
    int count = 0;
    while (s[count] != '\0') { count++;}
    return count;
}


void EightStructs(void) {
    struct car myCar = { "someName", 25, 150 };
    print_car_specs(&myCar);
    print_continues();
    struct car otherCar = {.speed = 150, .price = 25};
    set_price(&otherCar, 500);
    print_car_specs(&otherCar);
    print_continues();
    struct car *myCarPointer = &myCar;
    char *myCarNamePointer = myCar.name;
    float *myCarPricePointer = &myCar.price;
    int *myCarSpeedPointer = &myCar.speed;
    printf("Car struct pointer:  %p\n", (void*) myCarPointer);
    printf("Name pointer:  %p\n", myCarNamePointer);
    printf("Price pointer: %p\n", (void*) myCarPricePointer);
    printf("Speed pointer: %p\n", (void*) myCarSpeedPointer);
    //this only creates a new struct, all the other values are copied as is including pointers
    struct car carCopy = myCar;
    printf("Car struct pointer:  %p\n", (void*) &carCopy);
    printf("Name pointer:  %p\n", carCopy.name);
    printf("Price pointer: %p\n", (void*) &carCopy.price);
    printf("Speed pointer: %p\n", (void*) &carCopy.speed);
    //for comparing structs the best way to do it is comparing field by field
    if (myCar.price == carCopy.price && myCar.speed == carCopy.speed && myCar.price == carCopy.price) {
        printf("Cars are the same\n");
    }else {
        printf("Cars are different\n");
    }
}

void print_car_specs(struct car *carToPrint) {
    printf("Name:  %s\n", carToPrint->name);
    printf("Price: %f\n", carToPrint->price);
    printf("Speed: %d\n", carToPrint->speed);
}

void set_price(struct car *carToUpdate, float newPrice) {
    (*carToUpdate).price = newPrice;
}

void NineFileInputOutput(void) {
    //FILE* name 	Description
    //stdin 	        Standard Input, generally the keyboard by default
    //stdout 	    Standard Output, generally the screen by default
    //stderr 	    Standard Error, generally the screen by default, as well
    //these two calls are the same
    printf("Hello, world!\n");
    fprintf(stdout, "Hello, world!\n");
    print_continues();
    FILE *fp;
    fp = fopen("hello.txt", "r");
    int c = fgetc(fp);
    printf("%d\n", c);
    printf("%c\n", c);
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);
    print_continues();
    char s[1024];
    int lineCount = 0;
    fp = fopen("quote.txt", "r");
    while (fgets(s, 1024, fp) != NULL) {
        printf("%d: %s", ++lineCount, s);
    }
    fclose(fp);
    printf("\n");
    print_continues();
    char name[1024];
    float length;
    int mass;
    fp = fopen("whales.txt", "r");
    //stdout is alos a *FILE, so you can easily switch between where your output is going
    //fp = stdout;
    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF) {
        printf("%s whaled, %d tones, %.1f meters\n", name, mass, length);
    }
    fclose(fp);
    print_continues();
    printf("Code ran creates output.txt file\n");
    int x = 32;
    fp = fopen("output.txt", "w");
    fputc('B', fp);
    fputc('\n', fp);
    fprintf(fp, "x = %d\n", x);
    fputs("Hello world!\n", fp);
    fclose(fp);
    print_continues();
    unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};
    fp = fopen("outputBinary.bin", "wb");
    // In the call to fwrite, the arguments are:
    // * Pointer to data to write
    // * Size of each "piece" of data
    // * Count of each "piece" of data
    // * FILE*
    fwrite(bytes, sizeof(char), 6, fp);
    fclose(fp);
    fp = fopen("outputBinary.bin", "rb");
    unsigned char cr;
    while (fread(&cr, sizeof(char), 1, fp) > 0) {
        printf("%d\n", cr);
    }
    fp = fopen("outputBinaryShort.bin", "wb");
    unsigned short v = 0x1234;
    printf("%d\n", v);
    //This is the output of the line bellow when trying to see the hex of it. Because my machine is little endian that means it stores the least significant bytes in memory first.
    //This is why data should be serialized to a format and not just stored as binary output because it is not portable
    //hexdump -C outputBinaryShort.bin
    //00000000  34 12                                             |4.|
    fwrite(&v, sizeof v, 1, fp);
    fclose(fp);
}