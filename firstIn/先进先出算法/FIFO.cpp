#include<iostream>
using namespace std;
void display(int a[], int PageNum)
{
	for (int i = 0; i<PageNum; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}
void run(int a[], int PageNum, int BlockSno)
{
	int *p;
	int count = 0;
	p = new int[BlockSno];
	for (int i = 0; i<BlockSno; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			p[j] = a[j];
			cout << p[j] << "  ";
		}
		cout << endl;

	}
	int mm = 0;
	int mnm = 0;
	for (int i = 3; i < PageNum; i++)
	{
	
		for (int j = 0; j < BlockSno; j++) {
			int cour = 0;
			if (p[j] == a[i]) {
				mm++;
				cour++;
				mnm = cour;
			}

			
		}
		if (mnm >0) {
			//cout << "已存在！" << endl;
			for (int m = 0; m < BlockSno; m++) {
				cout << p[m] << "  ";
			}
			/*for (int m = 0; m < BlockSno; m++) {
				p[(i - m) % BlockSno] = a[i];
				cout << p[m] << " ";
			}*/
		}
		else if(mnm==0){
			for (int m = 0; m < BlockSno; m++) {
				p[(i-mm) % BlockSno] = a[i];
				cout << p[m] << "  ";
			}
		}
		mnm = 0;
		cout << endl;
	}
	cout <<"命中的个数："<< mm << endl;
	cout << "缺页率为：%" << (PageNum - mm) / (PageNum / 1.00) * 100 << endl;
}
bool check(int a[], int b,int BlockSno)
{
	int cour = 0;
	for (int i = 0; i < BlockSno; i++) {
		if (a[i] == b) {
			cour++;
		}
	}
	if (cour > 0) {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	int BlockSno;
	int PageSno;
	int *Page;
	int PageNum;
	cout << "请输入你的作业号数目：";
	cin >> PageNum;
	cout << endl;
	Page = new int[PageNum];
	cout << "请输入各个作业：" << endl;
	for (int i = 0; i<PageNum; i++)
	{
		cin >> PageSno;
		Page[i] = PageSno;
	}
	display(Page, PageNum);
	cout << "请输入你所需要的块号数目：";
	cin >> BlockSno;
	run(Page, PageNum, BlockSno);
	return 0;
}
