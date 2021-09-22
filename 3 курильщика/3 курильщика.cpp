

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>

enum Stuff {
    undefined=-1,
    matches,
    paper,
    tabaco,
    
};

struct Table {
    Stuff stuff[2];
    bool ready_to_smoke = false; //empty?

    bool ingrident()
       
};

class Smoker {
    Stuff stuff;
    int num_stuff;
    bool is_smoking;
public:
    Smoker(Stuff _stuff) :stuff(_stuff), is_smoking(false) {
    }
    void operator()() {};
    Stuff take() {
        if (num_stuff == 0)
            return undefined;

        num_stuff--;
        return stuff;
    }
};

class Barmen {
    public:
        void operator()() {
            int id[2]; 
            id[0]=id[1]= std::rand() % 3;
            while (id[0] == id[1])
                id[1] = std::rand() % 3;

            table.stuff[0] = smokers[id[0]].take();
            table.stuff[1] = smokers[id[1]].take();

            table.ready_to_smoke = true;
        };
};
Table table;
std::vector<Smoker>smokers{ matches,paper,tabaco };
Barmen barmen;
int main()
{
   
   std::vector<std::thread>sm_threads;

  
   std::thread t1(barmen);
   for (auto& sm : smokers)
       sm_threads.emplace_back(sm);

   t1.join();
}


