#include<stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <windows.h>
#define debug 1

char ten[100][100];
int soten=0;

void reset()
{
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			ten[i][j]='0';
}

void lay_ten_file_exe()
{
	DIR *dir;
	struct dirent *entry;

	// Mở thư mục hiện tại
	dir = opendir(".");
	
	// Duyệt qua các tệp trong thư mục
	int i=0;
	while ((entry = readdir(dir)) != NULL)
	{
	// Kiểm tra xem tệp có phải là tệp .exe hay không
		if (strstr(entry->d_name, ".exe")!=NULL&&strstr(entry->d_name,"Intall app.exe")==NULL)
		{
			int j;
			for (j=0;j<100;j++)
			{
				ten[i][j]=entry->d_name[j];
			}
			ten[i][j]='\0';
			
			// In tên của tệp
			if(debug)
			{
				j=0;
				do
				{
					printf("%c",ten[i][j]);
					j++;
				} while(ten[i][j]!='\0');
				printf("\n");
			}
		}
		i++;
	}
	
	// Đóng thư mục
	closedir(dir);
}

void intall(char ten)
{
	
}

int main()
{
	reset();
	lay_ten_file_exe();
}