#include <random>
#include <list>
#include <iostream>

int main(int, char**) {
  std::random_device seeder; // (May) use hardware to create seed value

  std::mt19937 engine(seeder()); //Mersenne Twister, with seed from seeder

  std::normal_distribution<> gauss(1.23, 2.5); // Normal distribution
                                               // mu=1, sigma=2.5

  std::list<double> data;
  std::generate_n(std::back_inserter(data),
                  1000000,
                  [&gauss, &engine](){return gauss(engine);});

  double mu {std::accumulate(data.begin(), data.end(), 0.0)/data.size()};
  std::cout << "Mean : " << mu << "\n";
  return 0;
}
