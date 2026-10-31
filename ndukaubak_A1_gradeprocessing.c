#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#pragma warning(disable: 4996)

struct student {
	char student_name[150];
	int student_id; 
	int grade_one;
	int grade_two;
	int grade_three;
	float average_grade;
};

float average(int grade_1, int grade_2, int grade_3) {
	return (grade_1 + grade_2 + grade_3) / 3.0f;
}

int read_file(struct student students[], int max_students, const char *filename) { 

	FILE *fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "The file can't be open: %s\n", filename);
		return 1; 
	}
	else {
		printf("Success: File Read\n");
	}

	int count = 0; 

	while (count < max_students && 
		fscanf(fp, "%149s %d %d %d %d\n", students[count].student_name, &students[count].student_id, &students[count].grade_one,
			&students[count].grade_two, &students[count].grade_three) == 5) {

			students[count].average_grade = average(
			students[count].grade_one,
			students[count].grade_two,
			students[count].grade_three
		);

		count++;
	}
	fclose(fp);
	return count;
}

int write_file(struct student students[], int count, const char *filename) {

	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "The file can't be open: %s\n", filename);
		return 1;
	}
	else {
		printf("Success: Written Contents to File\n"); 
	}

	for (int i = 0; i < count; i++) {
		fprintf(fp, "Name: %s, ID: %d, Grades: [%d, %d, %d], Average: %.2f\n",

			students[i].student_name, 
			students[i].student_id,
			students[i].grade_one, 
			students[i].grade_two,
			students[i].grade_three, 
			students[i].average_grade);
	}
	fclose(fp);
	return 0;
}

int main () {

	int max_students = 150;
	struct student students[150];

	int count = read_file(students, max_students, "student.txt");

	write_file(students, count, "output.txt");

	return 0;
}











