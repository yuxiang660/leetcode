#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>

using namespace std;

char character = 'A';
mutex mtx;

void printCharacter() {
   mtx.lock();
   cout << character << endl;
   character += 1;
   mtx.unlock();
}

int main() {
   cout << "Multi-Thread Test" << endl;

   /*vector<thread> threads;
   for (int i = 0; i < 26; i++) {
      threads.push_back(thread(printCharacter));
   }

   for (auto& thread : threads) {
      thread.join();
   }*/

   vector<future<void>> futs;
   for (int i = 0; i < 26; i++) {
      futs.push_back(async(printCharacter));
   }

   for (auto& fut : futs) {
      fut.get();
   }

   return 0;
}
