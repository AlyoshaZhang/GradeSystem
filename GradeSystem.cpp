#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define IDLENGTH 32
#define STUDENTLEN 30

//学生成绩结构体定义
typedef struct _Grade {
	char studentID[IDLENGTH];
	float computer;
	float sensor;
}Grade,*StudentGrade;

//更改分数
void alterScore(StudentGrade scores, int length) {
	char studentID[IDLENGTH];
	int a;
	float score;
	char c;
	while ((c = getchar()) != '\n');
	printf("请输入需要修改分数的学号：");
	scanf_s(studentID);
	while ((c = getchar()) != '\n');
	printf("请输入需要修改的科目[0代表计算机，1代表传感器]：");
	scanf_s("%d", &a);
	while ((c = getchar()) != '\n');
	printf("请输入修改后的分数：");
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
				printf("请输入正确的科目编号!!!\n");
			}
			return;
		}
	}
	printf("该学号不存在！！！请输入正确的学号！！！");
}

//所有学生成绩平均分数显示
void allScoreAVE(StudentGrade scores, int length, float* ave) {
	for (int i = 0; i < length; i++) {
		ave[i] = (scores[i].computer + scores[i].sensor) / 2;
		printf("学号：%s \t\t 平均分数： %.2f\n", scores[i].studentID, ave[i]);
	}
}

//所有学生成绩平均成绩显示
void rating(StudentGrade scores, float* ave, int length) {
	int choose;
	for (int i = 0; i < length; i++) {
		choose = (int)(ave[i] / 10);
		switch (choose) {
		case 0:case 1:case 2:case 3: case 4 :case 5:
			printf("学号：%s \t\t 平均成绩：不及格\n", scores[i].studentID); break;
		case 6:
			printf("学号：%s \t\t 平均成绩：及格\n", scores[i].studentID); break;
		case 7:
			printf("学号：%s \t\t 平均成绩：中\n", scores[i].studentID); break;
		case 8:
			printf("学号：%s \t\t 平均成绩：优\n", scores[i].studentID); break;
		case 9:case 10:
			printf("学号：%s \t\t 平均成绩：良\n", scores[i].studentID); break;
		default:
			printf("请输入0-100的分数！！！\n");
			break;
		}
		
	}
}

int main(void) {
	StudentGrade grades = new Grade[STUDENTLEN];
	float* ave = new float[STUDENTLEN];
	printf("请逐个输入30为学生的学号与两门课成绩信息：\n");
	printf("学号 \t\t 计算机成绩 \t\t 传感器成绩【按此格式输入】\n");
	for (int i = 0; i < STUDENTLEN; i++) {
		scanf_s("%s %f %f", grades[i].studentID, sizeof(grades[i].studentID),&grades[i].computer, &grades[i].sensor);
	}

	alterScore(grades, STUDENTLEN);
	allScoreAVE(grades, STUDENTLEN, ave);
	rating(grades, ave, STUDENTLEN);

	system("pause");
	return 0;
}