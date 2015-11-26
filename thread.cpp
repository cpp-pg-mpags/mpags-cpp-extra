#include <chrono>
#include <future>
#include <iostream>


int getUltimateAnswer(const std::chrono::microseconds& waitFor) {
  std::cout << "[getUltimateAnswer] starting to think...\n";
  std::this_thread::sleep_for(waitFor/2);
  std::cout << "[getUltimateAnswer] still thinking...\n";
  std::this_thread::sleep_for(waitFor/2);
  std::cout << "[getUltimateAnswer] got the answer...\n";
  return 42;
}


int main(int, char**) {
  std::chrono::microseconds thinkFor {7500000};
  auto ua = std::async(getUltimateAnswer, thinkFor);

  std::cout << "[main] Now we wait...\n";
  std::future_status status;
  do {
    // wait 1ms, get status of future
    status = ua.wait_for(std::chrono::seconds(1));

    if (status == std::future_status::timeout) {
      std::cout << "[main] waiting...\n";
    } else if (status == std::future_status::ready) {
      std::cout << "[main] finally, an answer!\n";
    }
  } while (status != std::future_status::ready);

  std::cout << "Ultimate Answer is: " << ua.get() <<"\n";
  return 0;
}
