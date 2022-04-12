#include <stdio.h>

float plu(float a, float b) {
	return ("%d", a + b);
}
float min(float a, float b) {
	return("%d", a - b);
}
float mul(float a, float b) {
	return("%f", a * b);
}
float div(float a, float b) {
	return("%f", a / b);
}
float rem(int a, int b) {
	return("%d", a % b);
}


int main()
{
	int ch;
	float num1=0., num2 = 0.;
	float num = 0.;
	int count = 0;
	int calcount = 0;
	int minus_count= 0;
	while ((ch = getchar()) != EOF)
	{
		
		if (ch >= '0' && ch <= '9') {
			if (minus_count == 0) {
				num = num * 10 + ch - '0';                         //num�� ����� �� num�� �ѱ��ھ� ��
			}
			else {
				num = num + 0.1 * ((double)ch - '0');             //num�� ������ �� �Ҽ��� ���ķ� num�� ��
			}
		}
		else if (ch == ' ' || ch == '\n') {                       //getchar()�� ���� ���� or \n�� �Էµ� ��
			if (count == 0) {                                    //ù ������� �������� num1�� ����
				num1 = num;
				num = 0;
				count++;
			}
			else {
				num2 = num;                                      //count�� 0�� �ƴѰ�� �������� num2�� ����
				
			}
			minus_count = 0;
			
			if (ch == '\n') {
				switch (calcount) {
				case 1:
					printf("%f\n", plu(num1, num2));
					break;
				case 2:
					printf("%f\n", min(num1, num2));
					break;
				case 3:
					printf("%f\n", mul(num1, num2));
					break;
				case 4:
					printf("%f\n", div(num1, num2));
					break;
				case 5:
					printf("%f\n", rem(num1, num2));
					break;
				}


				num = 0, num1 = 0, num2 = 0, count = 0, calcount = 0; //�ʱ�ȭ
			}
			
		}
		
		else {
			switch (ch) {
			case '+':
				calcount = 1;
				break;
			case '-':
				calcount = 2;
				break;
			case '*':
				calcount = 3;
				break;
			case '/':
				calcount = 4;
				break;
			case '%':
				calcount = 5;
				break;
			}
		}

		if (ch == '.') {
			minus_count = 1;                                        //�Ҽ����� ������ �� ���� ������ �Ҽ��� ���� ���� �غ�
		}
		

	}
	
	return 0;
	
	
}