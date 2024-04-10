#include <stdio.h>
#include <cstdlib>

#define debug 1

int main()
{
  int n=0,temp,sum;
  printf("Nhap n: ");
  scanf("%d",&n);

  FILE *file;

  // Mở file "data.txt" để ghi
  file = fopen("data.mt", "w");

  // Kiểm tra lỗi mở file
  if (file == NULL) {
    printf("Lỗi mở file!");
    return 1;
  }

  // Ghi dữ liệu vào file
  fprintf(file,"%d %d\n",n,n+1);
  for(int i=1;i<=n;i++)
  {
    sum=0;
    for(int j=1;j<=n;j++)
    {
      temp = rand() % (100 + 100 + 1) - 100;
      sum+=(temp*j);

      if(debug) printf("%d:%d\ttemp=%d; sum=%d\n",i,j,temp,sum);

      fprintf(file,"%d ",temp);
    }
    fprintf(file,"%d",sum);
    if(i<n) fprintf(file,"\n");
  }

  // Đóng file
  fclose(file);

  return 0;
}
