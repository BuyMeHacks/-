#include <stdio.h>
int table[9][9], ans=0;

bool check_x(int x, int y, int value) //檢查橫的有無重複 
{
    for (int i=0; i<9; i++)
       {
        if (y == i) continue;
        if (value == table[x][i]) return 1; //有重複 
       }
    return 0;
}

bool check_y(int x, int y, int value) //檢查直的有無重複 
{
    for (int i=0; i<9; i++)
       {
        if (x == i) continue;
        if (value == table[i][y]) return 1; //有重複 
       }
    return 0;
}

bool check_square(int x, int y, int value) //檢查在小九宮格內有無重複 
{
	for (int i=0; i<9; i++)
	   {
		int gridx = (x / 3) * 3;
		int gridy = (y / 3) * 3;
		if (value == table[gridx + i / 3][gridy + i % 3]) return 1;
	   }
	return 0;	
}
      
void DFS(int pos)
{ int x,y;
  x=pos/9;
  y=pos%9;  
      
  if (pos == 81){
      ans++;
      printf("\n");
      for (int i=0; i<9; i++){
        for (int j=0; j<9; j++)printf("%d ",table[i][j]);
        printf("\n");
      }
      printf("\n");
      return;
  }
    
 if(!table[x][y]){ 
    for (int i=1; i<=9; i++)
    {
        if ( check_x(x, y, i) ) continue;
        if ( check_y(x, y, i) ) continue;
        if ( check_square(x, y, i) ) continue;
        table[ x ][ y ] = i;
        DFS(pos + 1);    
    }
    table[ x ][ y ] = 0;return;
 }
 else{
  DFS(pos + 1);return;
 }   
}

int main()
{
    freopen("sudo.txt","r",stdin);
    freopen("sudoout-notyet.txt","w",stdout);
    printf("Hi I am 21124!!!\a\n\n");    
        ans = 0;
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                scanf("%d",&table[i][j]);
				   
        DFS( 0 );
        printf("there are  %d solution(s).\n",ans);
    
    return 0;
}
