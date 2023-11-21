#include <stdio.h>
#include <time.h>

//�Է��� �ð���ŭ ����ϴ� �Լ����
void delay(int seconds) {
    clock_t start_time = clock(); //���� �ð�
    clock_t wait_time = seconds * CLOCKS_PER_SEC; //����� �ð� ���

    while (clock() < start_time + wait_time); // ����ϱ�
}

int main() {
    int hour, minute;

    printf("�� �ð� �Ŀ� �˶��� �︱���? (24�ð� ����)\n");
    printf("�ð�: ");
    scanf_s("%d", &hour);

    printf("��: ");
    scanf_s("%d", &minute);

    printf("�˶��� �����Ǿ����ϴ�. %d:%d �Ŀ� �︳�ϴ�.\n", hour, minute);

    // �ð� ��ȯ �� ���
    delay(hour * 3600 + minute * 60);

    printf("�Ͼ����!\n");

    return 0;
}