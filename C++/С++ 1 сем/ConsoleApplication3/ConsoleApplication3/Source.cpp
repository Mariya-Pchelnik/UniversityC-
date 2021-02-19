#include<stdio.h>
#include<string.h>
#define SECURE_NO_WARNINGS

void main() {
	int t;
	FILE** fp = fopen_s(&fp, "NameA", "r");
	while ((t = getc(fp)) != EOF)
	{
		putchar(t);
	}
	fclose(fp);
}