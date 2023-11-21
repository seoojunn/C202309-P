#include <stdio.h>
#include <time.h>

//입력한 시간만큼 대기하는 함수블록
void delay(int seconds) {
    clock_t start_time = clock(); //현재 시간
    clock_t wait_time = seconds * CLOCKS_PER_SEC; //대기할 시간 계산

    while (clock() < start_time + wait_time); // 대기하기
}

int main() {
    int hour, minute;

    printf("몇 시간 후에 알람을 울릴까요? (24시간 형식)\n");
    printf("시간: ");
    scanf_s("%d", &hour);

    printf("분: ");
    scanf_s("%d", &minute);

    printf("알람이 설정되었습니다. %d:%d 후에 울립니다.\n", hour, minute);

    // 시간 변환 후 대기
    delay(hour * 3600 + minute * 60);

    printf("일어나세요!\n");

    return 0;
}