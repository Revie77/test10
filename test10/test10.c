#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/**
* ͨ�õ�ð�������㷨�����õ��˻ص�����������
*/
struct Stu {
	int age;
	int name[20];
};
void swap(char* buf1, char* buf2, int width) {
	int i = 0;
	//����ʹ��ѭ������Ϊcharָ��ֻ��ָ��һ���ֽڵ�Ԫ�أ���������Ԫ����ռ�ֽ�>1,��Ҫ�ֶԽ��н���
	for (i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}
int count = 0;
int cmp_short(const void* e1, const void* e2) {
return *(short*)e1 - *(short*)e2;
}
int cmp_int(const void* e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;
}
//float���ͺ�double���Ͳ���������ͨ��ð��������Ϊ������ǵ�ַ���������͵����ݴ洢ģʽ�����͵����ݴ洢ģʽ�в��죬����ʹ�õ�ַ+-�����һԪ�صĵ�ַ
int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
	{
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2)
	{
		return 1;
	}
	else
	{
		return -1;
	}

}
//ð�����򣬽�������ĵ�ַ�����ȣ���ȣ��Լ��������͵ĺ���ָ��
int bubbling_sort(void* base, int length, int width, int (*cmp)(const void* e1, const  void* e2))
{
	int i = 0, j = 0;
	//��Ҫѭ���ȽϵĴ���
	for (i = 0; i < length; i++)
	{
		j = 0;
		//ÿ�αȽϵĴ���
		for (j = 0; j < length - 1 - i; j++)
		{
			//�����Զ���ıȽϺ����Ƚ���������Ԫ�صĴ�С������charָ��+�������Ϳ�ȵ��ֽڴﵽָ����������һ��Ԫ�ص�Ŀ�ģ�char����ָ��+1����ַ�ֽ�ֻ��+1��������Ҫ*��ȣ�void*ָ���޷����мӼ���
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				//ǰһ��Ԫ��ֵ�Ⱥ�һ��ֵ������н��������봫��Ԫ�ؿ�ȣ���Ϊ����Ҳ�ǽ���ַǿ����char����ָ�����
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
	for (i = 0; i < length; i++)
	{
		printf("%f\n", (float) (*((char*)base + i * width)) );
	}
	return 0;
}
void test1() {
	//�����˳���Ϊ9��double��������arr
	short arr[9] = { 6,5,2,3,1,8,7,9,4 };
	//float arr[7] = { 7.0f, 4.0f, 0.0f, 5.0f, 1.0f, 3.5f, 2.9f };
	//��������鳤��
	int length = sizeof(arr) / sizeof(arr[0]);
	//�����һ��Ԫ����ռ�ֽڳ���
	int width = sizeof(arr[0]);
	bubbling_sort(arr, length, width, cmp_short);
}
int main() {
	test1();
}