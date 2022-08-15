#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/**
* 通用的冒泡排序算法，运用到了回调函数的作用
*/
struct Stu {
	int age;
	int name[20];
};
void swap(char* buf1, char* buf2, int width) {
	int i = 0;
	//这里使用循环是因为char指针只能指向一个字节的元素，如果传入的元素所占字节>1,需要分对进行交换
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
//float类型和double类型不适用这种通用冒泡排序，因为传入的是地址，而浮点型的数据存储模式与整型的数据存储模式有差异，不能使用地址+-获得下一元素的地址
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
//冒泡排序，接收数组的地址，长度，宽度，以及各个类型的函数指针
int bubbling_sort(void* base, int length, int width, int (*cmp)(const void* e1, const  void* e2))
{
	int i = 0, j = 0;
	//需要循环比较的次数
	for (i = 0; i < length; i++)
	{
		j = 0;
		//每次比较的次数
		for (j = 0; j < length - 1 - i; j++)
		{
			//调用自定义的比较函数比较相邻两个元素的大小，利用char指针+传入类型宽度的字节达到指向数组中下一个元素的目的（char类型指针+1，地址字节只能+1，所以需要*宽度；void*指针无法进行加减）
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				//前一个元素值比后一个值大则进行交换，必须传入元素宽度，因为这里也是将地址强制用char类型指针接收
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
	//定义了长度为9的double类型数组arr
	short arr[9] = { 6,5,2,3,1,8,7,9,4 };
	//float arr[7] = { 7.0f, 4.0f, 0.0f, 5.0f, 1.0f, 3.5f, 2.9f };
	//计算出数组长度
	int length = sizeof(arr) / sizeof(arr[0]);
	//计算出一个元素所占字节长度
	int width = sizeof(arr[0]);
	bubbling_sort(arr, length, width, cmp_short);
}
int main() {
	test1();
}