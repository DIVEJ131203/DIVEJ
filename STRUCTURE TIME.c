#include <stdio.h>


struct Time {
    int hour;
    int min;
    int sec;
};


struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;
    result.sec %= 60;
    return result;
}

struct Time diffTime(struct Time t1, struct Time t2) {
    struct Time result;
    result.sec = t1.sec - t2.sec;
    result.min = t1.min - t2.min;
    result.hour = t1.hour - t2.hour;


    if (result.sec < 0) {
        result.sec += 60;
        result.min--;
    }
    if (result.min < 0) {
        result.min += 60;
        result.hour--;
    }

    return result;
}

void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}


struct Time readTime() {
    struct Time t;
    printf("Enter time (hh:mm:ss): ");
    scanf("%d:%d:%d", &t.hour, &t.min, &t.sec);
    return t;
}

int main() {
    struct Time time1, time2, sum, difference;

    printf("Enter Time 1:\n");
    time1 = readTime();

    printf("Enter Time 2:\n");
    time2 = readTime();

    sum = addTime(time1, time2);
    printf("Sum of times:\n");
    displayTime(sum);

    difference = diffTime(time1, time2);
    printf("Difference between times:\n");
    displayTime(difference);

    return 0;
}
