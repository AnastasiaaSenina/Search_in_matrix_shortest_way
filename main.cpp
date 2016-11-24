
#include "stdio.h"
#include <queue>
#include "locale.h"
struct position{
  int strokn;
  int stolbm;
};

int SearchInMatrixShortestWay(int matrix[][5], int n, int m){
  int **visited = new int*[n];
  for (int i = 0; i < n; ++i)
  {
    visited[i] = new int[m];
    for (int j = 0; j<m; ++j)
      visited[i][j] = 0;
  }
  std::queue<position> q;
  position start;
  position finish;
  start.strokn = n - 1;
  start.stolbm = 0;
  finish.strokn = 0;
  finish.stolbm = m - 1;
  q.push(start);
  while (!q.empty()) {
    position x = q.front();// текущий элемент в обходе
    if (x.stolbm == finish.stolbm && x.strokn == finish.strokn)
      return visited[finish.strokn][finish.stolbm] - 1;
    q.pop();
    //проверка снизу и сверху
    if (x.strokn + 1 < n && visited[x.strokn + 1][x.stolbm] == 0 && matrix[x.strokn + 1][x.stolbm] != 0){
      position related;
      related.strokn = x.strokn + 1;
      related.stolbm = x.stolbm;
      q.push(related);
      visited[x.strokn + 1][x.stolbm] = visited[x.strokn][x.stolbm] + 1;
    }
    if (x.strokn - 1 >= 0 && visited[x.strokn - 1][x.stolbm] == 0 && matrix[x.strokn - 1][x.stolbm] != 0){
      position related;
      related.strokn = x.strokn - 1;
      related.stolbm = x.stolbm;
      q.push(related);
      visited[x.strokn - 1][x.stolbm] = visited[x.strokn][x.stolbm] + 1;
    }
    //проверка слева и справа
    if (x.stolbm - 1 >= 0 && visited[x.strokn][x.stolbm - 1] == 0 && matrix[x.strokn][x.stolbm - 1] != 0){
      position related;
      related.strokn = x.strokn;
      related.stolbm = x.stolbm - 1;
      q.push(related);
      visited[x.strokn][x.stolbm - 1] = visited[x.strokn][x.stolbm] + 1;
    }
    if (x.stolbm + 1 < m && visited[x.strokn][x.stolbm + 1] == 0 && matrix[x.strokn][x.stolbm + 1] != 0){
      position related;
      related.strokn = x.strokn;
      related.stolbm = x.stolbm + 1;
      q.push(related);
      visited[x.strokn][x.stolbm + 1] = visited[x.strokn][x.stolbm] + 1;
    }

  }
  return 0;
};



int main(){
  setlocale(LC_ALL, "Rus");
  const int n = 3;
  const int  m = 5;
  int res;
  int matrix[n][m] = { { 1, 1, 1, 1, 'Y' },
  { 1, 0, 0, 1, 1, },
  { 'X', 1, 0, 1, 0 }
  };
  res = SearchInMatrixShortestWay(matrix, n, m);
  if (res)
    printf("Искомый путь между X и Y =  %d\n", res);
  else printf("Искомого пути не существует\n");

  int matrix1[n][m] = { { 0, 1, 1, 1, 'Y' },
  { 0, 0, 0, 1, 1, },
  { 'X', 1, 0, 1, 0 }
  };
  res = SearchInMatrixShortestWay(matrix1, n, m);
  if (res)
    printf("Искомый путь между X и Y =  %d\n", res);
  else printf("Искомого пути не существует\n");
}