#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define IDLENGTH 32
#define STUDENTLEN 30

//ѧ���ɼ��ṹ�嶨��
typedef struct _Grade {
	char studentID[IDLENGTH];
	float computer;
	float sensor;
}Grade,*StudentGrade;

//���ķ���
void alterScore(StudentGrade scores, int length) {
	char studentID[IDLENGTH];
	int a;
	float score;
	char c;
	while ((c = getchar()) != '\n');
	printf("��������Ҫ�޸ķ�����ѧ�ţ�");
	scanf_s(studentID);
	while ((c = getchar()) != '\n');
	printf("��������Ҫ�޸ĵĿ�Ŀ[0����������1��������]��");
	scanf_s("%d", &a);
	while ((c = getchar()) != '\n');
	printf("�������޸ĺ�ķ�����");
	scanf_s("%f", &score);
	for (int i = 0; i < length; i++) {
		if (strcmp(studentID, scores[i].studentID)) {
			if (a == 0) {
				scores[i].computer = score;
			}
			else if (a == 1) {
				scores[i].sensor = score;
			}
			else {
				printf("��������ȷ�Ŀ�Ŀ���!!!\n");
			}
			return;
		}
	}
	printf("��ѧ�Ų����ڣ�������������ȷ��ѧ�ţ�����");
}

//����ѧ���ɼ�ƽ��������ʾ
void allScoreAVE(StudentGrade scores, int length, float* ave) {
	for (int i = 0; i < length; i++) {
		ave[i] = (scores[i].computer + scores[i].sensor) / 2;
		printf("ѧ�ţ�%s \t\t ƽ�������� %.2f\n", scores[i].studentID, ave[i]);
	}
}

//����ѧ���ɼ�ƽ���ɼ���ʾ
void rating(StudentGrade scores, float* ave, int length) {
	int choose;
	for (int i = 0; i < length; i++) {
		choose = (int)(ave[i] / 10);
		switch (choose) {
		case 0:case 1:case 2:case 3: case 4 :case 5:
			printf("ѧ�ţ�%s \t\t ƽ���ɼ���������\n", scores[i].studentID); break;
		case 6:
			printf("ѧ�ţ�%s \t\t ƽ���ɼ�������\n", scores[i].studentID); break;
		case 7:
			printf("ѧ�ţ�%s \t\t ƽ���ɼ�����\n", scores[i].studentID); break;
		case 8:
			printf("ѧ�ţ�%s \t\t ƽ���ɼ�����\n", scores[i].studentID); break;
		case 9:case 10:
			printf("ѧ�ţ�%s \t\t ƽ���ɼ�����\n", scores[i].studentID); break;
		default:
			printf("������0-100�ķ���������\n");
			break;
		}
		
	}
}

int main(void) {
	StudentGrade grades = new Grade[STUDENTLEN];
	float* ave = new float[STUDENTLEN];
	printf("���������30Ϊѧ����ѧ�������ſγɼ���Ϣ��\n");
	printf("ѧ�� \t\t ������ɼ� \t\t �������ɼ������˸�ʽ���롿\n");
	for (int i = 0; i < STUDENTLEN; i++) {
		scanf_s("%s %f %f", grades[i].studentID, sizeof(grades[i].studentID),&grades[i].computer, &grades[i].sensor);
	}

	alterScore(grades, STUDENTLEN);
	allScoreAVE(grades, STUDENTLEN, ave);
	rating(grades, ave, STUDENTLEN);

	system("pause");
	return 0;
}