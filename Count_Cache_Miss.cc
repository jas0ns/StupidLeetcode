#include <iostream>
#include <queue>

using namespace std;

int countCacheMiss(int max_cache_size, int *page_requests, int len) {
  queue<int> q; 
  queue<int> tq;
  int miss = 0;
  int li = 0;
  bool bingo = false;
  for (int i=0; i < len; ++i) {
    tq = q;
    bingo = false;
    while (tq.size() != 0) {
      if (page_requests[i] == tq.front()) {
        bingo = true;
        break;
      }
      tq.pop();
    }
    if (bingo) continue;
    if (q.size() == max_cache_size) {
      q.pop();
      q.push(page_requests[i]);
    } else {
      q.push(page_requests[i]);
    }
    ++miss;
  }
  return miss;
}

int main(int argc, char **argv) {
  int a[6] = {1,2,1,3,1,2};
  int miss = countCacheMiss(2, a, 6); 
  cout << miss << endl;

  return 1;
}

