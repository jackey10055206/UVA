#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int m;
vector<int> A, B, C;

void print_hanoi(){
  printf( "A=> " );
  if( A.size() ){
    printf( " " );
    for( int i = 0 ; i < A.size() ; i++ )
      printf( " %d", A[i] );
  }
  printf( "\n" );

  printf( "B=>" );
  if( B.size() ){
    printf( " " );
    for( int i = 0 ; i < B.size() ; i++ )
      printf( " %d", B[i] );
  }
  printf( "\n" );

  printf( "C=>" );
  if( C.size() ){
    printf( " " );
    for( int i = 0 ; i < C.size() ; i++ )
      printf( " %d", C[i] );
  }
  printf( "\n" );
  printf( "\n" );
}

void hanoi( int n, vector<int> &start, vector<int> &temp, vector<int> &finish ){
  if( m <= 0 ) return;
  if( n == 1 ){
    finish.push_back( start.back() );
    start.pop_back();
    print_hanoi();
    m--;
    return;
  }
  hanoi( n-1, start, finish, temp );
  if( m <= 0 ) return;

  finish.push_back(start.back());
  start.pop_back();
  print_hanoi();
  m--;
  if( m <= 0 ) return;

  hanoi( n-1, temp, start, finish );
}

int main(){
  int n;
  int problem = 1;
  #ifdef DBG
  freopen("10017.in","r",stdin);
  freopen("10017.out","w",stdout);
  #endif

  while( scanf( "%d%d", &n, &m ) != EOF && !(n == 0 && m == 0) ){
    printf( "Problem #%d\n\n", problem++ );
    A.clear();
    B.clear();
    C.clear();

    for( int i = n ; i >= 1 ; i-- )
      A.push_back(i);

    print_hanoi();
    hanoi( n, A, B, C );
  }
  return 0;
}